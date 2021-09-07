#include "Operations.h"

#include <iostream>

Matrix multiply(Matrix &m1, Matrix &m2) {
	Matrix out(m1.get_m(), m2.get_n());
	if (m1.get_n() != m2.get_m()) {
		LALIB_Error ex(ErrorCode::ROW_COL_NOTEQ);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	int out_row_index = 0;
	int out_column_index = 0;
	while (out_row_index < m1.get_m()) {
		double acc = 0;
		for (int i = 0; i < m1.get_n(); i++)
			acc += m1.get_single_element(out_row_index, i) * m2.get_single_element(i, out_column_index);
		out.set_single_element(out_row_index, out_column_index, acc);
		out_column_index++;
		if (out_column_index == m2.get_n()) {
			out_row_index++;
			out_column_index = 0;
		}
	}
	return out;
}