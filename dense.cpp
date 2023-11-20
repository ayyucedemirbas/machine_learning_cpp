#include <iostream>
#include <vector>


std::vector<double> denseLayer(const std::vector<double>& input, const std::vector<std::vector<double>>& weights, const std::vector<double>& biases) {
    int input_size = input.size();
    int output_size = biases.size();

    std::vector<double> output(output_size, 0.0);

    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < input_size; ++j) {
            output[i] += input[j] * weights[i][j];
        }
        output[i] += biases[i];
    }

    return output;
}

int main() {
    std::vector<double> input = {1, 2, 3};

    std::vector<std::vector<double>> weights = {{0.1, 0.2, 0.3},
                                               {0.4, 0.5, 0.6}};

    std::vector<double> biases = {0.1, 0.2};

    std::vector<double> result = denseLayer(input, weights, biases);

    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
