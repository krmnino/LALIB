#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <string>

class Matrix {
private:
	std::vector<std::vector<double>> matrix;
	int m;
	int n;

public:
	Matrix(std::string);
	Matrix(int, int);
	Matrix(const Matrix &m);
	std::vector<std::vector<double>> get_matrix();
	int get_m();
	int get_n();
	double get_single_element(int, int);
	void update_single_element(int, int, double);
	void row_addition(int, int);
	void row_scale_up(int, double);
	void row_scale_down(int, double);
	void row_swap(int, int);
	std::string to_string();
};

#endif MATRIX_H