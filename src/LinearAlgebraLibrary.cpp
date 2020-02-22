
#include <iostream>
#include <vector>
#include "Matrix.h"
#include "RREF.h"
#include "REF.h"
#include "Transpose.h"
#include "Determinant.h"
#include "MatrixMultiplication.h"
#include "Orthogonalization.h"

using namespace std;

void program_loop() {
	while (true) {
		//TODO
	}
}

int main()
{
	//Matrix test("2 1 4; 0 1 1");
	//Matrix test2("6 3 -1 0; 1 1 0 4;-2 5 0 2");
	//Matrix test("3 4 2");
	Matrix test("13; 9; 7; 15; 23; 7");
	//Matrix test('r', 4);
	//Matrix* test = new Matrix("13; 9; 7; 15; 23; 6");
	cout << test.to_string() << endl;

	cout << orthogonalize_vector(test).to_string() << endl;
}