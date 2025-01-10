#ifndef READ_CSV_H
#define READ_CSV_H

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class csv_reader {
public:
    csv_reader(); // Constructor
    vector<vector<string>> read_csv(const string& filename); // CSV reader method
    void print_data(const vector<vector<string>>& data);
    vector<double> csv_get_column(const vector<vector<string>>& data, size_t column_number);
};

#endif // READ_CSV_H

