#include "Orthogonalization.h"
#include <cmath>

//TODO: Gram-Schmidt OP

Matrix unit_vector(Matrix &src) {
	if (src.get_n() != 1) {
		std::cout << "Matrix must contain 1 column." << std::endl;
		return src;
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

Matrix gram_schmidt(Matrix &src) {
	return src; //just a placeholder
}