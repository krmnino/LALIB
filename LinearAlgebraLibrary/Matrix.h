#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <string>

class Matrix {
private:
	std::vector<std::vector<int>> matrix;
	int m;
	int n;

public:
	Matrix(std::string);
	Matrix(int, int);
	std::vector<std::vector<int>> get_matrix();
	std::vector<std::vector<int>> copy_matrix();
	int get_m();
	int get_n();
	std::string display_as_string();
};

#endif MATRIX_H