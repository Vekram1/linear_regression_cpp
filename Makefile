# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

# Target executable
TARGET = main

# Source files and object files
SRC = main.cpp read_csv.cpp qr_decomp_regression.cpp gradient_descent_regression.cpp
OBJ = $(SRC:.cpp=.o)

# Build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS)  -o $(TARGET) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

