// code to calculate the average return, variance, and standard deviation of a set of returns
#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the average return
double calculateAverageReturn(const std::vector<double>& returns) {
    double sum = 0.0;
    for (double r : returns) {
        sum += r;
    }
    return sum / returns.size();
}

// Function to calculate the variance
double calculateVariance(const std::vector<double>& returns, double averageReturn) {
    double sumSquaredDeviations = 0.0;
    for (double r : returns) {
        double deviation = r - averageReturn;
        sumSquaredDeviations += deviation * deviation;
    }
    return sumSquaredDeviations / (returns.size() - 1); // using N-1 for sample variance
}

// Function to calculate the standard deviation
double calculateStandardDeviation(double variance) {
    return std::sqrt(variance);
}

int main() {
    // Example data: monthly returns over five months
    std::vector<double> returns = {0.02, -0.01, 0.03, 0.04, -0.02};

    // Calculate the average return
    double averageReturn = calculateAverageReturn(returns);
    std::cout << "Average Return: " << averageReturn * 100 << "%" << std::endl;

    // Calculate the variance
    double variance = calculateVariance(returns, averageReturn);
    std::cout << "Variance: " << variance << std::endl;

    // Calculate the standard deviation
    double standardDeviation = calculateStandardDeviation(variance);
    std::cout << "Standard Deviation: " << standardDeviation * 100 << "%" << std::endl;

    return 0;
}
