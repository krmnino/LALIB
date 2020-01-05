// LinearAlgebraLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "RREF.h"

using namespace std;

int main()
{
	Matrix test("3 5 8 5; 1 2 3 2");
	Matrix test2(3, 4);
	Matrix copy_matrix(test);
	vector<vector<double>> m = test.get_matrix();
	vector<vector<double>> m2 = test2.get_matrix();
	vector<vector<double>> mc = copy_matrix.get_matrix();
	cout << endl;
	cout << test.to_string() << endl;
	Matrix sol(rref(test));
	cout << endl;
	cout << sol.to_string() << endl;
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
