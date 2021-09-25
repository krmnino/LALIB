#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>
#include <assert.h>

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
	// Test: use get_m() on a 4 x 4 matrix
	{
		Matrix mtrx('r', 4);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 4);
	}

	// Test: use get_n() on a 4 x 4 matrix
	{
		Matrix mtrx('r', 4);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_n() == 4);
	}

	// Test: use get_matrix() on a 4 x 4 matrix
	{
		Matrix mtrx('r', 4);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 4);
		assert(mtrx.get_n() == 4);
		auto ret = mtrx.get_matrix();
		assert(ret.size() == 4);
		for (int i = 0; i < ret.size(); i++) {
			assert(ret[i].size() == 4);
		}
	}

	// Test: use is_square() on a 4 x 4 matrix
	{
		Matrix mtrx(5, 5);
		//std::cout << mtrx << std::endl;
		assert(mtrx.is_square());
	}

	// Test: use equal() to compare two 3 x 3 equal matrix
	{
		Matrix mtrx1("7 8 9; 4 5 6; 1 2 3");
		Matrix mtrx2("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx1 << std::endl;
		//std::cout << mtrx2 << std::endl;
		assert(mtrx1.equal(mtrx2));
	}

	// Test: use equal() to compare two 3 x 3 matrix with different contents
	{
		Matrix mtrx1("7 8 9; 4 5 6; 1 2 3");
		Matrix mtrx2('i', 3);
		//std::cout << mtrx1 << std::endl;
		//std::cout << mtrx2 << std::endl;
		assert(!mtrx1.equal(mtrx2));
	}

	// Test: use equal() to compare a 3 x 1 matrix and 4 x 1 matrix
	{
		Matrix mtrx1("7; 4; 1");
		Matrix mtrx2("1; 2; 3; 4");
		//std::cout << mtrx1 << std::endl;
		//std::cout << mtrx2 << std::endl;
		assert(!mtrx1.equal(mtrx2));
	}

	// Test: use equal() to compare a 1 x 3 matrix and 1 x 4 matrix
	{
		Matrix mtrx1("7 4 1;");
		Matrix mtrx2("1 2 3 4;");
		//std::cout << mtrx1 << std::endl;
		//std::cout << mtrx2 << std::endl;
		assert(!mtrx1.equal(mtrx2));
	}

	// Test: use get_single_element() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_single_element(1,1) == 5);
	}

	// Test: use get_single_element() -> invalid row index
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//auto ret = mtrx.get_single_element(12, 1);
		//auto ret = mtrx.get_single_element(-12, 1);
	}

	// Test: use get_single_element() -> invalid row index
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//auto ret = mtrx.get_single_element(1, 12);
		//auto ret = mtrx.get_single_element(1, -1);
	}

	// Test: use set_single_element() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		mtrx.set_single_element(1, 2, 100.123);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_single_element(1, 2) == 100.123);
	}

	// Test: use set_single_element() -> invalid row index
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//mtrx.set_single_element(12, 1, 123);
		//mtrx.set_single_element(-1, 1, 123);
	}

	// Test: use set_single_element() -> invalid column index
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//mtrx.set_single_element(1, 12, 123);
		//mtrx.set_single_element(1, -1, 123);
	}

	// Test: use get_row() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		auto ret = mtrx.get_row(0);
		assert(ret.get_m() == 1);
		assert(ret.get_n() == 3);
		assert(ret.get_single_element(0, 0) == 7);
		assert(ret.get_single_element(0, 1) == 8);
		assert(ret.get_single_element(0, 2) == 9);
	}

	// Test: use get_row() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//auto ret1 = mtrx.get_row(10);
		//auto ret2 = mtrx.get_row(-1);
	}

	// Test: use get_column() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		auto ret = mtrx.get_column(0);
		assert(ret.get_m() == 3);
		assert(ret.get_n() == 1);
		assert(ret.get_single_element(0, 0) == 7);
		assert(ret.get_single_element(1, 0) == 4);
		assert(ret.get_single_element(2, 0) == 1);
	}

	// Test: use get_column() on a 3 x 3 matrix
	{
		Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
		//std::cout << mtrx << std::endl;
		//auto ret1 = mtrx.get_column(10);
		//auto ret2 = mtrx.get_column(-1);
	}

	// Test: use remove_row() on a 5 x 5 matrix
	{
		Matrix mtrx('r', 5);
		//std::cout << mtrx << std::endl;
		mtrx.remove_row(2);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 4);
		assert(mtrx.get_n() == 5);
	}

	// Test: use remove_row() -> invalid row index
	{
		Matrix mtrx('r', 5);
		//std::cout << mtrx << std::endl;
		//mtrx.remove_row(-2);
		//mtrx.remove_row(8);
	}

	// Test: use remove_column() -> invalid row index
	{
		Matrix mtrx('r', 5);
		//std::cout << mtrx << std::endl;
		mtrx.remove_column(2);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 5);
		assert(mtrx.get_n() == 4);
	}

	// Test: use remove_column() -> invalid row index
	{
		Matrix mtrx('r', 5);
		//std::cout << mtrx << std::endl;
		//mtrx.remove_column(-2);
		//mtrx.remove_column(8);
	}

	// Test: use row_addition() on a 3 x 3 matrix
	{
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		mtrx.row_addition(0, 1);
		//std::cout << mtrx << std::endl;
		for (int i = 0; i < mtrx.get_m(); i++) {
			assert(mtrx.get_single_element(0, i) == 9);
			assert(mtrx.get_single_element(1, i) == 4);
			assert(mtrx.get_single_element(2, i) == 3);
		}
	}

	// Test: use row_addition() -> invalid row index
	{
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		//mtrx.row_addition(0, 5);
		//mtrx.row_addition(0, -5);
		//mtrx.row_addition(5, 1);
		//mtrx.row_addition(-5, 5);
	}

	// Test: use row_scale() on a 3 x 3 matrix with int scalar
	{
		int scalar = 10;
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		mtrx.row_scale(1, scalar);
		//std::cout << mtrx << std::endl;
		for (int i = 0; i < mtrx.get_m(); i++) {
			assert(mtrx.get_single_element(0, i) == 5);
			assert(mtrx.get_single_element(1, i) == 4 * (double)scalar);
			assert(mtrx.get_single_element(2, i) == 3);
		}
	}

	// Test: use row_scale() on a 3 x 3 matrix with double scalar
	{
		double scalar = 0.5;
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		mtrx.row_scale(1, scalar);
		//std::cout << mtrx << std::endl;
		for (int i = 0; i < mtrx.get_m(); i++) {
			assert(mtrx.get_single_element(0, i) == 5);
			assert(mtrx.get_single_element(1, i) == 4 * (double)scalar);
			assert(mtrx.get_single_element(2, i) == 3);
		}
	}

	// Test: use row_scale() -> invalid row index
	{
		int scalar = 10;
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		//mtrx.row_scale(5, scalar);
		//mtrx.row_scale(-5, scalar);
	}

	// Test: use row_swap() on a 5 x 5 matrix
	{
		Matrix mtrx1("5 5 5; 4 4 4; 3 3 3");
		Matrix mtrx2("4 4 4; 5 5 5; 3 3 3");
		//std::cout << mtrx << std::endl;
		mtrx1.row_swap(0, 1);
		//std::cout << mtrx << std::endl;
		assert(mtrx1.equal(mtrx2));
	}

	// Test: use row_swap() -> invalid row index 
	{
		Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
		//std::cout << mtrx << std::endl;
		//mtrx.row_swap(5, 1);
		//mtrx.row_swap(-5, 1);
		//mtrx.row_swap(0, 5);
		//mtrx.row_swap(0, -5);
	}

	// Test: use matrix_addition() on two 3 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");
		//std::cout << mtrx1 << std::endl;
		mtrx1.matrix_addition(mtrx2);
		//std::cout << mtrx1 << std::endl;
		for (int i = 0; i < mtrx1.get_m(); i++) {
			for (int j = 0; j < mtrx1.get_n(); j++) {
				assert(mtrx1.get_single_element(i, j) == 10);
			}
		}
	}

	// Test: use matrix_addition() on a 3 x 3 matrix and 1 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1 2 3;");
		//mtrx1.matrix_addition(mtrx2);
	}

	// Test: use matrix_addition() on a 3 x 3 matrix and 3 x 1 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1; 2; 3;");
		//mtrx1.matrix_addition(mtrx2);
	}

	///////////////////////////////////////////////////////////////////

	// Test: Parse 3 x 1 matrix
	{
		Matrix mtrx("1;2;3");
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 3);
		assert(mtrx.get_n() == 1);
	}

	// Test: Parse 1 x 3 matrix
	{
		Matrix mtrx("1 2 3");
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 1);
		assert(mtrx.get_n() == 3);
	}

	// Test: Parse 1 x 1 matrix
	{
		Matrix mtrx("5");
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 1);
		assert(mtrx.get_n() == 1);
	}

	// Test: Parse 1 x 1 matrix
	{
		Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 3);
		assert(mtrx.get_n() == 3);
	}

	// Test: Generate 4 x 4 zero'd matrix
	{
		Matrix mtrx(4, 4);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 4);
		assert(mtrx.get_n() == 4);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				assert(mtrx.get_single_element(i, j) == 0);
			}
		}
	}

	// Test: Generate 5 x 1 zero'd matrix
	{
		Matrix mtrx(5, 1);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 5);
		assert(mtrx.get_n() == 1);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				assert(mtrx.get_single_element(i, j) == 0);
			}
		}
	}

	// Test: Generate 1 x 1 zero'd matrix
	{
		Matrix mtrx(1, 1);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 1);
		assert(mtrx.get_n() == 1);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				assert(mtrx.get_single_element(i, j) == 0);
			}
		}

	}
	
	// Test: Generate 3 x 3 random matrix
	{
		Matrix mtrx('r', 3);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 3);
		assert(mtrx.get_n() == 3);
	}

	// Test: Generate 3 x 3 identity matrix
	{
		Matrix mtrx('i', 3);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 3);
		assert(mtrx.get_n() == 3);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				if (i == j) {
					assert(mtrx.get_single_element(i, j) == 1);
				}
				else {
					assert(mtrx.get_single_element(i, j) == 0);
				}
			}
		}
	}

	// Test: Generate 10 x 10 identity matrix
	{
		Matrix mtrx('i', 10);
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 10);
		assert(mtrx.get_n() == 10);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				if (i == j) {
					assert(mtrx.get_single_element(i, j) == 1);
				}
				else {
					assert(mtrx.get_single_element(i, j) == 0);
				}
			}
		}
	}

	// Test: Generate undefined matrix
	{
		Matrix mtrx('z', 3);
		std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 0);
		assert(mtrx.get_n() == 0);
	}

	

	
	//Matrix b("0;1;6");
	//Matrix c("0 2 0; 4 56 5; 4 5 6; 1 2 3; 1 2 6");
	//Matrix res = projection_onto(a, b);
	//test({ a, b, c });
	//determinant(a);

	//Matrix* test = new Matrix("0;1;6");

	//std::cout << c;

	//std::cout << rank(c) << std::endl;
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

