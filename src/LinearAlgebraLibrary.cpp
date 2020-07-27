#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>

#include "Matrix.h"
#include "Operations.h"

void program_loop() {
	while (true) {
		//TODO
	}
}

int test(std::initializer_list<Matrix> list) {
	va_list args;
	for (auto mtrx : list) {
		//std::cout << mtrx.to_string() << std::endl;
	}
	return 1;
}

int main()
{
	Matrix a("1;1;4");
	Matrix b("0;1;6");
	Matrix c("0 2 0; 4 56 5; 4 5 6; 1 2 3; 1 2 6");
	Matrix res = projection_onto(a, b);
	test({ a, b, c });

	//Matrix* test = new Matrix("0;1;6");

	std::cout << c;

	std::cout << rank(c) << std::endl;
	//Matrix test("2 1 4; 0 1 1");
	//Matrix test("3 4 2");
	/*
	Matrix ptr_mtrx("2 1 4; 0 1 1");
	Matrix ptr_mtrx2("4 5 6; 1 2 3");

	Matrix test("6; 1; 4");
	Matrix test2("2; 9; 3");
	Matrix test3("8 1 0; 3 3 1 ; -2 5 0");
	Matrix test4("3 0 2; 2 0 -2; 0 1 1");
	Matrix test5 = projection_onto(test3, test4);
	*/
	//Matrix test('r', 4);
	//std::cout << test4.to_string() << std::endl;
	//std::cout << test4.to_string() << std::endl;
	//test4 = invert(test4);
	//std::cout << test5.to_string() << std::endl;
}

