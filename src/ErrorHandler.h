#ifndef LALIB_ERR_HDLR
#define LALIB_ERR_HDLR

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
	INVALID_DIMS,
	UNEVEN_INPUT_COLS,
	NO_NUMERIC_INPUT,
	INVALID_GEN_OPTION,
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
	ErrorCode get_error_code();
};

#endif
