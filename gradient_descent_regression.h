#ifndef GRADIENT_DESCENT_REGRESSION_H
#define GRADIENT_DESCENT_REGRESSION_H

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class gradient_descent_regressor
{
public:
    gradient_descent_regressor(); // Constructor
    double computeCost(const vector<double> &x, const vector<double> &y, double beta0, double beta1);
    void gradientDescent(const vector<double> &x, const vector<double> &y, double &beta0, double &beta1, double alpha, int iterations);
};

#endif // GRADIENT_DESCENT_REGRESSION_H