#ifndef OPS
#define OPS

#include "Matrix.h"

void add(Matrix&, double);
Matrix ref(Matrix&);
Matrix rref(Matrix&);
double determinant(Matrix&);
Matrix multiply(Matrix&, Matrix&);
Matrix unit_vector(Matrix&);
Matrix projection_onto(Matrix&, Matrix&);
Matrix gram_schmidt(Matrix&);

#endif