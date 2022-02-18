#include <vector>
#include <iostream>
#include "Matrix.h"
#include "ErrorHandler.h"

Matrix::Matrix() {
	this->m = 0;
	this->n = 0;
}

Matrix::Matrix(std::string data) {
	std::vector<std::string> str_rows;
	split_string(str_rows, data, ';');
	for (int i = 0; i < str_rows.size(); i++) {
		std::vector<std::string> str_cols;
		split_string(str_cols, str_rows[i], ' ');
		if (i == 0) {
			this->m = str_rows.size();
			this->n = str_cols.size();
			this->matrix.resize(this->m, std::vector<double>(this->n, 0));
		}
		if (this->n != str_cols.size()) {
			LALIB_Error ex(ErrorCode::UNEVEN_INPUT_COLS);
			std::cerr << ex.what() << std::endl;
			throw ex;
		}
		for (int j = 0; j < str_cols.size(); j++) {
			for (int k = 0; k < str_cols[j].size(); k++) {
				if (!std::isdigit(str_cols[j].at(k))) {
					if (str_cols[j].at(k) == '.' || str_cols[j].at(k) == '-') {
						continue;
					}
					LALIB_Error ex(ErrorCode::NO_NUMERIC_INPUT);
					std::cerr << ex.what() << std::endl;
					throw ex;
				}
			}
			#ifdef LINUX
			this->matrix[i][j] = atof(str_cols[j].c_str());
			#else
			this->matrix[i][j] = stoi(str_cols[j]);
			#endif // LINUX
		}
	}
}

Matrix::Matrix(int m_, int n_) {
	this->m = m_;
	this->n = n_;
	this->matrix.resize(this->m, std::vector<double>(this->n, 0));
}

Matrix::Matrix(const Matrix &src) {
	this->m = src.m;
	this->n = src.n;
	this->matrix = src.matrix;
}

Matrix::Matrix(char flag, int n) {
	switch (flag) {
		case 'r': // Generate matrix nxn of random values
			this->m = n;
			this->n = n;
			this->matrix.resize(this->m, std::vector<double>(this->n, 0));
			for (int i = 0; i < this->m; i++) {
				for (int j = 0; j < this->n; j++) {
					this->matrix[i][j] = rand() % (n * n) + (double)1;
				}
			}
			break;
		case 'i': // Generate identity matrix nxn 
			this->m = n;
			this->n = n;
			this->matrix.resize(this->m, std::vector<double>(this->n, 0));
			for (int i = 0; i < this->m; i++)
				this->matrix[i][i] = 1;
			break;
		default:
			break;
	}
}

Matrix::~Matrix() {};

void Matrix::split_string(std::vector<std::string>& processed, std::string& buffer, char delimiter) {
	int base = 0;
	std::string split;
	for (unsigned int i = 0; i < buffer.length(); i++) {
		if (buffer.at(i) == delimiter) {
			split = buffer.substr(base, i - base);
			if (split.length() != 0) {
				processed.push_back(split);
			}
			base = i + 1;
		}
		else if (i == buffer.length() - 1) {
			split = buffer.substr(base, i + 1 - base);
			if (split.length() != 0) {
				processed.push_back(split);
			}
			base = i + 1;
		}
	}
}

std::vector<std::vector<double>> Matrix::get_matrix() {
	return this->matrix;
}

int Matrix::get_m() {
	return this->m;
}

int Matrix::get_n() {
	return this->n;
}

bool Matrix::is_square() {
	if (this->m == this->n) {
		return true;
	}
	return false;
}

bool Matrix::equal(Matrix& src) {
	if (this->get_m() != src.get_m()) {
		return false;
	}
	if (this->get_n() != src.get_n()) {
		return false;
	}
	for (int i = 0; i < this->get_m(); i++) {
		for (int j = 0; j < this->get_n(); j++) {
			if (this->get_single_element(i, j) != src.get_single_element(i, j)) {
				return false;
			}
		}
	}
	return true;
}

