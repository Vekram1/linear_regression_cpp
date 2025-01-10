#include "gradient_descent_regression.h"

gradient_descent_regressor::gradient_descent_regressor() {
}

// Function to compute the cost (Mean Squared Error)
double gradient_descent_regressor::computeCost(const vector<double> &x, const vector<double> &y, double beta0, double beta1)
{
    size_t n = x.size();
    double cost = 0.0;

    for (size_t i = 0; i < n; ++i)
    {
        double prediction = beta0 + beta1 * x[i];
        cost += pow(y[i] - prediction, 2);
    }

    return cost / (2 * n);
}

// Gradient descent to optimize beta0 and beta1
void gradient_descent_regressor::gradientDescent(const vector<double> &x, const vector<double> &y, double &beta0, double &beta1, double alpha, int iterations)
{
    size_t n = x.size();

    for (int iter = 0; iter < iterations; ++iter)
    {
        double dBeta0 = 0.0;
        double dBeta1 = 0.0;

        // Compute the gradients
        for (size_t i = 0; i < n; ++i)
        {
            double error = (beta0 + beta1 * x[i]) - y[i];
            dBeta0 += error;
            dBeta1 += error * x[i];
        }

        dBeta0 /= n;
        dBeta1 /= n;

        // Update beta0 and beta1
        beta0 -= alpha * dBeta0;
        beta1 -= alpha * dBeta1;

        // Optionally, print the cost for each iteration
        // if (iter % 100 == 0)
        // {
        //     double cost = computeCost(x, y, beta0, beta1);
        //     cout << "Iteration " << iter << " | Cost: " << cost << " | beta0: " << beta0 << " | beta1: " << beta1 << endl;
        // }
    }
}