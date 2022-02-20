#include <iostream>
#include <vector>
#include <list>
#include <initializer_list>
#include <assert.h>

#include "Matrix.h"
#include "Operations.h"

int test1() {
	// Test: use get_m() on a 4 x 4 matrix
	
	Matrix mtrx('r', 4);
	assert(mtrx.get_m() == 4);
	
	std::cout << ">> Test 1 successful." << std::endl;
	return 0;
}


int test2() {
	// Test: use get_n() on a 4 x 4 matrix

	Matrix mtrx('r', 4);
	assert(mtrx.get_n() == 4);

	std::cout << ">> Test 2 successful." << std::endl;
	return 0;
}


int test3() {
	// Test: use get_matrix() on a 4 x 4 matrix

	Matrix mtrx('r', 4);
	assert(mtrx.get_m() == 4);
	assert(mtrx.get_n() == 4);
	auto ret = mtrx.get_matrix();
	assert(ret.size() == 4);
	for (int i = 0; i < ret.size(); i++) {
		assert(ret[i].size() == 4);
	}

	std::cout << ">> Test 3 successful." << std::endl;
	return 0;
}


int test4() {
	// Test: use is_square() on a 4 x 4 matrix

	Matrix mtrx(5, 5);
	assert(mtrx.is_square());

	std::cout << ">> Test 4 successful." << std::endl;
	return 0;
}


int test5() {
	// Test: use equal() to compare two 3 x 3 equal matrix

	Matrix mtrx1("7 8 9; 4 5 6; 1 2 3");
	Matrix mtrx2("7 8 9; 4 5 6; 1 2 3");
	assert(mtrx1.equal(mtrx2));

	std::cout << ">> Test 5 successful." << std::endl;
	return 0;
}


int test6() {
	// Test: use equal() to compare two 3 x 3 matrix with different contents

	Matrix mtrx1("7 8 9; 4 5 6; 1 2 3");
	Matrix mtrx2('i', 3);
	assert(!mtrx1.equal(mtrx2));

	std::cout << ">> Test 6 successful." << std::endl;
	return 0;
}


int test7() {
	// Test: use equal() to compare a 3 x 1 matrix and 4 x 1 matrix

	Matrix mtrx1("7; 4; 1");
	Matrix mtrx2("1; 2; 3; 4");
	assert(!mtrx1.equal(mtrx2));

	std::cout << ">> Test 7 successful." << std::endl;
	return 0;
}


int test8() {
	// Test: use equal() to compare a 1 x 3 matrix and 1 x 4 matrix

	Matrix mtrx1("7 4 1;");
	Matrix mtrx2("1 2 3 4;");
	assert(!mtrx1.equal(mtrx2));

	std::cout << ">> Test 8 successful." << std::endl;
	return 0;
}


int test9() {
	// Test: use get_single_element() on a 3 x 3 matrix

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
	assert(mtrx.get_single_element(1,1) == 5);

	std::cout << ">> Test 9 successful." << std::endl;
	return 0;
}


