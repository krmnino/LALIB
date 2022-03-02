#include "Matrix.h"
#include "Operations.h"

namespace {
	Matrix get_matrix_minor(Matrix& src, int skip_col) {
		Matrix minor_mrtx(src);
		minor_mrtx.remove_row(0);
		minor_mrtx.remove_column(skip_col);
		return minor_mrtx;
	}

	double recursive_determinant(Matrix& src) {
		double accumulator = 0;
		int sign_flag = 1;
		if (src.get_m() == 1 && src.get_n() == 1) 
			return src.get_single_element(0, 0);
		for (int i = 0; i < src.get_n(); i++) {
			Matrix minor_mrtx(get_matrix_minor(src, i));
			double cofactor = src.get_single_element(0, i);
			accumulator += sign_flag * src.get_single_element(0, i) * recursive_determinant(minor_mrtx);
			sign_flag = -sign_flag;
		}
		return accumulator;
	}
}

Matrix adjoint(Matrix& src){
    Matrix out(src.get_m(), src.get_n());
    double val = recursive_determinant(src);
    return out;
}