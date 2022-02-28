#include "Matrix.h"
#include "Operations.h"

int rank(Matrix& src) {
	if(src.get_m() <= 0 || src.get_n() <= 0){
		LALIB_Error ex(ErrorCode::INVALID_DIMS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
	Matrix reduced = rref(src);
	int non_zero_cols = 0;
	for (int i = 0; i < reduced.get_m(); i++) {
		for(int j = i; j < reduced.get_n(); j++){
			// In case the evaluated number is 0.9999... add 1e-15 and cast to int
			if(int(reduced.get_single_element(i, j) + 0.000000000000001) == 1){
				non_zero_cols++;
				break;
			}
		}
	}
	return non_zero_cols;
}
