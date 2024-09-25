#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Sensor {
public:
    virtual double read() = 0;
};

class DistanceSensor : public Sensor {
public:
    double read() override {
        // Simulate reading distance (in meters)
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<> dis(0.1, 5.0);
        return dis(gen);
    }
};

class Robot {
private:
    double x, y, theta;
    std::vector<Sensor*> sensors;

public:
    Robot(double x, double y, double theta) : x(x), y(y), theta(theta) {}

    void addSensor(Sensor* sensor) {
        sensors.push_back(sensor);
    }

    void move(double distance, double angle) {
        x += distance * cos(theta + angle);
        y += distance * sin(theta + angle);
        theta += angle;
    }

    void senseAndAvoid() {
        for (auto sensor : sensors) {
            double distance = sensor->read();
            if (distance < 1.0) {
                // Obstacle detected, turn right
                move(0.5, M_PI / 2);
                return;
            }
        }
        // No obstacle, move forward
        move(1.0, 0);
    }

    void displayStatus() {
        std::cout << "Robot position: (" << x << ", " << y << "), orientation: " << theta << std::endl;
    }
};

class Simulator {
private:
    Robot robot;
    int timesteps;

public:
    Simulator(Robot& r, int t) : robot(r), timesteps(t) {}

    void run() {
        for (int i = 0; i < timesteps; ++i) {
            std::cout << "Timestep " << i << ": ";
            robot.senseAndAvoid();
            robot.displayStatus();
        }
    }
};

int main() {
    Robot robot(0, 0, 0);
    DistanceSensor* sensor = new DistanceSensor();
    robot.addSensor(sensor);

    Simulator sim(robot, 10);
    sim.run();

    delete sensor;
    return 0;
}