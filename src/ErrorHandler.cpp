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
		default:
			break;
	}
}

LALIB_Error::~LALIB_Error() noexcept {}

const char* LALIB_Error::what() const noexcept {
	return this->message.c_str();
}