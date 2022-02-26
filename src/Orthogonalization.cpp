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
	double magnitude = dot_product(onto_vec, onto_vec);
	double onto_proj_dp = dot_product(onto_vec, proj_vec);
	out.matrix_scale(onto_proj_dp / magnitude);
	return out;
}

std::vector<Matrix> gram_schmidt(std::vector<Matrix>& vect_space) {
	if(vect_space.size() == 0){
		LALIB_Error ex(ErrorCode::EMPTY_SPACE);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	int n_dim = vect_space[0].get_n();
	for(int i = 0; i < vect_space.size(); i++){
		if (vect_space[i].get_m() != 1) {
			LALIB_Error ex(ErrorCode::NOT_SINGLE_ROW);
			std::cerr << ex.what() << std::endl;
			throw ex;
		}
		if (vect_space[i].get_n() != n_dim) {
			LALIB_Error ex(ErrorCode::INCONS_MATRX_COLS);
			std::cerr << ex.what() << std::endl;
			throw ex;
		}
	}
	std::vector<Matrix> out_vect_space;
	// u_1 = v_1
	out_vect_space.push_back(vect_space[0]);
	Matrix v;
	Matrix u;
	// Compute orthogonal basis
	for(int i = 1; i < vect_space.size(); i++){
		Matrix v = vect_space[i];
		for(int j = 0; j < out_vect_space.size(); j++){
			u = projection_onto(out_vect_space[j], vect_space[i]);
			v = v - u;
		}
		out_vect_space.push_back(v);
	}
	// Compute orthonormal basis
	for(int i = 0; i < out_vect_space.size(); i++){
		out_vect_space[i].matrix_scale(1 / sqrt(dot_product(out_vect_space[i], out_vect_space[i])));
	}
	return out_vect_space;
}
