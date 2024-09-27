#include <iostream>
using namespace std;

class Robot {
public:
    int x, y;
    Robot() {
        x = y = 0; // Initialize at origin
    }

    // Move the robot based on sensor data
    void move(int sensorInput) {
        switch (sensorInput) {
            case 0:
                cout << "Moving Forward" << endl;
                x += 1; // Move forward in the x direction
                break;
            case 1:
                cout << "Moving Backward" << endl;
                x -= 1; // Move backward in the x direction
                break;
            case 2:
                cout << "Turning Left" << endl;
                y -= 1; // Move left in the y direction
                break;
            case 3:
                cout << "Turning Right" << endl;
                y += 1; // Move right in the y direction
                break;
            case 4:
                cout << "Stopping and resetting position to origin" << endl;
                x = 0; // Resetting only x here, but y should also reset.
                y = 0;
                break;
            default:
                cout << "Invalid sensor input" << endl;
        }
    }

    void printPosition() const {
        cout << "Current Position: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Robot robot;
    int sensorInput;

    // Main loop to keep asking for sensor input until the stop signal
    do {
        cout << "Enter sensor input (0-4): ";
        cin >> sensorInput;

        robot.move(sensorInput);
        robot.printPosition();

    } while (sensorInput != 4);

    return 0;
}
