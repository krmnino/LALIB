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
	INCONS_MATRX_COLS,
	INCONS_MATRX_ROWS,
	ROW_OUT_BOUNDS,
	COL_OUT_BOUNDS,
	ROW_COL_NOTEQ,
	NOT_SINGLE_ROW,
	NOT_SINGLE_COL,
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