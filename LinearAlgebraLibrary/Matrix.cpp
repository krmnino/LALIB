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
	matrix.resize(m, vector<int>());
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
			int num = stoi(rows_arr[i].substr(0, index_end));
			matrix[i].push_back(num);
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
	matrix.resize(m, vector<int>(n, 0));
}

vector<vector<int>> Matrix::get_matrix() {
	return matrix;
}

int Matrix::get_m() {
	return m;
}

int Matrix::get_n() {
	return n;
}

string Matrix::display_as_string() {
	string out = "";
	for (int i = 0; i < (signed)matrix.size(); i++) {
		for (int j = 0; j < (signed)matrix[i].size(); j++) {
			out += to_string(matrix[i][j]) + " ";
		}
		out += "\n";
	}
	return out;
}
