#ifndef ORTH_H
#define ORTH_H

#include <iostream>
#include "Matrix.h"

Matrix unit_vector(Matrix);
Matrix projection_onto(Matrix, Matrix);
Matrix gram_schmidt(Matrix);

#endif