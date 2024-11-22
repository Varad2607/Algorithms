#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Normalize a probability distribution
void normalize(vector<double>& probabilities) {
    double sum = 0.0;
    for (double p : probabilities) sum += p;
    for (double& p : probabilities) p /= sum;
}

// Motion update (prediction step)
void motionUpdate(vector<double>& beliefs, int move, double move_prob) {
    vector<double> new_beliefs(beliefs.size(), 0.0);
    int n = beliefs.size();

    for (int i = 0; i < n; i++) {
        // Probability of staying in the same cell
        new_beliefs[i] += beliefs[i] * (1.0 - move_prob);

        // Probability of moving to the new cell
        int new_pos = (i + move + n) % n; // Ensure circular world
        new_beliefs[new_pos] += beliefs[i] * move_prob;
    }

    beliefs = new_beliefs;
}

// Measurement update (correction step)
void measurementUpdate(vector<double>& beliefs, const vector<double>& world, int measurement, double correct_prob) {
    for (int i = 0; i < beliefs.size(); i++) {
        if (world[i] == measurement) {
            beliefs[i] *= correct_prob; // Higher probability for correct measurement
        } else {
            beliefs[i] *= (1.0 - correct_prob); // Lower probability for incorrect measurement
        }
    }
    normalize(beliefs);
}

int main() {
    // Define the world and robot's beliefs
    vector<double> world = {1, 0, 1, 0, 1}; // 1 represents a landmark, 0 represents no landmark
    vector<double> beliefs(world.size(), 1.0 / world.size()); // Uniform initial belief
    cout<<"Belief",beliefs;

    // Parameters
    double move_prob = 0.8;      // Probability of successful movement
    double correct_prob = 0.9;   // Probability of correct measurement

    // Simulated robot actions
    vector<int> moves = {1, 1, -1};         // Move right, right, left
    vector<int> measurements = {1, 1, 0};  // Measurements taken after each move

    // Run Bayes filter
    for (size_t t = 0; t < moves.size(); t++) {
        cout << "Step " << t + 1 << ":\n";

        // Motion update
        motionUpdate(beliefs, moves[t], move_prob);
        cout << "Beliefs after motion update: ";
        for (double b : beliefs) cout << b << " ";
        cout << endl;

        // Measurement update
        measurementUpdate(beliefs, world, measurements[t], correct_prob);
        cout << "Beliefs after measurement update: ";
        for (double b : beliefs) cout << b << " ";
        cout << endl << endl;
    }

    return 0;
}

