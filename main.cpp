#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "read_csv.h"
#include "qr_decomp_regression.h"
#include "gradient_descent_regression.h"

using namespace std;
using namespace chrono;

void qr_decomposition_testing(vector<double> X, vector<double> y)
{
  qr_regression qr_regression_01;
  vector<vector<double>> X_matrix = qr_regression_01.construct_X_matrix(X);
  vector<vector<double>> Q, R;

  qr_regression_01.qr_decomposition(X_matrix, Q, R);
  vector<double> z = qr_regression_01.computeZ(Q, y);

  // Solve for Beta using back substitution
  vector<double> beta = qr_regression_01.backSubstitution(R, z);
  cout << "Regression Coefficients (beta):" << endl;
  cout << "Intercept (beta_0): " << beta[0] << endl;
  cout << "Slope (beta_1): " << beta[1] << endl;
}

void gradient_descent_testing(vector<double> X, vector<double> y)
{
  gradient_descent_regressor gradient_descent_regressor_01;
  double beta0 = 0.0;
  double beta1 = 0.0;

  double alpha = 0.01;
  int iterations = 6400;

  gradient_descent_regressor_01.gradientDescent(X, y, beta0, beta1, alpha, iterations);
  // Output final parameters
  cout << "GD Coefficients (beta):" << endl;
  cout << "beta0 (Intercept): " << beta0 << endl;
  cout << "beta1 (Slope): " << beta1 << endl;
}

int main() {
  string filename = "BostonHousing.csv";
  csv_reader csv_reader_01; // Create an object of csv_reader
  
  vector<vector<string>> csv_data = csv_reader_01.read_csv(filename);
  vector<double> y = csv_reader_01.csv_get_column(csv_data, csv_data[0].size()-1);
  vector<double> X = csv_reader_01.csv_get_column(csv_data, 7);

  // QR Decomposition
  auto start = high_resolution_clock::now();
  qr_decomposition_testing(X, y);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);
  cout << "QR Decomposition Time: " << duration.count() << " ns" << endl;

  // Gradient Descent
  start = high_resolution_clock::now();
  gradient_descent_testing(X, y);
  end = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(end - start);
  cout << "Gradient Descent Time: " << duration.count() << " ns" << endl;

  return 0;
}
