#include "qr_decomp_regression.h"


qr_regression::qr_regression() {
}

vector<vector<double>> qr_regression::construct_X_matrix(const vector<double>& x) {
  vector<vector<double>> X(x.size(), vector<double>(2, 1.0));
  for (size_t i = 0; i < x.size(); i++) {
    X[i][1] = x[i];
  }
  return X;
}

void qr_regression::qr_decomposition(vector<vector<double>>& X, vector<vector<double>>& Q, vector<vector<double>>& R) {
  size_t n = X.size(); // Number of rows
  size_t p = X[0].size(); // Number of columns
  Q = vector<vector<double>>(n, vector<double>(p, 0.0));
  R = vector<vector<double>>(p, vector<double>(p, 0.0));

  for (size_t k = 0; k < p; k++) {
    // Compute R[k][k]
    double norm = 0.0;
    for (size_t i = 0; i < n; i++) {
      norm += X[i][k] * X[i][k];
    }
    R[k][k] = sqrt(norm);

    // Compute Q[:, k]
    for (size_t i = 0; i < n; i++) {
      Q[i][k] = X[i][k] / R[k][k];
    }

    // Update R[k][j] and X[:, j]
    for (size_t j = k + 1; j < p; j++) {
      R[k][j] = 0.0;
      for (size_t i = 0; i < n; i++) {
        R[k][j] += Q[i][k] * X[i][j];
      }
      for (size_t i = 0; i < n; i++) {
        X[i][j] -= R[k][j] * Q[i][k];
      }
    }
  }
}

// Step 3: Compute z = Q^T * y
vector<double> qr_regression::computeZ(const vector<vector<double>> &Q, const vector<double> &y)
{
  size_t n = Q.size();    // Number of rows
  size_t p = Q[0].size(); // Number of columns
  vector<double> z(p, 0.0);

  for (size_t j = 0; j < p; ++j)
  {
    for (size_t i = 0; i < n; ++i)
    {
      z[j] += Q[i][j] * y[i];
    }
  }

  return z;
}

// Step 4: Solve R * beta = z using back substitution
vector<double> qr_regression::backSubstitution(const vector<vector<double>> &R, const vector<double> &z)
{
  size_t p = R.size();
  vector<double> beta(p, 0.0);

  for (int i = p - 1; i >= 0; --i)
  {
    beta[i] = z[i];
    for (size_t j = i + 1; j < p; ++j)
    {
      beta[i] -= R[i][j] * beta[j];
    }
    beta[i] /= R[i][i];
  }

  return beta;
}
