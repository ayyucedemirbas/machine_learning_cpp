#include <iostream>
#include <vector>


std::vector<std::vector<double>> convolution(const std::vector<std::vector<double>>& input, const std::vector<std::vector<double>>& kernel, int padding, int stride) {
    int input_height = input.size();
    int input_width = input[0].size();
    int kernel_height = kernel.size();
    int kernel_width = kernel[0].size();

    int padded_height = input_height + 2 * padding;
    int padded_width = input_width + 2 * padding;

    int output_height = (padded_height - kernel_height) / stride + 1;
    int output_width = (padded_width - kernel_width) / stride + 1;

    std::vector<std::vector<double>> padded_input(padded_height, std::vector<double>(padded_width, 0.0));

    
    for (int i = 0; i < input_height; ++i) {
        for (int j = 0; j < input_width; ++j) {
            padded_input[i + padding][j + padding] = input[i][j];
        }
    }

    std::vector<std::vector<double>> output(output_height, std::vector<double>(output_width, 0.0));

    for (int i = 0; i < output_height; ++i) {
        for (int j = 0; j < output_width; ++j) {
            for (int m = 0; m < kernel_height; m += stride) {
                for (int n = 0; n < kernel_width; n += stride) {
                    output[i][j] += padded_input[i * stride + m][j * stride + n] * kernel[m][n];
                }
            }
        }
    }

    return output;
}

int main() {
    std::vector<std::vector<double>> input = {{1, 2, 3, 4},
                                             {5, 6, 7, 8},
                                             {9, 10, 11, 12}};

    std::vector<std::vector<double>> kernel = {{1, 0},
                                              {0, 1}};

    int padding = 1;
    int stride = 2;  
    std::vector<std::vector<double>> result = convolution(input, kernel, padding, stride);
  
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
