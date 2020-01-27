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
	bool is_square();
	void set_single_element(int, int, double);
	void remove_row(int);
	void remove_column(int);
	void row_addition(int, int);
	void row_scale_up(int, double);
	void row_scale_down(int, double);
	void row_swap(int, int);
	void add(Matrix &input);
	void scale(double);
	std::string to_string();
};

#endif MATRIX_H