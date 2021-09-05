#ifndef OPS
#define OPS

#include "Matrix.h"
#include "ErrorHandler.h"

Matrix ref(Matrix&);
Matrix rref(Matrix&);
int rank(Matrix&);
double determinant(Matrix&);
bool is_singular(Matrix&);
Matrix multiply(Matrix&, Matrix&);
Matrix unit_vector(Matrix&);
Matrix invert(Matrix&);
Matrix projection_onto(Matrix&, Matrix&);
Matrix gram_schmidt(Matrix&);

#endif