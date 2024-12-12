#include <iostream>
#include <memory>
#include <vector>

class ForkliftController {
private:
    std::string model;
    double maxLoadCapacity;
    bool isOperational;

public:
    // Constructor
    ForkliftController(const std::string& modelName, double capacity) 
        : model(modelName), maxLoadCapacity(capacity), isOperational(true) {
        std::cout << "Forklift Controller Created: " << model << std::endl;
    }

    // Method to simulate forklift operation
    void operate() {
        if (isOperational) {
            std::cout << "Forklift " << model << " is operating." << std::endl;
        } else {
            std::cout << "Forklift " << model << " is not operational." << std::endl;
        }
    }

    // Getter methods
    std::string getModel() const { return model; }
    double getMaxLoadCapacity() const { return maxLoadCapacity; }

    // Destructor
    ~ForkliftController() {
        std::cout << "Forklift Controller Destroyed: " << model << std::endl;
    }
};

// Demonstration class for different pointer creation methods
class PointerDemonstrator {
public:
    // Method 1: Raw Pointer Creation
    static ForkliftController* createRawPointer(const std::string& model, double capacity) {
        return new ForkliftController(model, capacity);
    }

    // Method 2: Unique Pointer Creation
    static std::unique_ptr<ForkliftController> createUniquePointer(const std::string& model, double capacity) {
        return std::make_unique<ForkliftController>(model, capacity);
    }

    // Method 3: Shared Pointer Creation
    static std::shared_ptr<ForkliftController> createSharedPointer(const std::string& model, double capacity) {
        return std::make_shared<ForkliftController>(model, capacity);
    }

    // Method to demonstrate pointer management
    static void demonstratePointerUsage() {
        // Raw Pointer (CAUTION: Requires manual memory management)
        {
            std::cout << "\n--- Raw Pointer Demonstration ---" << std::endl;
            ForkliftController* rawPtr = createRawPointer("RawModel", 1000.0);
            rawPtr->operate();
            delete rawPtr; // IMPORTANT: Manual deletion required
        }

        // Unique Pointer (Recommended for single ownership)
        {
            std::cout << "\n--- Unique Pointer Demonstration ---" << std::endl;
            auto uniquePtr = createUniquePointer("UniqueModel", 1500.0);
            uniquePtr->operate();
            // No manual deletion needed - automatically manages memory
        }

        // Shared Pointer (For shared ownership)
        {
            std::cout << "\n--- Shared Pointer Demonstration ---" << std::endl;
            auto sharedPtr1 = createSharedPointer("SharedModel", 2000.0);
            {
                auto sharedPtr2 = sharedPtr1; // Reference count increases
                sharedPtr2->operate();
            } // sharedPtr2 goes out of scope, but object is not deleted
            sharedPtr1->operate();
            // Object deleted when last shared_ptr goes out of scope
        }
    }
};

// Advanced example with pointer collection
class ForkliftFleet {
private:
    std::vector<std::unique_ptr<ForkliftController>> forklifts;

public:
    // Add a forklift to the fleet
    void addForklift(const std::string& model, double capacity) {
        forklifts.push_back(
            std::make_unique<ForkliftController>(model, capacity)
        );
    }

    // Operate all forklifts
    void operateAllForklifts() {
        for (const auto& forklift : forklifts) {
            forklift->operate();
        }
    }

    // Get fleet size
    size_t getFleetSize() const {
        return forklifts.size();
    }
};

int main() {
    // Demonstrate different pointer creation methods
    PointerDemonstrator::demonstratePointerUsage();

    // Demonstrate fleet management
    std::cout << "\n--- Forklift Fleet Demonstration ---" << std::endl;
    ForkliftFleet fleet;

    // int *ptr;
    // ptr=&new

    fleet.addForklift("F1", 1000.0);
    fleet.addForklift("F2", 1500.0);
    fleet.addForklift("F3", 2000.0);

    std::cout << "Fleet Size: " << fleet.getFleetSize() << std::endl;
    fleet.operateAllForklifts();

    return 0;
}