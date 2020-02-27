#include "Matrix.h"

Matrix transpose(Matrix src) {
	Matrix copy(src.get_n(), src.get_m());
	for (int i = 0; i < copy.get_m(); i++) 
		for (int j = 0; j < copy.get_n(); j++) 
			copy.set_single_element(i, j, src.get_single_element(j, i));
	return copy;
}