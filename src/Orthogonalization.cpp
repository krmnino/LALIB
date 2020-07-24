#include "Matrix.h"
#include "Operations.h"

#include <cmath>
#include <iostream>

namespace {
	double vector_magnitude(Matrix src) {
		double accumulator = 0;
		for (int i = 0; i < src.get_m(); i++) {
			accumulator += pow(src.get_single_element(i, 0), 2);
		}
		return sqrt(accumulator);
	}
}

Matrix unit_vector(Matrix &src) {
	if (src.get_n() != 1) {
		std::cout << "Matrix must contain 1 column." << std::endl;
		return src;
		//Add throw exception
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

Matrix projection_onto(Matrix &src1, Matrix &src2) { //Note: Projection of src2 onto src1
	src1.transpose();
	//Matrix src1_t = transpose(src1);
	double magnitude = 0;
	for (int i = 0; i < src1.get_m(); i++) {
		magnitude += pow(src1.get_single_element(i, 0), 2);
	}
	double dot_product = multiply(src1, src2).get_single_element(0, 0);
	src1.scalar_multi(dot_product / magnitude);
	return src1;
}

Matrix gram_schmidt(Matrix &src) {
	Matrix out(src.get_m(), src.get_n());
	for (int i = 0; i < src.get_m(); i++) {
		out.set_single_element(i, 0, src.get_single_element(i, 0));
	}
	return out;
}