#include "ErrorHandler.h"

LALIB_Error::LALIB_Error() {
	this->err_code = ErrorCode::OK;
}

LALIB_Error::LALIB_Error(ErrorCode error) {
	this->err_code = error;
	switch (this->err_code) {
		case ErrorCode::OK:
			break;
		case ErrorCode::NON_SQR_MTRX:
			this->message = "Error: Evaluated matrix is not square.";
			break;
		case ErrorCode::INV_SNGL_MTRX:
			this->message = "Error: Cannot compute inverse of a singular matrix.";
			break;
		case ErrorCode::INCONS_MATRX_DIMS:
			this->message = "Error: The row and column count is not consistent between both matrices.";
			break;
		case ErrorCode::INCONS_MATRX_ROWS:
			this->message = "Error: The row count is not consistent between both matrices.";
			break;
		case ErrorCode::INCONS_MATRX_COLS:
			this->message = "Error: The column count is not consistent between both matrices.";
			break;
		case ErrorCode::ROW_OUT_BOUNDS:
			this->message = "Error: Row index of evaluated matrix is out of bounds.";
			break;
		case ErrorCode::COL_OUT_BOUNDS:
			this->message = "Error: Column index of evaluated matrix is out of bounds.";
			break;
		case ErrorCode::ROW_COL_NOTEQ:
			this->message = "M and N dimensions do not match between evaluated matrices.";
			break;
		case ErrorCode::NOT_SINGLE_ROW:
			this->message = "The number of rows in evauluated matrix must be 1.";
			break;
		case ErrorCode::NOT_SINGLE_COL:
			this->message = "The number of columns in evauluated matrix must be 1.";
			break;
		default:
			this->message = "Undefinded error.";
			break;
	}
}

LALIB_Error::~LALIB_Error() noexcept {}

const char* LALIB_Error::what() const noexcept {
	return this->message.c_str();
}