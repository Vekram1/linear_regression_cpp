#include "read_csv.h"
#include <fstream>
#include <sstream>
using namespace std;

csv_reader::csv_reader() {
}

vector<vector<string>> csv_reader::read_csv(const string& filename) {
  vector<vector<string>> data;
  ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Error: Could not open the file " << filename << endl;
    return data;
  }

  string line;
  while (getline(file, line)) {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
      row.push_back(cell);
    }
    data.push_back(row);
  }

  file.close();
  return data;
}

// Print a 2D vector for debugging
void csv_reader::print_data(const vector<vector<string>>& data) {
  for (const auto& row : data) {
    for (const auto& cell : row) {
      std::cout << cell << " ";
    }
    cout << endl;
  }
}

vector<double> csv_reader::csv_get_column(const vector<vector<string>>& data, size_t column_number) {
  vector<double> column;

  if (data.empty()) {
    throw out_of_range("The 2D vector is empty.");
  }

  int row_count = 0;
  for (const auto& row : data) {
    if (column_number >= row.size()) {
      throw out_of_range("Column index out of range for one or more rows.");
    }

    // Convert the string value to float
    try {
      if (row_count > 0) {
        float value = std::stod(row[column_number]); // Use std::stod instead of atof
        column.push_back(value);
      }
    } catch (const invalid_argument& e) {
      throw runtime_error("Invalid data: Unable to convert string to float.");
    } catch (const std::out_of_range& e) {
      throw runtime_error("Value out of range for float conversion.");
    }
    row_count++;
  }
  return column;
}
