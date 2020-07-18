#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Operations.h"
using namespace std;

void program_loop() {
	while (true) {
		//TODO
	}
}

int main()
{
	//Matrix test("2 1 4; 0 1 1");
	//Matrix test("3 4 2");
	Matrix* ptr_mtrx = new Matrix("2 1 4; 0 1 1");
	Matrix* ptr_mtrx2 = new Matrix("2; 9; 3");

	Matrix test("6; 1; 4");
	Matrix test2("2; 9; 3");
	Matrix test3("6 3 -1 0; 1 1 0 4;-2 5 0 2");
	//Matrix test('r', 4);
	//Matrix* test = new Matrix("13; 9; 7; 15; 23; 6");
	cout << test.to_string() << endl;
	cout << ref(*ptr_mtrx).to_string() << endl;
	cout << rref(*ptr_mtrx).to_string() << endl;
	cout << unit_vector(*ptr_mtrx2).to_string() << endl;
	cout << projection_onto(test, test2).to_string() << endl;
	cout << transpose(*ptr_mtrx).to_string() << endl;
}