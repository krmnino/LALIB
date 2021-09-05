#include "ErrorHandler.h"

LALIB_Error::LALIB_Error() {
	this->err_code = ErrorCode::OK;
}

LALIB_Error::LALIB_Error(ErrorCode error) {
	this->err_code = error;
}

LALIB_Error::~LALIB_Error() noexcept {}

const char* LALIB_Error::what() const noexcept {
	return this->message.c_str();
}