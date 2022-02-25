#include "Matrix.h"
#include "Operations.h"

#include <cmath>
#include <iostream>

Matrix unit_vector(Matrix &src) {
	if (src.get_m() != 1) {
		LALIB_Error ex(ErrorCode::NOT_SINGLE_ROW);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	double v_length = 0;
	for (int i = 0; i < src.get_n(); i++) {
		v_length += pow(src.get_single_element(0, i), 2);
	}
	Matrix out(src);
	v_length = sqrt(v_length);
	for (int i = 0; i < src.get_n(); i++) {
		out.set_single_element(0, i, (src.get_single_element(0, i) / v_length));
	}
	return out;
}

//Note: Computing the projection of proj_vec onto onto_vec -> proj_(onto_vec)(proj_vec)
Matrix projection_onto(Matrix &onto_vec, Matrix &proj_vec) {
	if (onto_vec.get_m() != 1 || proj_vec.get_m() != 1) {
		LALIB_Error ex(ErrorCode::NOT_SINGLE_ROW);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	if (onto_vec.get_n() != proj_vec.get_n()) {
		LALIB_Error ex(ErrorCode::INCONS_MATRX_COLS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix out(onto_vec);
	double magnitude = 0;
	for (int i = 0; i < onto_vec.get_n(); i++) {
		magnitude += pow(onto_vec.get_single_element(0, i), 2);
	}
	double dot_prod = dot_product(onto_vec, proj_vec);
	out.matrix_scale(dot_prod / magnitude);
	return out;
}

Matrix gram_schmidt(Matrix &src) {
	Matrix out(src.get_m(), src.get_n());
	for (int i = 0; i < src.get_m(); i++) {
		out.set_single_element(i, 0, src.get_single_element(i, 0));
	}
	return out;
}