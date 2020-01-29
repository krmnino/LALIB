// LinearAlgebraLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "RREF.h"
#include "REF.h"
#include "Transpose.h"
#include "Determinant.h"
#include "MatrixMultiplication.h"

using namespace std;

int main()
{
	//Matrix test("2 1 4; 0 1 1");
	//Matrix test2("6 3 -1 0; 1 1 0 4;-2 5 0 2");
	//Matrix test("3 4 2");
	//Matrix test2("13 9 7 15; 8 7 4 6; 6 4 0 3");
	Matrix test("3 -2 4 1 0 0; 1 0 2 0 1 0; 0 1 0 0 0 1");
	cout << test.to_string() << endl;
	Matrix result = rref(test);
	cout << result.to_string() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
