#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include "step.hpp"

// Forward declaration of the step function
void step(float* r, const float* d, int n);

int main() {
    const int n = 4000;

    // Create random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // Allocate memory for input and output
    std::vector<float> d(n * n);
    std::vector<float> r(n * n);

    // Fill input with random floating point numbers between 0 and 1
    for (int i = 0; i < n * n; ++i) {
        d[i] = dis(gen);
    }

    // Measure execution time
    auto start = std::chrono::high_resolution_clock::now();
    step(r.data(), d.data(), n);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Print summary information to prevent compiler optimization
    float sum = 0.0f;
    float min_val = r[0];
    float max_val = r[0];

    for (int i = 0; i < n * n; ++i) {
        sum += r[i];
        min_val = std::min(min_val, r[i]);
        max_val = std::max(max_val, r[i]);
    }

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
    std::cout << "Result summary:" << std::endl;
    std::cout << "  Sum: " << std::fixed << std::setprecision(6) << sum << std::endl;
    std::cout << "  Min: " << min_val << std::endl;
    std::cout << "  Max: " << max_val << std::endl;

    return 0;
}
