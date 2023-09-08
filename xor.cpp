#include <iostream>
#include <vector>

using namespace std;

// Define the step activation function
int step(float x) {
    return x > 0 ? 1 : 0;
}

// Define the neuron function
int neuron(const vector<int>& inputs, const vector<int>& weights) {
    int sum = 0;
    for (size_t i = 0; i < inputs.size(); ++i) {
        sum += inputs[i] * weights[i];
    }
    return step(sum);
}

int main() {
    // Define weights for NAND, OR, and AND gates
    vector<int> NAND = {1, -1, -1};
    vector<int> OR = {-1, 1, 1};
    vector<int> AND = {-1, 1, 1};

    // XOR logic using NAND, OR, and AND gates
    vector<vector<int>> inputs = {
        {0, 0},
        {1, 0},
        {0, 1},
        {1, 1}
    };

    for (const vector<int>& input : inputs) {
        int nand_output = neuron(input, NAND);
        int or_output = neuron(input, OR);
        vector<int> and_inputs = {nand_output, or_output};
        int result = neuron(and_inputs, AND);

        cout << "[" << input[0] << ", " << input[1] << "] = " << result << endl;
    }

    return 0;
}
