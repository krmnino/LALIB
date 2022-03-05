#include "Matrix.h"
#include "Operations.h"

double trace(Matrix& src) {
    if (src.get_m() == 0 || src.get_n() == 0) {
		LALIB_Error ex(ErrorCode::INVALID_DIMS);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
    if (!src.is_square()) {
		LALIB_Error ex(ErrorCode::NON_SQR_MTRX);
		std::cerr << ex.what() << std::endl;
		throw ex;
	}
    double out = 0;
    for(int i = 0; i < src.get_m(); i++){
        out += src.get_single_element(i, i);
    }
    return out;
}