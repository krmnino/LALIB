#ifndef ERR_LALIB
#define ERR_LALIB

#include <exception>
#include <string>

enum class ErrorCode {
	OK,
	NON_SQR_MTRX,
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