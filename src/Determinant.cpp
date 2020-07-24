#include "Matrix.h"
#include "Operations.h"

#include <iostream>

namespace {
	Matrix get_matrix_minor(Matrix src, int skip_col) {
		Matrix minor(src);
		minor.remove_row(0);
		minor.remove_column(skip_col);
		return minor;
	}

	double recursive_determinant(Matrix src) {
		double accumulator = 0;
		int sign_flag = 1;
		if (src.get_m() == 1 && src.get_n() == 1) 
			return src.get_single_element(0, 0);
		for (int i = 0; i < src.get_n(); i++) {
			Matrix minor(get_matrix_minor(src, i));
			double cofactor = src.get_single_element(0, i);
			accumulator += sign_flag * src.get_single_element(0, i) * recursive_determinant(minor);
			sign_flag = -sign_flag;
		}
		return accumulator;
	}
}

double determinant(Matrix &src) {
	if (!src.is_square()) {
		//Throw exception when this condition is satisfied
		std::cout << "Matrix must be square!" << std::endl;
		return 1.0;
	}
	return recursive_determinant(src);
}
