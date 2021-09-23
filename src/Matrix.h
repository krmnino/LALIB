#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <string>
#include <iostream>

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
	int get_m();
	int get_n();
	std::vector<std::vector<double>> get_matrix();
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
	Matrix operator+ (Matrix&);
	void scalar_multi(double);
	void transpose();
	friend std::ostream& operator<<(std::ostream& out, Matrix& matrx);
};

#endif