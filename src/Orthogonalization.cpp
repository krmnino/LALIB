#include "Matrix.h"
#include "Operations.h"

#include <cmath>
#include <iostream>

namespace {
	double vector_magnitude(Matrix& src) {
		double accumulator = 0;
		for (int i = 0; i < src.get_m(); i++) {
			accumulator += pow(src.get_single_element(i, 0), 2);
		}
		return sqrt(accumulator);
	}
}

Matrix unit_vector(Matrix &src) {
	if (src.get_n() != 1) {
		LALIB_Error ex(ErrorCode::NOT_SINGLE_COL);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	double v_length = 0;
	for (int i = 0; i < src.get_m(); i++) {
		v_length += pow(src.get_single_element(i, 0), 2);
	}
	Matrix out(src);
	v_length = sqrt(v_length);
	for (int i = 0; i < src.get_m(); i++) {
		out.set_single_element(i, 0, (src.get_single_element(i, 0) / v_length));
	}
	return out;
}

//Note: Computing the projection of proj_vec onto onto_vec_in: proj_(onto_vec_in)(proj_vec)
Matrix projection_onto(Matrix &onto_vec_in, Matrix &proj_vec) {
	if (onto_vec_in.get_n() != 1 || proj_vec.get_n() != 1) {
		LALIB_Error ex(ErrorCode::NOT_SINGLE_COL);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix onto_vec_out(onto_vec_in);
	double magnitude = pow(vector_magnitude(onto_vec_in), 2);
	onto_vec_out.transpose();
	double dot_product = multiply(onto_vec_out, proj_vec).get_single_element(0, 0);
	onto_vec_out.matrix_scale(dot_product / magnitude);
	return onto_vec_out;
}

Matrix gram_schmidt(Matrix &src) {
	Matrix out(src.get_m(), src.get_n());
	for (int i = 0; i < src.get_m(); i++) {
		out.set_single_element(i, 0, src.get_single_element(i, 0));
	}
	return out;
}