#include <iostream>
#include <vector>

#include "Matrix.h"
#include "Operations.h"

void program_loop() {
	while (true) {
		//TODO
	}
}

int main()
{
	//Matrix test("2 1 4; 0 1 1");
	//Matrix test("3 4 2");
	Matrix ptr_mtrx("2 1 4; 0 1 1");
	Matrix ptr_mtrx2("4 5 6; 1 2 3");

	Matrix test("6; 1; 4");
	Matrix test2("2; 9; 3");
	Matrix test3("8 1 0; 3 3 1 ; -2 5 0");
	Matrix test4("3 0 2; 2 0 -2; 0 1 1");

	//Matrix test('r', 4);
	//std::cout << test4.to_string() << std::endl;
	std::cout << test4.to_string() << std::endl;
	test4 = invert(test4);
	std::cout << test4.to_string() << std::endl;
}