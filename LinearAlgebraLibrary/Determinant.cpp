#include <iostream>
#include "LinearAlgebraLibrary.h"

using namespace std;

namespace {
	Matrix get_matrix_minor(Matrix src, int skip_row, int skip_col) {
		Matrix minor(src);
		//minor.remove_row()
		
		return minor;
	}

	double recursive_matrix_cofactor(Matrix src, int i, int j) {
		return 1.0;
	}
}

double determinant(Matrix src) {
	if (src.is_square()) {
		recursive_matrix_cofactor(src, 0, 0);
	}
	return -1;
}
