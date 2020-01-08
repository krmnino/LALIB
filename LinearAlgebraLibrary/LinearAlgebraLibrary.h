#ifndef LAL_H
#define LAL_H
#include "Matrix.h"


namespace la_lib {
	Matrix rref(Matrix);
	Matrix transpose(Matrix);
	double determinant(Matrix);
}

#endif LAL_H