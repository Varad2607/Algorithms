#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

class Joint {
private:
    double currentAngle;
    double targetAngle;
    double maxSpeed;
    string jointName;

public:
    Joint(const string& name, double maxSpeedDegPerSec = 30.0)
        : currentAngle(0.0), targetAngle(0.0), maxSpeed(maxSpeedDegPerSec), jointName(name) {}

    void setTargetAngle(double angle) {
        // Clamp angle between -180 and 180 degrees
        targetAngle = min(180.0, max(-180.0, angle));
    }

    bool moveTowardsTarget(double deltaTime) {
        const double tolerance = 0.1;
        if (abs(currentAngle - targetAngle) < tolerance) {
            return true;  // Target reached
        }

        double direction = (targetAngle > currentAngle) ? 1.0 : -1.0;
        double movement = maxSpeed * deltaTime;
        currentAngle += direction * min(movement, abs(targetAngle - currentAngle));
        return false;  // Still moving
    }

    double getCurrentAngle() const { return currentAngle; }
    string getName() const { return jointName; }
};

class EndEffector {
private:
    bool isGripping;
    double gripperWidth;

public:
    EndEffector() : isGripping(false), gripperWidth(100.0) {}

    void grip() {
        isGripping = true;
        gripperWidth = 20.0;
        cout << "Gripper activated - Object gripped\n";
    }

    void release() {
        isGripping = false;
        gripperWidth = 100.0;
        cout << "Gripper released\n";
    }

    bool getGripStatus() const { return isGripping; }
    double getGripperWidth() const { return gripperWidth; }
};

class RobotArm {
private:
    vector<unique_ptr<Joint>> joints;
    shared_ptr<EndEffector> endEffector;
    bool isInitialized;

public:
    RobotArm() : isInitialized(false) {
        initialize();
    }

    void initialize() {
        if (!isInitialized) {
            // Initialize joints
            joints.push_back(make_unique<Joint>("Base", 45.0));
            joints.push_back(make_unique<Joint>("Shoulder", 30.0));
            joints.push_back(make_unique<Joint>("Elbow", 60.0));
            joints.push_back(make_unique<Joint>("Wrist", 90.0));

            // Initialize end effector
            endEffector = make_shared<EndEffector>();
            
            isInitialized = true;
            cout << "Robot arm initialized successfully with " << joints.size() << " joints\n";
        }
    }

    void moveToPosition(const vector<double>& targetAngles) {
        if (targetAngles.size() != joints.size()) {
            throw invalid_argument("Error: Invalid number of target angles provided");
        }

        // Set target angles for all joints
        for (size_t i = 0; i < joints.size(); ++i) {
            joints[i]->setTargetAngle(targetAngles[i]);
        }

        // Move joints until all targets are reached
        bool allJointsAtTarget = false;
        while (!allJointsAtTarget) {
            allJointsAtTarget = true;
            
            // Update each joint
            for (auto& joint : joints) {
                if (!joint->moveTowardsTarget(0.1)) {  // 100ms timestep
                    allJointsAtTarget = false;
                }
                cout << joint->getName() << " angle: " 
                     << joint->getCurrentAngle() << " degrees\n";
            }

            // Add a small delay to simulate real-time movement
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << string(50, '-') << endl;
        }
    }

    void grabObject() {
        endEffector->grip();
    }

    void releaseObject() {
        endEffector->release();
    }

    shared_ptr<EndEffector> getEndEffector() {
        return endEffector;
    }

    vector<double> getCurrentPositions() {
        vector<double> positions;
        for (const auto& joint : joints) {
            positions.push_back(joint->getCurrentAngle());
        }
        return positions;
    }
};

class RobotController {
private:
    unique_ptr<RobotArm> robotArm;

public:
    RobotController() : robotArm(make_unique<RobotArm>()) {}

    void executePickAndPlace() {
        try {
            cout << "\nStarting pick and place operation...\n";

            // Move to pickup position
            cout << "\nMoving to pickup position...\n";
            robotArm->moveToPosition({45.0, 30.0, -45.0, 90.0});
            
            // Grab object
            cout << "\nGrabbing object...\n";
            robotArm->grabObject();
            
            // Move to place position
            cout << "\nMoving to place position...\n";
            robotArm->moveToPosition({0.0, 45.0, -30.0, 45.0});
            
            // Release object
            cout << "\nReleasing object...\n";
            robotArm->releaseObject();

            // Return to home position
            cout << "\nReturning to home position...\n";
            robotArm->moveToPosition({0.0, 0.0, 0.0, 0.0});

            cout << "\nPick and place operation completed successfully!\n";

        } catch (const exception& e) {
            cerr << "Error during pick and place operation: " << e.what() << endl;
        }
    }
};

int main() {
    try {
        // Create robot controller
        auto controller = make_unique<RobotController>();
        
        // Execute pick and place operation
        controller->executePickAndPlace();

    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }

    return 0;
}