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
	Matrix(const Matrix &);
	Matrix(char, int);
	~Matrix();
	std::vector<std::vector<double>> get_matrix();
	int get_m();
	int get_n();
	bool is_square();
	double get_single_element(int, int);
	void set_single_element(int, int, double);
	Matrix get_row(int);
	Matrix get_column(int);
	void remove_row(int);
	void remove_column(int);
	void row_addition(int, int);
	void row_scale(int, double);
	void row_swap(int, int);
	void matrix_addition(Matrix&);
	void scalar_multi(double);
	void transpose();
	std::string to_string();
};

#endif