int test10() {
	// Test: use get_single_element() -> invalid row index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try{
		auto ret = mtrx.get_single_element(12, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try{
		auto ret = mtrx.get_single_element(-12, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 10 successful." << std::endl;
	return 0;	
}


int test11() {
	// Test: use get_single_element() -> invalid col index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try {
		auto ret = mtrx.get_single_element(1, 12);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}
	
	try {
		auto ret = mtrx.get_single_element(1, -1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 11 successful." << std::endl;
	return 0;
}


int test12() {
	// Test: use set_single_element() on a 3 x 3 matrix

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
	
	mtrx.set_single_element(1, 2, 100.123);

	assert(mtrx.get_single_element(1, 2) == 100.123);

	std::cout << ">> Test 12 successful." << std::endl;
	return 0;
}


int test13() {
	// Test: use set_single_element() on a 3 x 3 matrix

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
	
	mtrx.set_single_element(1, 2, 100.123);
	
	assert(mtrx.get_single_element(1, 2) == 100.123);

	std::cout << ">> Test 13 successful." << std::endl;
	return 0;
}


int main() {
	bool all = true;
	bool t1  = false;
	bool t2  = false;
	bool t3  = false;
	bool t4  = false;
	bool t5  = false;
	bool t6  = false;
	bool t7  = false;
	bool t8  = false;
	bool t9  = false;
	bool t10 = false;
	bool t11 = false;
	bool t12 = false;
	bool t13 = false;

	if(t1 || all){
		test1();
	}
	if(t2 || all){
		test2();
	}
	if(t3 || all){
		test3();
	}
	if(t4 || all){
		test4();
	}
	if(t5 || all){
		test5();
	}
	if(t6 || all){
		test6();
	}
	if(t7 || all){
		test7();
	}
	if(t8 || all){
		test8();
	}
	if(t9 || all){
		test9();
	}
	if(t10 || all){
		test10();
	}
	if(t11 || all){
		test11();
	}
	if(t12 || all){
		test12();
	}
	if(t13 || all){
		test13();
	}

	return 0;
}
/*
	

	

	

	

	

	

	

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

	// Test: use matrix_scale() on a 3 x 3 matrix
	{
		Matrix mtrx("2 2 2; 2 2 2; 2 2 2");
		//std::cout << mtrx << std::endl;
		mtrx.matrix_scale(40);
		//std::cout << mtrx << std::endl;
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				assert(mtrx.get_single_element(i, j) == 80);
			}
		}
	}

	// Test: use transpose() on a 3 x 3 
	{
		Matrix mtrx("2 2 2; 4 4 4; 6 6 6");
		//std::cout << mtrx << std::endl;
		mtrx.transpose();
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_single_element(0, 0) == 2);
		assert(mtrx.get_single_element(0, 1) == 4);
		assert(mtrx.get_single_element(0, 2) == 6);
		assert(mtrx.get_single_element(1, 0) == 2);
		assert(mtrx.get_single_element(1, 1) == 4);
		assert(mtrx.get_single_element(1, 2) == 6);
		assert(mtrx.get_single_element(2, 0) == 2);
		assert(mtrx.get_single_element(2, 1) == 4);
		assert(mtrx.get_single_element(2, 2) == 6);
	}

	// Test: use transpose() on a 5 x 1 
	{
		Matrix mtrx("1; 2; 3; 4; 5");
		//std::cout << mtrx << std::endl;
		mtrx.transpose();
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_single_element(0, 0) == 1);
		assert(mtrx.get_single_element(0, 1) == 2);
		assert(mtrx.get_single_element(0, 2) == 3);
		assert(mtrx.get_single_element(0, 3) == 4);
		assert(mtrx.get_single_element(0, 4) == 5);
	}

	// Test: use transpose() on a 1 x 5 
	{
		Matrix mtrx("1 2 3 4 5;");
		//std::cout << mtrx << std::endl;
		mtrx.transpose();
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_single_element(0, 0) == 1);
		assert(mtrx.get_single_element(1, 0) == 2);
		assert(mtrx.get_single_element(2, 0) == 3);
		assert(mtrx.get_single_element(3, 0) == 4);
		assert(mtrx.get_single_element(4, 0) == 5);
	}

	// Test: use operator+ on two 3 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");
		Matrix ret = mtrx1 + mtrx2;
		//std::cout << ret << std::endl;
		assert(ret.get_m() == 3);
		assert(ret.get_n() == 3);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				assert(ret.get_single_element(i, j) == 10);
			}
		}
	}

	// Test: use operator+ on two 3 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");
		mtrx1 = mtrx1 + mtrx2;
		//std::cout << mtrx1 << std::endl;
		assert(mtrx1.get_m() == 3);
		assert(mtrx1.get_n() == 3);
		for (int i = 0; i < mtrx1.get_m(); i++) {
			for (int j = 0; j < mtrx1.get_n(); j++) {
				assert(mtrx1.get_single_element(i, j) == 10);
			}
		}
	}

	// Test: use operator+ on a 3 x 3 matrix and 1 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1 2 3;");
		//Matrix ret = mtrx1 + mtrx2;
	}

	// Test: use operator+ on a 3 x 3 matrix and 3 x 1 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1; 2; 3;");
		//Matrix ret = mtrx1 + mtrx2;
	}

	// Test: use operator- on two 3 x 3 matrix
	{
		Matrix mtrx1("8 8 8; 10 10 10; 6 6 6");
		Matrix mtrx2("2 2 2; 4 4 4; 0 0 0");
		Matrix ret = mtrx1 - mtrx2;
		//std::cout << ret << std::endl;
		assert(ret.get_m() == 3);
		assert(ret.get_n() == 3);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				assert(ret.get_single_element(i, j) == 6);
			}
		}
	}

	// Test: use operator+ on two 3 x 3 matrix
	{
		Matrix mtrx1("8 8 8; 10 10 10; 6 6 6");
		Matrix mtrx2("2 2 2; 4 4 4; 0 0 0");
		mtrx1 = mtrx1 - mtrx2;
		assert(mtrx1.get_m() == 3);
		assert(mtrx1.get_n() == 3);
		//std::cout << mtrx1 << std::endl;
		for (int i = 0; i < mtrx1.get_m(); i++) {
			for (int j = 0; j < mtrx1.get_n(); j++) {
				assert(mtrx1.get_single_element(i, j) == 6);
			}
		}
	}

	// Test: use operator+ on a 3 x 3 matrix and 1 x 3 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1 2 3;");
		//Matrix ret = mtrx1 - mtrx2;
	}

	// Test: use operator+ on a 3 x 3 matrix and 3 x 1 matrix
	{
		Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
		Matrix mtrx2("1; 2; 3;");
		//Matrix ret = mtrx1 + mtrx2;
	}

	// Test: use operator*(double) on a 3 x 3 matrix and update source matrix
	{
		Matrix mtrx("2 2 2; 2 2 2; 2 2 2");
		//std::cout << mtrx << std::endl;
		mtrx = mtrx * 40;
		//std::cout << mtrx << std::endl;
		assert(mtrx.get_m() == 3);
		assert(mtrx.get_n() == 3);
		for (int i = 0; i < mtrx.get_m(); i++) {
			for (int j = 0; j < mtrx.get_n(); j++) {
				assert(mtrx.get_single_element(i, j) == 80);
			}
		}
	}

	// Test: use operator*(double) on a 3 x 3 matrix and update source matrix
	{
		Matrix mtrx("2 2 2; 2 2 2; 2 2 2");
		//std::cout << mtrx << std::endl;
		Matrix ret = mtrx * 40;
		//std::cout << ret << std::endl;
		assert(ret.get_m() == 3);
		assert(ret.get_n() == 3);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				assert(ret.get_single_element(i, j) == 80);
			}
		}
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

	///////////////////////////////////////////////////////////////////

	// Test: use determinant() on a 2 x 2 matrix -> succeeds
	{
		Matrix mtrx("5 8; 4 5");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == -7);
	}

	// Test: use determinant() on a 4 x 4 matrix -> succeeds
	{
		Matrix mtrx("2 4 1 -3; 7 2 2 -2; 3 3 2 2; 0 5 1 0");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == -35);
	}

	// Test: use determinant() on a 5 x 5 matrix -> succeeds
	{
		Matrix mtrx("8 9 7 8 2; 4 5 9 5 7; 1 3 6 6 8; 4 5 7 4 5; 2 3 6 8 9");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == 213);
	}

	// Test: use determinant() on a 1 x 1 matrix -> succeeds
	{
		Matrix mtrx("5");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == 5);
	}

	// Test: use determinant() on a 0 x 0 matrix -> fails
	{
		Matrix mtrx(0, 0);
		//std::cout << mtrx << std::endl;
		//auto ret = determinant(mtrx);
	}

	// Test: use determinant() on a 3 x 3 singular matrix -> succeeds
	{
		Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == 0);
	}

	// Test: use determinant() on a 5 x 5 singular matrix -> succeeds
	{
		Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
		//std::cout << mtrx << std::endl;
		auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
		assert(ret == 0);
	}

	// Test: use determinant() on a 10 x 10 -> succeeds
	{
		//Matrix mtrx("5 8 52 6 4 1 2 8 6 -9;"
		//	        "1 5 -8 65 8 5 -9 7 45 4;"
		//          "2 21 1 5641 6 5 3 65 2 5;"
		//	        "2 2 65 52 2 35 61 4 35 45;"
		//	        "13 5216 51 52 6 63 87 8 5 4185;"
		//	        "451 235 8 35 9 89 -8 55 52 2;"
		//	        "1 2 5 13 5 5 6 4 3 46;"
		//	        "4 654 3 5 2 1 5 62 3 3;"
		//	        "2 3 55 -98 7 8 4512 2 56 3;"
		//	        "5 2 -5 35 4 53 1 65 3 6");
		//std::cout << mtrx << std::endl;
		//auto ret = determinant(mtrx);
		//std::cout << ret << std::endl;
	}

	// Test: use determinant() on a 1 x 4 -> fails
	{
		Matrix mtrx("1 2 3 4");
		//std::cout << mtrx << std::endl;
		//auto ret = determinant(mtrx);
	}

	// Test: use determinant() on a 4 x 1 -> fails
	{
		Matrix mtrx("1; 2; 3; 4");
		//std::cout << mtrx << std::endl;
		//auto ret = determinant(mtrx);
	}
	
	// Test: use is_singular() on a 3 x 3 -> succeeds
	{
		Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
		//std::cout << mtrx << std::endl;
		assert(is_singular(mtrx));
	}

	// Test: use is_singular() on a 5 x 5 -> succeeds
	{
		Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
		//std::cout << mtrx << std::endl;
		assert(is_singular(mtrx));
	}

	// Test: use is_singular() on a 4 x 4 matrix -> succeeds
	{
		Matrix mtrx("2 4 1 -3; 7 2 2 -2; 3 3 2 2; 0 5 1 0");
		//std::cout << mtrx << std::endl;
		assert(!is_singular(mtrx));
	}

	// Test: use is_singular() on a 5 x 5 matrix -> succeeds
	{
		Matrix mtrx("8 9 7 8 2; 4 5 9 5 7; 1 3 6 6 8; 4 5 7 4 5; 2 3 6 8 9");
		//std::cout << mtrx << std::endl;
		assert(!is_singular(mtrx));
	}

	// Test: use is_singular() on a 2 x 2 matrix -> succeeds
	{
		Matrix mtrx("5 8; 4 5");
		//std::cout << mtrx << std::endl;
		assert(!is_singular(mtrx));
	}

	// Test: use is_singular() on a 1 x 4 -> fails
	{
		Matrix mtrx("1 2 3 4");
		//std::cout << mtrx << std::endl;
		//auto ret = is_singular(mtrx);
	}

	// Test: use is_singular() on a 4 x 1 -> fails
	{
		Matrix mtrx("1; 2; 3; 4");
		//std::cout << mtrx << std::endl;
		//auto ret = is_singular(mtrx);
	}

	///////////////////////////////////////////////////////////////////

	// Test: use invert on a 2 x 2 matrix -> succeeds
	{
		Matrix mtrx("5 8; 4 5");
		//std::cout << mtrx << std::endl;
		auto ret = invert(mtrx);
		Matrix validate(2, 2);
		validate.set_single_element(0, 0, (double)-5 / 7);
		validate.set_single_element(0, 1, (double)8 / 7);
		validate.set_single_element(1, 0, (double)4 / 7);
		validate.set_single_element(1, 1, (double)-5 / 7);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				long long ret_val = ret.get_single_element(i, j) * 1000000000000;
				long long validate_val = validate.get_single_element(i, j) * 1000000000000;
				assert(ret_val == validate_val);
			}
		}
	}

	// Test: use invert on a 3 x 3 matrix -> succeeds
	{
		Matrix mtrx("14 2 54; 49 81 33; 85 15 66");
		auto ret = invert(mtrx);
		//std::cout << ret << std::endl;
		Matrix validate(3, 3);
		validate.set_single_element(0, 0, (double)-1617 / 88348);
		validate.set_single_element(0, 1, (double)-113 / 44174);
		validate.set_single_element(0, 2, (double)359 / 22087);
		validate.set_single_element(1, 0, (double)11 / 6796);
		validate.set_single_element(1, 1, (double)47 / 3398);
		validate.set_single_element(1, 2, (double)-14 / 1699);
		validate.set_single_element(2, 0, (double)1025 / 44174);
		validate.set_single_element(2, 1, (double)10 / 66261);
		validate.set_single_element(2, 2, (double)-259 / 66261);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				long long ret_val = ret.get_single_element(i, j) * 1000000000000;
				long long validate_val = validate.get_single_element(i, j) * 1000000000000;
				assert(ret_val == validate_val);
			}
		}
	}

	// Test: use invert on a 5 x 5 matrix -> succeeds
	{
		Matrix mtrx("8 9 7 8 2; 4 5 9 5 7; 1 3 6 6 8; 4 5 7 4 5; 2 3 6 8 9");
		auto ret = invert(mtrx);
		//std::cout << ret << std::endl;
		Matrix validate(5, 5);
		validate.set_single_element(0, 0, (double)-37 / 213);
		validate.set_single_element(0, 1, (double)-46 / 213);
		validate.set_single_element(0, 2, (double)-217 / 213);
		validate.set_single_element(0, 3, (double)151 / 213);
		validate.set_single_element(0, 4, (double)51 / 71);
		validate.set_single_element(1, 0, (double)1 / 71);
		validate.set_single_element(1, 1, (double)-64 / 71);
		validate.set_single_element(1, 2, (double)50 / 71);
		validate.set_single_element(1, 3, (double)65 / 71);
		validate.set_single_element(1, 4, (double)-31 / 71);
		validate.set_single_element(2, 0, (double)32 / 213);
		validate.set_single_element(2, 1, (double)224 / 213);
		validate.set_single_element(2, 2, (double)38 / 213);
		validate.set_single_element(2, 3, (double)-263 / 213);
		validate.set_single_element(2, 4, (double)-23 / 71);
		validate.set_single_element(3, 0, (double)46 / 213);
		validate.set_single_element(3, 1, (double)109 / 213);
		validate.set_single_element(3, 2, (double)28 / 213);
		validate.set_single_element(3, 3, (double)-205 / 213);
		validate.set_single_element(3, 4, (double)-2 / 71);
		validate.set_single_element(4, 0, (double)-55 / 213);
		validate.set_single_element(4, 1, (double)-172 / 213);
		validate.set_single_element(4, 2, (double)-52 / 213);
		validate.set_single_element(4, 3, (double)259 / 213);
		validate.set_single_element(4, 4, (double)24 / 71);
		for (int i = 0; i < ret.get_m(); i++) {
			for (int j = 0; j < ret.get_n(); j++) {
				long long ret_val = ret.get_single_element(i, j) * 1000000000000;
				long long validate_val = validate.get_single_element(i, j) * 1000000000000;
				assert(ret_val == validate_val);
			}
		}
	}

	// Test: use invert on a 5 x 5 matrix -> succeeds
	{
		Matrix mtrx("5");
		auto ret = invert(mtrx);
		//std::cout << ret << std::endl;
		Matrix validate(1, 1);
		validate.set_single_element(0, 0, (double)1 / 5);
		long long ret_val = ret.get_single_element(0, 0) * 1000000000000;
		long long validate_val = validate.get_single_element(0, 0) * 1000000000000;
		assert(ret_val == validate_val);
	}

	// Test: use invert() on a 0 x 0 matrix -> fails
	{
		Matrix mtrx(0, 0);
		//std::cout << mtrx << std::endl;
		//auto ret = invert(mtrx);
	}

	// Test: use invert() on a 3 x 3 singular matrix -> fails
	{
		Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
		//std::cout << mtrx << std::endl;
		//auto ret = invert(mtrx);
	}

	// Test: use invert() on a 5 x 5 singular matrix -> fails
	{
		Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
		//std::cout << mtrx << std::endl;
		//auto ret = invert(mtrx);
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


