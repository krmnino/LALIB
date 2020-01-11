#include <iostream>
#include "LinearAlgebraLibrary.h"

using namespace std;

namespace {
	Matrix get_matrix_minor(Matrix src, int skip_col) {
		Matrix minor(src);
		minor.remove_row(0);
		minor.remove_column(skip_col);
		return minor;
	}

	double recursive_matrix_cofactor(Matrix src, int row_acc, int accumulator) {
		for (int i = 0; i < src.get_n(); i++) {
			Matrix minor(get_matrix_minor(src, i));
			if (minor.get_m() == 1 && minor.get_n() == 1) {
				double one = pow(-1, i + row_acc);
				double cofactor = src.get_single_element(0, i);
				double minor_det = minor.get_single_element(0, 0);
				//accumulator += pow(-1, i + row_acc) * src.get_single_element(0, i) * minor.get_single_element(0, 0);
				accumulator += (one * cofactor * minor_det);
			}
			else {
				double one = pow(-1, i + row_acc);
				double cofactor = src.get_single_element(0, i);
				//accumulator += pow(-1, i + row_acc) * src.get_single_element(0, i) * recursive_matrix_cofactor(minor, row_acc + 1, accumulator);
				accumulator += (one * cofactor * recursive_matrix_cofactor(minor, row_acc + 1, accumulator));
			}
		}
		return -1;
	}
}

double determinant(Matrix src) {
	if (src.is_square()) {
		double accumulator = 0;
		recursive_matrix_cofactor(src, 0, 0.0);
		cout << accumulator << endl;
	}
	return -1;
}
