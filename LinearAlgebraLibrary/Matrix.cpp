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
				data = data.substr(index_end + 1, data.length());
				index_end = data.find(";");
			}
			else {
				break;
			}
		}
	}
	string first_row = rows_arr[0];
	m = rows_arr.size();
	n = 0;
	int index_end = first_row.find(" ");
	while (true) {
		if (index_end != -1) {
			n++;
			int offset = 0;
			bool digits_remaining = false;
			for (int i = index_end; i < (signed)first_row.length(); i++) {
				if (isdigit(first_row.at(i))) {
					digits_remaining = true;
					break;
				}
			}
			while (digits_remaining && first_row.at(index_end + offset) == ' ') {
				offset++;
			}
			first_row = first_row.substr(index_end + 1 + offset, first_row.length());
			index_end = first_row.find(" ");
		}
		else {
			n++;
			break;
		}
	}
	matrix.resize(m, vector<double>());
	int length = rows_arr.size();
	for (int i = 0; i < length; i++) {
		if (rows_arr[i].at(0) == ' ') {
			int offset = 0;
			for (offset = 0; offset < (signed)rows_arr[i].length(); offset++) {
				if (isdigit(rows_arr[i].at(offset)))
					break;
			}
			rows_arr[i] = rows_arr[i].substr(offset, rows_arr[i].length());
		}
		int index_end = rows_arr[i].find(" ");
		int elements = 0;
		while (elements < n) {
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
					while (rows_arr[i].at(index_end + 1 + offset) == ' ')
						offset++;
					rows_arr[i] = rows_arr[i].substr(index_end + offset + 1, rows_arr[i].length());
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
	m = m_;
	n = n_;
	matrix.resize(m, vector<double>(n, 0));
}

Matrix::Matrix(const Matrix &src) {
	m = src.m;
	n = src.n;
	matrix = src.matrix;
}

vector<vector<double>> Matrix::get_matrix() {
	return matrix;
}

int Matrix::get_m() {
	return m;
}

int Matrix::get_n() {
	return n;
}

double Matrix::get_single_element(int row, int column) {
	return matrix[row][column];
}

bool Matrix::is_square() {
	if (m == n)
		return true;
	return false;
}

void Matrix::set_single_element(int row, int column, double val) {
	matrix[row][column] = val;
}

void Matrix::remove_row(int row) {
	m = m - 1;
	matrix.erase(matrix.begin() + row);
}

void Matrix::remove_column(int column) {
	n = n - 1;
	for (int i = 0; i < m; i++) {
		matrix[i].erase(matrix[i].begin() + column);
	}
}

void Matrix::row_addition(int row1, int row2) {
	for (int i = 0; i < n; i++) {
		matrix[row1][i] += matrix[row2][i];
	}
}

void Matrix::row_scale_up(int row, double scalar) {
	for (int i = 0; i < n; i++) {
		matrix[row][i] *= scalar;
	}
}

void Matrix::row_scale_down(int row, double scalar) {
	for (int i = 0; i < n; i++) {
		matrix[row][i] /= scalar;
	}
}

void Matrix::row_swap(int to_row, int from_row) {
	if (to_row >= m || from_row >= m) {
		for (int i = 0; i < n; i++) {
			int temp = matrix[to_row][i];
			matrix[to_row][i] = matrix[from_row][i];
			matrix[from_row][i] = temp;
		}
	}
}

string Matrix::to_string() {
	string out = "";
	for (int i = 0; i < (signed)matrix.size(); i++) {
		for (int j = 0; j < (signed)matrix[i].size(); j++) {
			out += std::to_string(matrix[i][j]) + " ";
		}
		out += "\n";
	}
	return out;
}
