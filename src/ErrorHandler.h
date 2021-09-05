#ifndef ERR_LALIB
#define ERR_LALIB

#include <iostream>
#include <exception>
#include <string>

enum class ErrorCode {
	OK,
	NON_SQR_MTRX,
	INV_SNGL_MTRX,
	INCONS_MATRX_DIMS,
	ROW_OUT_BOUNDS,
	COL_OUT_BOUNDS,
};

class LALIB_Error : public std::exception {
protected:
	ErrorCode err_code;
	std::string message;

public:
	explicit LALIB_Error();
	explicit LALIB_Error(ErrorCode);
	virtual ~LALIB_Error() noexcept;
	virtual const char* what() const noexcept;
};

#endif  ERR_LALIB