#include "Operations.h"

namespace {
	int find_pivot_row(Matrix& copy, int row, int col) {
		for (int i = row; i < copy.get_m(); i++) {
			if (copy.get_single_element(i, col) != 0)
				return i;
		}
		return -1;
	}
}

Matrix invert(Matrix& src) {

	if (!src.is_square()) {
		LALIB_Error ex(ErrorCode::NON_SQR_MTRX);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (determinant(src) == 0) {
		LALIB_Error ex(ErrorCode::INV_SNGL_MTRX);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix copy(src);
	Matrix inverted('i', src.get_n());
	int row = 0; //index of current pivot row
	int col = 0; //index of current pivot column
	for (row = 0; row < copy.get_m(); row++) {
		while (true) {
			if (row >= copy.get_m() || col >= copy.get_n())
				return copy;
			int new_pivot_row = find_pivot_row(copy, row, col);
			if (new_pivot_row == col)
				break;
			else if (new_pivot_row == -1)
				col++;
			else {
				copy.row_swap(new_pivot_row, row);
				inverted.row_swap(new_pivot_row, row);
				break;
			}
		}
		if (copy.get_single_element(row, col) != 0) {
			double pivot_scalar = copy.get_single_element(row, col);
			copy.row_scale(row, 1.0 / pivot_scalar);
			inverted.row_scale(row, 1.0 / pivot_scalar);
		}
		for (int j = 0; j < copy.get_m(); j++) {
			if (row != j) {
				double mul = -1 * copy.get_single_element(j, col);
				for (int k = 0; k < copy.get_n(); k++) {
					copy.set_single_element(j, k, (copy.get_single_element(j, k) + copy.get_single_element(row, k) * mul));
					inverted.set_single_element(j, k, (inverted.get_single_element(j, k) + inverted.get_single_element(row, k) * mul));
				}
			} 
		}
		col++;
	}
	return inverted;
}