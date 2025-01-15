#include <iostream>
#include <vector>

class KalmanFilter {
private:
    double x;  // State estimate (e.g., position)
    double P;  // Estimate uncertainty (covariance)
    double Q;  // Process noise covariance
    double R;  // Measurement noise covariance
    double K;  // Kalman Gain
    double A;  // State transition matrix
    double B;  // Control input matrix

public:
    KalmanFilter(double initial_x, double initial_P, double process_noise, double measurement_noise, double A_val, double B_val)
        : x(initial_x), P(initial_P), Q(process_noise), R(measurement_noise), K(0), A(A_val), B(B_val) {}

    void predict(double control_input = 0, double dt = 1.0) {
        // Prediction step with control input
        x = A * x + B * control_input * dt;
        P = A * P * A + Q;
    }

    void update(double measurement) {
        // Kalman Gain
        K = P / (P + R);

        // Update state estimate
        x = x + K * (measurement - x);

        // Update covariance
        P = (1 - K) * P;
    }

    double getState() const {
        return x;
    }

    double getUncertainty() const {
        return P;
    }
};

int main() {
    // Initialize Kalman Filter with control input
    double initial_position = 0.0;
    double initial_uncertainty = 1.0;
    double process_noise = 0.1;  // Assumes small process uncertainty
    double measurement_noise = 0.5;  // Assumes moderate sensor noise
    double A_val = 1.0;  // For simplicity, we assume a basic model: A = 1
    double B_val = 1.0;  // Control input matrix

    KalmanFilter kf(initial_position, initial_uncertainty, process_noise, measurement_noise, A_val, B_val);

    // Simulate sensor measurements (noisy data)
    std::vector<double> measurements = {1.0, 2.0, 3.1, 3.8, 5.0};

    // Simulate a control input (optional, can be 0 for simple cases)
    double control_input = 1.0;
    double dt = 1.0;  // Time step

    std::cout << "Time Step\tMeasurement\tEstimate\tUncertainty\n";
    for (size_t i = 0; i < measurements.size(); ++i) {
        kf.predict(control_input, dt);  // Prediction step with control input
        kf.update(measurements[i]);    // Update step

        std::cout << i << "\t\t" << measurements[i] << "\t\t" 
                  << kf.getState() << "\t\t" << kf.getUncertainty() << "\n";
    }

    return 0;
}
