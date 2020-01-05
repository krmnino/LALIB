// LinearAlgebraLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "RowOperations.h"
#include "RREF.h"

using namespace std;

int main()
{
	Matrix test("3 5 4; 8 2 5");
	Matrix test2(3, 4);
	vector<vector<int>> m = test.get_matrix();
	vector<vector<int>> m2 = test2.get_matrix();
	cout << test.display_as_string() << endl;
	cout << "rows " << test.get_m() << endl;
	cout << "cols " << test.get_n() << endl;
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
