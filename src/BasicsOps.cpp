#include "Matrix.h"
#include "Operations.h"

#include <iostream>

void add(Matrix& src1, Matrix& src2) {
	if (src1.get_m() != src2.get_m() && src1.get_m() != src2.get_m()) {
		std::cout << "Matrix dimensions are not consistent." << std::endl;
		return;
	}
	else {
		for (int i = 0; i < src1.get_m(); i++) {
			for (int j = 0; j < src1.get_n(); j++) {
				src1.set_single_element(i, j, src1.get_single_element(i, j) + src2.get_single_element(i, j));
			}
		}
	}
	return;
}

void add(Matrix& src, double value) {
	for (int i = 0; i < src.get_m(); i++) {
		for (int j = 0; j < src.get_n(); j++) {
			src.set_single_element(i, j, src.get_single_element(i, j) + value);
		}
	}
}