double Matrix::get_single_element(int row, int col) {
	if (0 > row || row >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (0 > col || col >= this->n) {
		LALIB_Error ex(ErrorCode::COL_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	return this->matrix[row][col];
}

void Matrix::set_single_element(int row, int col, double val) {
	if (0 > row || row >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (0 > col || col >= this->n) {
		LALIB_Error ex(ErrorCode::COL_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	this->matrix[row][col] = val;
}

Matrix Matrix::get_row(int row) {
	if (0 > row || row >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix out(1, this->n);
	for (int i = 0; i < this->n; i++) {
		out.set_single_element(0, i, this->matrix[row][i]);
	}
	return out;
}

Matrix Matrix::get_column(int col) {
	if (0 > col || col >= this->n) {
		LALIB_Error ex(ErrorCode::COL_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix out(this->m, 1);
	for (int i = 0; i < this->m; i++) {
		out.set_single_element(i, 0, this->matrix[i][col]);
	}
	return out;
}

void Matrix::remove_row(int row) {
	if (0 > row || row >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	this->m = this->m - 1;
	matrix.erase(matrix.begin() + row);
}

void Matrix::remove_column(int col) {
	if (0 > col || col >= this->n) {
		LALIB_Error ex(ErrorCode::COL_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	this->n = this->n - 1;
	for (int i = 0; i < this->m; i++) {
		this->matrix[i].erase(this->matrix[i].begin() + col);
	}
}

void Matrix::row_addition(int row1, int row2) {
	if (0 > row1 || row1 >= this->m || 0 > row2 || row2 >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	for (int i = 0; i < this->n; i++) {
		this->matrix[row1][i] += this->matrix[row2][i];
	}
}

void Matrix::row_scale(int row, double scalar) {
	if (0 > row || row >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	for (int i = 0; i < this->n; i++) {
		this->matrix[row][i] *= scalar;
	}
}

void Matrix::row_swap(int row1, int row2) {
	if (0 > row1 || row1 >= this->m || 0 > row2 || row2 >= this->m) {
		LALIB_Error ex(ErrorCode::ROW_OUT_BOUNDS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	for (int i = 0; i < this->n; i++) {
		double temp = this->matrix[row1][i];
		this->matrix[row1][i] = this->matrix[row2][i];
		this->matrix[row2][i] = temp;
	}
}

void Matrix::matrix_addition(Matrix& src) {
	if (this->m != src.get_m()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_ROWS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (this->n != src.get_n()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_COLS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			this->matrix[i][j] += src.get_single_element(i, j);
		}
	}
}

void Matrix::matrix_scale(double scalar) {
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			this->matrix[i][j] *= scalar;
		}
	}
}

void Matrix::transpose() {
	Matrix transposed(this->n, this->m);
	for (int i = 0; i < transposed.get_m(); i++)
		for (int j = 0; j < transposed.get_n(); j++)
			transposed.set_single_element(i, j, this->matrix[j][i]);
	this->matrix = transposed.get_matrix();
	this->m = transposed.get_m();
	this->n = transposed.get_n();
}

Matrix Matrix::operator+(Matrix& src) {
	if (this->m != src.get_m()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_ROWS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (this->n != src.get_n()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_COLS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix out(this->m, this->n);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			out.set_single_element(i, j, this->matrix[i][j] + src.get_single_element(i, j));
		}
	}
	return out;
}

Matrix Matrix::operator-(Matrix& src) {
	if (this->m != src.get_m()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_ROWS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (this->n != src.get_n()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_COLS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix out(this->m, this->n);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			out.set_single_element(i, j, this->matrix[i][j] - src.get_single_element(i, j));
		}
	}
	return out;
}

Matrix Matrix::operator*(double scalar) {
	Matrix out(this->m, this->n);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			out.set_single_element(i, j, this->matrix[i][j] * scalar);
		}
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, Matrix& mtrx) {
	for (int i = 0; i < (signed)mtrx.get_m(); i++) {
		for (int j = 0; j < (signed)mtrx.get_n(); j++) {
			out << std::to_string(mtrx.get_single_element(i, j)) + " ";
		}
		out << "\n";
	}
	return out;
}
