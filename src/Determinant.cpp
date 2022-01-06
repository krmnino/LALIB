#include "Matrix.h"
#include "Operations.h"

namespace {
	Matrix get_matrix_minor(Matrix& src, int skip_col) {
		Matrix minor(src);
		minor.remove_row(0);
		minor.remove_column(skip_col);
		return minor;
	}

	double recursive_determinant(Matrix& src) {
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
		LALIB_Error ex(ErrorCode::NON_SQR_MTRX);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (src.get_m() == 0 || src.get_n() == 0) {
		LALIB_Error ex(ErrorCode::INVALID_DIMS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	return recursive_determinant(src);
}

bool is_singular(Matrix& src) {
	double ret_det = determinant(src);
	if (ret_det != 0.0) {
		return false;
	}
	return true;
}
