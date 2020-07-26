#include "Matrix.h"
#include "Operations.h"

int rank(Matrix& src) {
	Matrix reduced = rref(src);
	int non_zero_cols = 0;
	for (int i = 0; i < reduced.get_m(); i++) {
		for (int j = 0; j < reduced.get_n(); j++) {
			if (reduced.get_single_element(i, j) != 0) {
				non_zero_cols++;
			}
		}
	}
	return non_zero_cols;
}
