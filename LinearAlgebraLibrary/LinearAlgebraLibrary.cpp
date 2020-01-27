// LinearAlgebraLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "RREF.h"
#include "REF.h"
#include "Transpose.h"
#include "Determinant.h"

using namespace std;

int main()
{
	Matrix test("1 -1 1 2; 3 -2 1 -1; 1 1 0 -3");
	//Matrix test("9 8 52 65; 213 51 56 7; 4 1 455 6; 84 65 6 12");
	Matrix sol2(ref(test));
	cout << endl;
	cout << test.to_string() << endl;
	cout << "PRINT RETURN" << endl;
	cout << sol2.to_string() << endl;
	//cout << determinant(test) << endl;
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
