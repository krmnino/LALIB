#include <vector>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(string data) {
	vector<string> rows_arr;
	if (data.find(";") == -1) {
		rows_arr.push_back(data);
	}
	else {
		int index_start = 0;
		int index_end = data.find(";");
		while (true) {
			string row = data.substr(0, index_end);
			if (row.length() != 0)
				rows_arr.push_back(row);
			else
				break;
			if (index_end != -1) {
				data = data.substr((long)index_end + 1, data.length());
				index_end = data.find(";");
			}
			else {
				break;
			}
		}
	}
	string first_row = rows_arr[0];
	this->m = rows_arr.size();
	this->n = 0;
	int index_end = first_row.find(" ");
	while (true) {
		if (index_end != -1) {
			this->n++;
			int offset = 0;
			bool digits_remaining = false;
			for (int i = index_end; i < (signed)first_row.length(); i++) {
				if (isdigit(first_row.at(i))) {
					digits_remaining = true;
					break;
				}
			}
			while (digits_remaining && first_row.at((long)index_end + offset) == ' ') {
				offset++;
			}
			first_row = first_row.substr((long)index_end + 1 + offset, first_row.length());
			index_end = first_row.find(" ");
		}
		else {
			this->n++;
			break;
		}
	}
	this->matrix.resize(this->m, vector<double>());
	for (int i = 0; i < (signed)rows_arr.size(); i++) {
		if (rows_arr[i].at(0) == ' ') {
			int offset = 0;
			for (offset = 0; offset < (signed)rows_arr[i].length(); offset++) {
				if (isdigit(rows_arr[i].at(offset)) || rows_arr[i].at(offset) == '-')
					break;
			}
			rows_arr[i] = rows_arr[i].substr(offset, rows_arr[i].length());
		}
		int index_end = rows_arr[i].find(" ");
		int elements = 0;
		while (elements < this->n) {
			matrix[i].push_back(stod(rows_arr[i].substr(0, index_end)));
			if (index_end != -1) {
				int offset = 0;
				bool digits_remaining = false;
				for (int j = index_end; j < (signed)rows_arr[i].length(); j++) {
					if (isdigit(rows_arr[i].at(j))) {
						digits_remaining = true;
						break;
					}
				}
				if (!digits_remaining)
					break;
				else {
					while (rows_arr[i].at((long)index_end + 1 + offset) == ' ')
						offset++;
					rows_arr[i] = rows_arr[i].substr((long)index_end + offset + 1, rows_arr[i].length());
					index_end = rows_arr[i].find(" ");
					elements++;
				}
			}
			else
				break;
		}
	}
}

Matrix::Matrix(int m_, int n_) {
	this->m = m_;
	this->n = n_;
	this->matrix.resize(this->m, vector<double>(this->n, 0));
}

Matrix::Matrix(const Matrix &src) {
	this->m = src.m;
	this->n = src.n;
	this->matrix = src.matrix;
}

Matrix::Matrix(char flag, int n) {
	this->m = n;
	this->n = n;
	this->matrix.resize(this->m, vector<double>(this->n, 0));
	switch (flag) {
		case 'r':
			for (int i = 0; i < this->m; i++) {
				for (int j = 0; j < this->n; j++) {
					this->matrix[i][j] = rand() % (n * n) + 1;
				}
			}
			break;
		case 'i':
			for (int i = 0; i < this->m; i++)
				this->matrix[i][i] = 1;
			break;
		default:
			break;
	}
}

Matrix::~Matrix() {};

vector<vector<double>> Matrix::get_matrix() {
	return this->matrix;
}

int Matrix::get_m() {
	return this->m;
}

int Matrix::get_n() {
	return this->n;
}

double Matrix::get_single_element(int row, int column) {
	return this->matrix[row][column];
}

bool Matrix::is_square() {
	if (this->m == this->n)
		return true;
	return false;
}

void Matrix::set_single_element(int row, int column, double val) {
	this->matrix[row][column] = val;
}

void Matrix::remove_row(int row) {
	this->m = this->m - 1;
	matrix.erase(matrix.begin() + row);
}

void Matrix::remove_column(int column) {
	this->n = this->n - 1;
	for (int i = 0; i < this->m; i++) {
		this->matrix[i].erase(this->matrix[i].begin() + column);
	}
}

void Matrix::row_addition(int row1, int row2) {
	for (int i = 0; i < this->n; i++) {
		this->matrix[row1][i] += this->matrix[row2][i];
	}
}

void Matrix::row_scale_up(int row, double scalar) {
	for (int i = 0; i < this->n; i++) {
		this->matrix[row][i] *= scalar;
	}
}

void Matrix::row_scale_down(int row, double scalar) {
	for (int i = 0; i < this->n; i++) {
		this->matrix[row][i] /= scalar;
	}
}

void Matrix::row_swap(int row1, int row2) {
	if (row1 < this->m || row2 < this->m) {
		for (int i = 0; i < this->n; i++) {
			int temp = this->matrix[row1][i];
			this->matrix[row1][i] = this->matrix[row2][i];
			this->matrix[row2][i] = temp;
		}
	}
}

void Matrix::add(Matrix &input) {
	if (this->m == input.get_m() && this->n == input.get_n()) {
		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) 
				this->matrix[i][j] += input.get_single_element(i, j);
		}
	}
}

void Matrix::scale(double scalar) {
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++)
			this->matrix[i][j] *= scalar;
	}
}

Matrix Matrix::concatenate(Matrix& m1, Matrix& m2) { // TODO...
	Matrix out(m1.get_m(), m1.get_n() + m2.get_n());
	return out;
}

string Matrix::to_string() {
	string out = "";
	for (int i = 0; i < (signed)this->matrix.size(); i++) {
		for (int j = 0; j < (signed)this->matrix[i].size(); j++) {
			out += std::to_string(this->matrix[i][j]) + " ";
		}
		out += "\n";
	}
	return out;
}
