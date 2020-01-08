#include "REF.h"

Matrix ref(Matrix src) {
	Matrix copy(src);
	for (int i = 0; i < copy.get_n(); i++) {
		if (i >= copy.get_m() || i >= copy.get_n())
			break;
		if (copy.get_single_element(i, i) == 0)
			copy.row_swap(i, i + 1);
		copy.row_scale_down(i, copy.get_single_element(i, i));
		for (int j = 0; j < copy.get_m(); j++) {
			if (j != i) {
				double multiplier = copy.get_single_element(j, i);
				for (int k = 0; k < copy.get_n(); k++) {
					if (i == k) {
						break;
					}
					else {
						double element = -1.0 * copy.get_single_element(i, k) * multiplier;
						copy.set_single_element(j, k, copy.get_single_element(j, k) + element);
					}
				}
			}
		}
	}
	return copy;
}