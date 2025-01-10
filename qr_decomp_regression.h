#ifndef QR_DECOMP_REGRESSION_H
#define QR_DECOMP_REGRESSION_H

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class qr_regression
{
public:
    qr_regression(); // Constructor
    vector<vector<double>> construct_X_matrix(const vector<double> &x);
    void qr_decomposition(vector<vector<double>> &X, vector<vector<double>> &Q, vector<vector<double>> &R);
    vector<double> computeZ(const vector<vector<double>> &Q, const vector<double> &y);
    vector<double> backSubstitution(const vector<vector<double>> &R, const vector<double> &z);
};

#endif // QR_DECOMP_REGRESSION_H