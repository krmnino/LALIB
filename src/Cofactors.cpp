#include "Matrix.h"
#include "Operations.h"

namespace {
    Matrix get_matrix_minor(Matrix& src, int skip_row, int skip_col) {
		Matrix minor_mrtx(src);
		minor_mrtx.remove_row(skip_row);
		minor_mrtx.remove_column(skip_col);
		return minor_mrtx;
	}
}

Matrix cofactors(Matrix& src) {
    if (!src.is_square()) {
		LALIB_Error ex(ErrorCode::NON_SQR_MTRX);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (src.get_m() <= 1 || src.get_n() <= 1) {
		LALIB_Error ex(ErrorCode::INVALID_DIMS_ONE);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
    Matrix out(src.get_m(), src.get_n());
    double det;
    for (int i = 0; i < src.get_m(); i++) {
	    for (int j = 0; j < src.get_n(); j++) {
            Matrix minor_mrtx(get_matrix_minor(src, i, j));
            det = determinant(minor_mrtx);
            // Compute cofactor and save
            det = ((i + 1 + j + 1) % 2 == 0) ? det : det * -1;
            out.set_single_element(i, j, det);
        }
    }
    return out;
}