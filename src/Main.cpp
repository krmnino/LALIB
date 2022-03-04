#include <iostream>
#include <vector>
#include <cmath>
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

	try {
		auto ret = mtrx.get_single_element(12, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
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


int test14() {
	// Test: use set_single_element() -> invalid row index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try {
		mtrx.set_single_element(12, 1, 123);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.set_single_element(-1, 1, 123);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 14 successful." << std::endl;
	return 0;
}


int test15() {
	// Test: use set_single_element() -> invalid column index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try {
		mtrx.set_single_element(1, 12, 123);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}
	
	try {
		mtrx.set_single_element(1, -1, 123);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 15 successful." << std::endl;
	return 0;
}


int test16() {
	// Test: use get_row() on a 3 x 3 matrix
	
	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	auto ret = mtrx.get_row(0);
	assert(ret.get_m() == 1);
	assert(ret.get_n() == 3);
	assert(ret.get_single_element(0, 0) == 7);
	assert(ret.get_single_element(0, 1) == 8);
	assert(ret.get_single_element(0, 2) == 9);

	std::cout << ">> Test 16 successful." << std::endl;
	return 0;
}


int test17() {
	// Test: use get_row() on a 3 x 3 matrix -> invalid row index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try {
		auto ret1 = mtrx.get_row(10);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		auto ret2 = mtrx.get_row(-1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 17 successful." << std::endl;
	return 0;
}


int test18() {
	// Test: use get_column() on a 3 x 3 matrix 

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");
	
	auto ret = mtrx.get_column(0);
	assert(ret.get_m() == 3);
	assert(ret.get_n() == 1);
	assert(ret.get_single_element(0, 0) == 7);
	assert(ret.get_single_element(1, 0) == 4);
	assert(ret.get_single_element(2, 0) == 1);

	std::cout << ">> Test 18 successful." << std::endl;
	return 0;
}


int test19() {
	// Test: use get_column() on a 3 x 3 matrix -> invalid column index

	Matrix mtrx("7 8 9; 4 5 6; 1 2 3");

	try {
		auto ret1 = mtrx.get_column(10);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}
	
	try {
		auto ret2 = mtrx.get_column(-1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 19 successful." << std::endl;
	return 0;
}


int test20() {
	// Test: use remove_row() on a 5 x 5 matrix

	Matrix mtrx('r', 5);

	mtrx.remove_row(2);

	assert(mtrx.get_m() == 4);
	assert(mtrx.get_n() == 5);

	std::cout << ">> Test 20 successful." << std::endl;
	return 0;
}


int test21() {
	// Test: use remove_row() -> invalid row index

	Matrix mtrx('r', 5);
	
	try {
		mtrx.remove_row(-2);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.remove_row(8);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 21 successful." << std::endl;
	return 0;
}


int test22() {
	// Test: use remove_column() -> invalid row index

	Matrix mtrx('r', 5);

	mtrx.remove_column(2);

	assert(mtrx.get_m() == 5);
	assert(mtrx.get_n() == 4);

	std::cout << ">> Test 22 successful." << std::endl;
	return 0;
}


int test23() {
	// Test: use remove_column() -> invalid row index

	Matrix mtrx('r', 5);

	try {
		mtrx.remove_column(-2);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}
	
	try {
		mtrx.remove_column(8);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::COL_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Column index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 23 successful." << std::endl;
	return 0;
}


int test24() {
	// Test: use row_addition() on a 3 x 3 matrix

	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");

	mtrx.row_addition(0, 1);

	for (int i = 0; i < mtrx.get_m(); i++) {
		assert(mtrx.get_single_element(0, i) == 9);
		assert(mtrx.get_single_element(1, i) == 4);
		assert(mtrx.get_single_element(2, i) == 3);
	}

	std::cout << ">> Test 24 successful." << std::endl;
	return 0;
}


int test25() {
	// Test: use row_addition() -> invalid row index
	
	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");
	

	try {
		mtrx.row_addition(0, 5);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_addition(0, -5);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_addition(5, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_addition(-5, 5);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}
	
	std::cout << ">> Test 25 successful." << std::endl;
	return 0;
}


int test26() {
	// Test: use row_scale() on a 3 x 3 matrix with int scalar
	

	int scalar = 10;
	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");

	mtrx.row_scale(1, scalar);

	for (int i = 0; i < mtrx.get_m(); i++) {
		assert(mtrx.get_single_element(0, i) == 5);
		assert(mtrx.get_single_element(1, i) == 4 * (double)scalar);
		assert(mtrx.get_single_element(2, i) == 3);
	}

	std::cout << ">> Test 26 successful." << std::endl;
	return 0;
}


int test27() {
	// Test: use row_scale() on a 3 x 3 matrix with double scalar

	double scalar = 0.5;
	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");

	mtrx.row_scale(1, scalar);

	for (int i = 0; i < mtrx.get_m(); i++) {
		assert(mtrx.get_single_element(0, i) == 5);
		assert(mtrx.get_single_element(1, i) == 4 * (double)scalar);
		assert(mtrx.get_single_element(2, i) == 3);
	}

	std::cout << ">> Test 27 successful." << std::endl;
	return 0;
}


int test28() {
	// Test: use row_scale() -> invalid row index

	int scalar = 10;
	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");

	try {
		mtrx.row_scale(5, scalar);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_scale(-5, scalar);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 28 successful." << std::endl;
	return 0;
}

int test29() {
	// Test: use row_swap() on a 5 x 5 matrix

	Matrix mtrx1("5 5 5; 4 4 4; 3 3 3");
	Matrix mtrx2("4 4 4; 5 5 5; 3 3 3");

	mtrx1.row_swap(0, 1);

	assert(mtrx1.equal(mtrx2));

	std::cout << ">> Test 29 successful." << std::endl;
	return 0;
}

int test30() {
	// Test: use row_swap() -> invalid row index 

	Matrix mtrx("5 5 5; 4 4 4; 3 3 3");

	try {
		mtrx.row_swap(5, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_swap(-5, 1);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_swap(0, 5);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	try {
		mtrx.row_swap(0, -5);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::ROW_OUT_BOUNDS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Row index of evaluated matrix is out of bounds.");
	}

	std::cout << ">> Test 30 successful." << std::endl;
	return 0;
}


int test31() {
	// Test: use matrix_addition() on two 3 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");

	mtrx1.matrix_addition(mtrx2);

	for (int i = 0; i < mtrx1.get_m(); i++) {
		for (int j = 0; j < mtrx1.get_n(); j++) {
			assert(mtrx1.get_single_element(i, j) == 10);
		}
	}

	std::cout << ">> Test 31 successful." << std::endl;
	return 0;
}


int test32() {
	// Test: use matrix_addition() on a 3 x 3 matrix and 1 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1 2 3;");
	
	try {
		mtrx1.matrix_addition(mtrx2);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_ROWS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The row count is not consistent between both matrices.");
	}

	std::cout << ">> Test 32 successful." << std::endl;
	return 0;
}

int test33() {
	// Test: use matrix_addition() on a 3 x 3 matrix and 3 x 1 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1; 2; 3;");

	try {
		mtrx1.matrix_addition(mtrx2);
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}

	std::cout << ">> Test 33 successful." << std::endl;
	return 0;
}


int test34() {
	// Test: use matrix_scale() on a 3 x 3 matrix

	Matrix mtrx("2 2 2; 2 2 2; 2 2 2");
 
 	mtrx.matrix_scale(40);

	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 80);
		}
	}

	std::cout << ">> Test 34 successful." << std::endl;
	return 0;
}


int test35() {
	// Test: use transpose() on a 3 x 3 

	Matrix mtrx("2 2 2; 4 4 4; 6 6 6");

	mtrx.transpose();

	assert(mtrx.get_single_element(0, 0) == 2);
	assert(mtrx.get_single_element(0, 1) == 4);
	assert(mtrx.get_single_element(0, 2) == 6);
	assert(mtrx.get_single_element(1, 0) == 2);
	assert(mtrx.get_single_element(1, 1) == 4);
	assert(mtrx.get_single_element(1, 2) == 6);
	assert(mtrx.get_single_element(2, 0) == 2);
	assert(mtrx.get_single_element(2, 1) == 4);
	assert(mtrx.get_single_element(2, 2) == 6);

	std::cout << ">> Test 35 successful." << std::endl;
	return 0;
}


int test36() {
	// Test: use transpose() on a 5 x 1 

	Matrix mtrx("1; 2; 3; 4; 5");

	mtrx.transpose();

	assert(mtrx.get_single_element(0, 0) == 1);
	assert(mtrx.get_single_element(0, 1) == 2);
	assert(mtrx.get_single_element(0, 2) == 3);
	assert(mtrx.get_single_element(0, 3) == 4);
	assert(mtrx.get_single_element(0, 4) == 5);

	std::cout << ">> Test 36 successful." << std::endl;
	return 0;
}


int test37() {
	// Test: use transpose() on a 1 x 5 
	
	Matrix mtrx("1 2 3 4 5;");

	mtrx.transpose();

	assert(mtrx.get_single_element(0, 0) == 1);
	assert(mtrx.get_single_element(1, 0) == 2);
	assert(mtrx.get_single_element(2, 0) == 3);
	assert(mtrx.get_single_element(3, 0) == 4);
	assert(mtrx.get_single_element(4, 0) == 5);

	std::cout << ">> Test 37 successful." << std::endl;
	return 0;
}


int test38() {
	// Test: use operator+ on two 3 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");
	Matrix ret = mtrx1 + mtrx2;

	assert(ret.get_m() == 3);
	assert(ret.get_n() == 3);
	for (int i = 0; i < ret.get_m(); i++) {
		for (int j = 0; j < ret.get_n(); j++) {
			assert(ret.get_single_element(i, j) == 10);
		}
	}

	std::cout << ">> Test 38 successful." << std::endl;
	return 0;
}


int test39() {
	// Test: use operator+ on two 3 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("8 8 8; 6 6 6; 4 4 4");
	mtrx1 = mtrx1 + mtrx2;

	assert(mtrx1.get_m() == 3);
	assert(mtrx1.get_n() == 3);
	for (int i = 0; i < mtrx1.get_m(); i++) {
		for (int j = 0; j < mtrx1.get_n(); j++) {
			assert(mtrx1.get_single_element(i, j) == 10);
		}
	}

	std::cout << ">> Test 39 successful." << std::endl;
	return 0;
}


int test40() {
	// Test: use operator+ on a 3 x 3 matrix and 1 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1 2 3;");
	
	try {
		Matrix ret = mtrx1 + mtrx2;
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_ROWS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The row count is not consistent between both matrices.");
	}

	std::cout << ">> Test 40 successful." << std::endl;
	return 0;
}


int test41() {
	// Test: use operator+ on a 3 x 3 matrix and 3 x 1 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1; 2; 3;");

	try {
		Matrix ret = mtrx1 + mtrx2;
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}

	std::cout << ">> Test 41 successful." << std::endl;
	return 0;
}


int test42() {
	// Test: use operator- on two 3 x 3 matrix

	Matrix mtrx1("8 8 8; 10 10 10; 6 6 6");
	Matrix mtrx2("2 2 2; 4 4 4; 0 0 0");
	Matrix ret = mtrx1 - mtrx2;

	assert(ret.get_m() == 3);
	assert(ret.get_n() == 3);
	for (int i = 0; i < ret.get_m(); i++) {
		for (int j = 0; j < ret.get_n(); j++) {
			assert(ret.get_single_element(i, j) == 6);
		}
	}

	std::cout << ">> Test 42 successful." << std::endl;
	return 0;
}


int test43() {
	// Test: use operator- on two 3 x 3 matrix

	Matrix mtrx1("8 8 8; 10 10 10; 6 6 6");
	Matrix mtrx2("2 2 2; 4 4 4; 0 0 0");
	mtrx1 = mtrx1 - mtrx2;

	assert(mtrx1.get_m() == 3);
	assert(mtrx1.get_n() == 3);
	for (int i = 0; i < mtrx1.get_m(); i++) {
		for (int j = 0; j < mtrx1.get_n(); j++) {
			assert(mtrx1.get_single_element(i, j) == 6);
		}
	}

	std::cout << ">> Test 43 successful." << std::endl;
	return 0;
}


int test44() {
	// Test: use operator- on a 3 x 3 matrix and 1 x 3 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1 2 3;");
	
	try {
		Matrix ret = mtrx1 - mtrx2;
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_ROWS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The row count is not consistent between both matrices.");
	}

	std::cout << ">> Test 44 successful." << std::endl;
	return 0;
}


int test45() {
	// Test: use operator- on a 3 x 3 matrix and 3 x 1 matrix

	Matrix mtrx1("2 2 2; 4 4 4; 6 6 6");
	Matrix mtrx2("1; 2; 3;");

	try {
		Matrix ret = mtrx1 + mtrx2;
	}
	catch (LALIB_Error ex) {
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}

	std::cout << ">> Test 45 successful." << std::endl;
	return 0;
}


int test46() {
	// Test: use operator*(double) on a 3 x 3 matrix and update source matrix

	Matrix mtrx("2 2 2; 2 2 2; 2 2 2");
	
	mtrx = mtrx * 40;
	
	assert(mtrx.get_m() == 3);
	assert(mtrx.get_n() == 3);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 80);
		}
	}

	std::cout << ">> Test 46 successful." << std::endl;
	return 0;
}


int test47() {
	// Test: use operator*(double) on a 3 x 3 matrix and store result in new matrix

	Matrix mtrx("2 2 2; 2 2 2; 2 2 2");

	Matrix ret = mtrx * 40;

	assert(ret.get_m() == 3);
	assert(ret.get_n() == 3);
	for (int i = 0; i < ret.get_m(); i++) {
		for (int j = 0; j < ret.get_n(); j++) {
			assert(ret.get_single_element(i, j) == 80);
		}
	}

	std::cout << ">> Test 47 successful." << std::endl;
	return 0;
}


int test48() {
	// Test: Parse 3 x 1 matrix

	Matrix mtrx("1;2;3");
	assert(mtrx.get_m() == 3);
	assert(mtrx.get_n() == 1);

	std::cout << ">> Test 48 successful." << std::endl;
	return 0;
}


int test49() {
	// Test: Parse 1 x 3 matrix

	Matrix mtrx("1 2 3");
	assert(mtrx.get_m() == 1);
	assert(mtrx.get_n() == 3);

	std::cout << ">> Test 49 successful." << std::endl;
	return 0;
}


int test50() {
	// Test: Parse 1 x 1 matrix

	Matrix mtrx("5");
	assert(mtrx.get_m() == 1);
	assert(mtrx.get_n() == 1);

	std::cout << ">> Test 50 successful." << std::endl;
	return 0;
}


int test51() {
	// Test: Parse 1 x 1 matrix

	Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
	assert(mtrx.get_m() == 3);
	assert(mtrx.get_n() == 3);

	std::cout << ">> Test 51 successful." << std::endl;
	return 0;
}


int test52() {
	// Test: Generate 4 x 4 zero'd matrix

	Matrix mtrx(4, 4);

	assert(mtrx.get_m() == 4);
	assert(mtrx.get_n() == 4);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 0);
		}
	}

	std::cout << ">> Test 52 successful." << std::endl;
	return 0;
}


int test53() {
	// Test: Generate 5 x 1 zero'd matrix

	Matrix mtrx(5, 1);

	assert(mtrx.get_m() == 5);
	assert(mtrx.get_n() == 1);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 0);
		}
	}

	std::cout << ">> Test 53 successful." << std::endl;
	return 0;
}


int test54() {
	// Test: Generate 1 x 1 zero'd matrix

	Matrix mtrx(1, 1);

	assert(mtrx.get_m() == 1);
	assert(mtrx.get_n() == 1);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 0);
		}
	}

	std::cout << ">> Test 54 successful." << std::endl;
	return 0;
}


int test55() {
	// Test: Generate 3 x 3 random matrix

	Matrix mtrx('r', 3);

	assert(mtrx.get_m() == 3);
	assert(mtrx.get_n() == 3);

	std::cout << ">> Test 55 successful." << std::endl;
	return 0;
}


int test56() {
	// Test: Generate 3 x 3 identity matrix

	Matrix mtrx('i', 3);

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

	std::cout << ">> Test 56 successful." << std::endl;
	return 0;
}


int test57() {
	// Test: Generate 10 x 10 identity matrix

	Matrix mtrx('i', 10);

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

	std::cout << ">> Test 57 successful." << std::endl;
	return 0;
}

// Test: Attempt generating matrix with unsupported flag
int test58() {
	try {
		Matrix mtrx('h', 3);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_GEN_OPTION);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Unsupported generation option passed to constructor.");
	}

	std::cout << ">> Test 58 successful." << std::endl;
	return 0;
}


int test59() {
	// Test: Generate 3 x 3 zero matrix

	Matrix mtrx('z', 3);

	assert(mtrx.get_m() == 3);
	assert(mtrx.get_n() == 3);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 0);
		}
	}

	std::cout << ">> Test 59 successful." << std::endl;
	return 0;
}


int test60() {
	// Test: Generate 12 x 12 zero matrix

	Matrix mtrx('z', 12);

	assert(mtrx.get_m() == 12);
	assert(mtrx.get_n() == 12);
	for (int i = 0; i < mtrx.get_m(); i++) {
		for (int j = 0; j < mtrx.get_n(); j++) {
			assert(mtrx.get_single_element(i, j) == 0);
		}
	}

	std::cout << ">> Test 60 successful." << std::endl;
	return 0;
}


int test61() {
	// Test: use determinant() on a 2 x 2 matrix -> succeeds

	Matrix mtrx("5 8; 4 5");
	
	auto ret = determinant(mtrx);
	
	assert(ret == -7);

	std::cout << ">> Test 61 successful." << std::endl;
	return 0;
}


int test62() {
	// Test: use determinant() on a 4 x 4 matrix -> succeeds

	Matrix mtrx("2 4 1 -3; 7 2 2 -2; 3 3 2 2; 0 5 1 0");

	auto ret = determinant(mtrx);

	assert(ret == -35);

	std::cout << ">> Test 62 successful." << std::endl;
	return 0;
}


int test63() {
	// Test: use determinant() on a 5 x 5 matrix -> succeeds

	Matrix mtrx("8 9 7 8 2; 4 5 9 5 7; 1 3 6 6 8; 4 5 7 4 5; 2 3 6 8 9");

	auto ret = determinant(mtrx);

	assert(ret == 213);

	std::cout << ">> Test 63 successful." << std::endl;
	return 0;
}


int test64() {
	// Test: use determinant() on a 1 x 1 matrix -> succeeds

	Matrix mtrx("5");

	auto ret = determinant(mtrx);

	assert(ret == 5);

	std::cout << ">> Test 64 successful." << std::endl;
	return 0;
}


int test65() {
	// Test: use determinant() on a 0 x 0 matrix -> fails

	Matrix mtrx(0, 0);
	
	try {
		auto ret = determinant(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 0.");
	}

	std::cout << ">> Test 65 successful." << std::endl;
	return 0;
}


int test66() {
	// Test: use determinant() on a 3 x 3 singular matrix -> succeeds

	Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
	
	auto ret = determinant(mtrx);
	
	assert(ret == 0);

	std::cout << ">> Test 66 successful." << std::endl;
	return 0;
}


int test67() {
	// Test: use determinant() on a 5 x 5 singular matrix -> succeeds
	
	Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
	
	auto ret = determinant(mtrx);
	
	assert(ret == 0);

	std::cout << ">> Test 67 successful." << std::endl;
	return 0;
}


int test68() {
	// Test: use determinant() on a 10 x 10 -> succeeds
	Matrix mtrx("5 8 52 6 4 1 2 8 6 -9;"
		        "1 5 -8 65 8 5 -9 7 45 4;"
	            "2 21 1 5641 6 5 3 65 2 5;"
		        "2 2 65 52 2 35 61 4 35 45;"
		        "13 5216 51 52 6 63 87 8 5 4185;"
		        "451 235 8 35 9 89 -8 55 52 2;"
		        "1 2 5 13 5 5 6 4 3 46;"
		        "4 654 3 5 2 1 5 62 3 3;"
		        "2 3 55 -98 7 8 4512 2 56 3;"
		        "5 2 -5 35 4 53 1 65 3 6");
	
	auto ret = determinant(mtrx);
	
	std::cout << ">> Test 68 successful." << std::endl;
	return 0;
}


int test69() {
	// Test: use determinant() on a 1 x 4 -> fails

	Matrix mtrx("1 2 3 4");

	try {
		auto ret = determinant(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 69 successful." << std::endl;
	return 0;
}


int test70() {
	// Test: use determinant() on a 4 x 1 -> fails

	Matrix mtrx("1; 2; 3; 4");

	try {
		auto ret = determinant(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 70 successful." << std::endl;
	return 0;
}


int test71() {
	// Test: use is_singular() on a 3 x 3 -> succeeds

	Matrix mtrx("1 2 3; 4 5 6; 7 8 9");

	assert(is_singular(mtrx));

	std::cout << ">> Test 71 successful." << std::endl;
	return 0;
}


int test72() {
	// Test: use is_singular() on a 5 x 5 -> succeeds

	Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
	
	assert(is_singular(mtrx));

	std::cout << ">> Test 72 successful." << std::endl;
	return 0;
}


int test73() {
	// Test: use is_singular() on a 4 x 4 matrix -> succeeds

	Matrix mtrx("2 4 1 -3; 7 2 2 -2; 3 3 2 2; 0 5 1 0");
	
	assert(!is_singular(mtrx));

	std::cout << ">> Test 73 successful." << std::endl;
	return 0;
}


int test74(){
	// Test: use is_singular() on a 5 x 5 matrix -> succeeds

	Matrix mtrx("8 9 7 8 2; 4 5 9 5 7; 1 3 6 6 8; 4 5 7 4 5; 2 3 6 8 9");
	
	assert(!is_singular(mtrx));

	std::cout << ">> Test 74 successful." << std::endl;
	return 0;
}


int test75() {
	// Test: use is_singular() on a 2 x 2 matrix -> succeeds

	Matrix mtrx("5 8; 4 5");
	
	assert(!is_singular(mtrx));

	std::cout << ">> Test 75 successful." << std::endl;
	return 0;
}


int test76() {
	// Test: use is_singular() on a 1 x 4 -> fails

	Matrix mtrx("1 2 3 4");
	
	try {
		auto ret = is_singular(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 76 successful." << std::endl;
	return 0;
}


int test77() {
	// Test: use is_singular() on a 4 x 1 -> fails

	Matrix mtrx("1; 2; 3; 4");
	
	try {
		auto ret = is_singular(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 77 successful." << std::endl;
	return 0;
}


int test78() {
	// Test: use invert on a 2 x 2 matrix -> succeeds

	Matrix mtrx("5 8; 4 5");
	
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

	std::cout << ">> Test 78 successful." << std::endl;
	return 0;
}


int test79() {
	// Test: use invert on a 3 x 3 matrix -> succeeds

	Matrix mtrx("14 2 54; 49 81 33; 85 15 66");
	auto ret = invert(mtrx);

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

	std::cout << ">> Test 79 successful." << std::endl;
	return 0;
}


int test80() {
	// Test: use invert on a 5 x 5 matrix -> succeeds

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

	std::cout << ">> Test 80 successful." << std::endl;
	return 0;
}

int test81() {
	// Test: use invert on a 5 x 5 matrix -> succeeds

	Matrix mtrx("5");
	auto ret = invert(mtrx);
	
	Matrix validate(1, 1);
	validate.set_single_element(0, 0, (double)1 / 5);
	long long ret_val = ret.get_single_element(0, 0) * 1000000000000;
	long long validate_val = validate.get_single_element(0, 0) * 1000000000000;

	assert(ret_val == validate_val);

	std::cout << ">> Test 81 successful." << std::endl;
	return 0;
}


int test82() {
	// Test: use invert() on a 0 x 0 matrix -> fails

	Matrix mtrx(0, 0);
	
	try {
		auto ret = invert(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 0.");
	}

	std::cout << ">> Test 82 successful." << std::endl;
	return 0;
}


int test83() {
	// Test: use invert() on a 3 x 3 singular matrix -> fails

	Matrix mtrx("1 2 3; 4 5 6; 7 8 9");
	
	try {
		auto ret = invert(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INV_SNGL_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Cannot compute inverse of a singular matrix.");
	}

	std::cout << ">> Test 83 successful." << std::endl;
	return 0;
}


int test84() {
	// Test: use invert() on a 5 x 5 singular matrix -> fails

	Matrix mtrx("1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25");
	
	try {
		auto ret = invert(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INV_SNGL_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Cannot compute inverse of a singular matrix.");
	}

	std::cout << ">> Test 84 successful." << std::endl;
	return 0;
}

int test85() {
	// Test: use multiply() with two 3x3 matrices

	Matrix mtrx1("9 6 6; 2 55 3; -4 56 8;");
	Matrix mtrx2("8 85 5; 8 3 -56; 1 1 3;");

	auto ret = multiply(mtrx1, mtrx2);
	
	Matrix res(3, 3);
	res.set_single_element(0, 0, 126);
	res.set_single_element(0, 1, 789);
	res.set_single_element(0, 2, -273);
	res.set_single_element(1, 0, 459);
	res.set_single_element(1, 1, 338);
	res.set_single_element(1, 2, -3061);
	res.set_single_element(2, 0, 424);
	res.set_single_element(2, 1, -164);
	res.set_single_element(2, 2, -3132);
	for (int i = 0; i < res.get_m(); i++) {
		for (int j = 0; j < res.get_n(); j++) {
			assert(res.get_single_element(i, j) == ret.get_single_element(i, j));
		}
	}

	std::cout << ">> Test 85 successful." << std::endl;
	return 0;
}


int test86() {
	// Test: use multiply() with two 5x5 matrices

	Matrix mtrx1("9 5 5 6 5; 41 1 3 35 45; 5 63 1 6 85; 6 87 86 6 8; 46 534 6 584 6;");
	Matrix mtrx2("89 56 65 99 12; 2 32 54 31 35; 13 5 35 4635 4; 2 8 68 8 63; 4 68 4 346 5;");

	auto ret = multiply(mtrx1, mtrx2);
	
	Matrix res(5, 5);
	res.set_single_element(0, 0, 908);
	res.set_single_element(0, 1, 1077);
	res.set_single_element(0, 2, 1458);
	res.set_single_element(0, 3, 25999);
	res.set_single_element(0, 4, 706);
	res.set_single_element(1, 0, 3940);
	res.set_single_element(1, 1, 5683);
	res.set_single_element(1, 2, 5384);
	res.set_single_element(1, 3, 33845);
	res.set_single_element(1, 4, 2969);
	res.set_single_element(2, 0, 936);
	res.set_single_element(2, 1, 8129);
	res.set_single_element(2, 2, 4510);
	res.set_single_element(2, 3, 36541);
	res.set_single_element(2, 4, 3072);
	res.set_single_element(3, 0, 1870);
	res.set_single_element(3, 1, 4142);
	res.set_single_element(3, 2, 8538);
	res.set_single_element(3, 3, 404717);
	res.set_single_element(3, 4, 3879);
	res.set_single_element(4, 0, 6432);
	res.set_single_element(4, 1, 24774);
	res.set_single_element(4, 2, 71772);
	res.set_single_element(4, 3, 55666);
	res.set_single_element(4, 4, 56088);

	for (int i = 0; i < res.get_m(); i++) {
		for (int j = 0; j < res.get_n(); j++) {
			assert(res.get_single_element(i, j) == ret.get_single_element(i, j));
		}
	}

	std::cout << ">> Test 86 successful." << std::endl;
	return 0;
}



int test87() {
	// Test: use multiply() with two 1x1 matrices
	
	Matrix mtrx1("5");
	Matrix mtrx2("9");

	auto ret = multiply(mtrx1, mtrx2);
	
	Matrix res(3, 3);
	res.set_single_element(0, 0, 45);
	assert(res.get_single_element(0, 0) == ret.get_single_element(0, 0));
	
	std::cout << ">> Test 87 successful." << std::endl;
	return 0;
}


int test88() {
	// Test: use multiply() with two 0x0 matrices -> fails
	
	Matrix mtrx1(0, 0);
	Matrix mtrx2(0, 0);

	try {
		auto ret = multiply(mtrx1, mtrx2);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 0.");
	}
	
	std::cout << ">> Test 88 successful." << std::endl;
	return 0;
}


int test89() {
	// Test: use multiply() with two 3x1 and 1x3 matrices

	Matrix mtrx1("1; 2; 3;");
	Matrix mtrx2("4 5 6;");

	auto ret = multiply(mtrx1, mtrx2);
	
	Matrix res(3, 3);
	res.set_single_element(0, 0, 4);
	res.set_single_element(0, 1, 5);
	res.set_single_element(0, 2, 6);
	res.set_single_element(1, 0, 8);
	res.set_single_element(1, 1, 10);
	res.set_single_element(1, 2, 12);
	res.set_single_element(2, 0, 12);
	res.set_single_element(2, 1, 15);
	res.set_single_element(2, 2, 18);
	for (int i = 0; i < res.get_m(); i++) {
		for (int j = 0; j < res.get_n(); j++) {
			assert(res.get_single_element(i, j) == ret.get_single_element(i, j));
		}
	}

	std::cout << ">> Test 89 successful." << std::endl;
	return 0;
}


int test90() {
	// Test: use multiply() with two 2x4 and 4x1 matrices

	Matrix mtrx1("5 6 8 32; 52 6 86 9;");
	Matrix mtrx2("1; 12; 47; 2;");

	auto ret = multiply(mtrx1, mtrx2);
	
	Matrix res(2, 1);
	res.set_single_element(0, 0, 517);
	res.set_single_element(1, 0, 4184);
	for (int i = 0; i < res.get_m(); i++) {
		for (int j = 0; j < res.get_n(); j++) {
			assert(res.get_single_element(i, j) == ret.get_single_element(i, j));
		}
	}

	std::cout << ">> Test 90 successful." << std::endl;
	return 0;
}


int test91() {
	// Test: use multiply() with 3x3 and 2x2 matrices -> fails
	
	Matrix mtrx1('r', 3);
	Matrix mtrx2('r', 2);

	try {
		auto ret = multiply(mtrx1, mtrx2);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::ROW_COL_NOTEQ);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: M and N dimensions do not match between evaluated matrices.");
	}
	
	std::cout << ">> Test 91 successful." << std::endl;
	return 0;
}


int test92() {
	// Test: use of unit_vector with 1x5 matrix

	Matrix mtrx("4 53 3 23 2;");
	
	auto ret = unit_vector(mtrx);

	double v_length = pow(4, 2) + pow(53, 2) + pow(3, 2) + pow(23, 2) + pow(2, 2);
	v_length = sqrt(v_length);
	
	assert(ret.get_single_element(0, 0) == 4 / v_length);
	assert(ret.get_single_element(0, 1) == 53 / v_length);
	assert(ret.get_single_element(0, 2) == 3 / v_length);
	assert(ret.get_single_element(0, 3) == 23 / v_length);
	assert(ret.get_single_element(0, 4) == 2 / v_length);

	std::cout << ">> Test 92 successful." << std::endl;
	return 0;
}


int test93() {
	// Test: use of unit_vector with 1x10 matrix

	Matrix mtrx("1 2 3 4 5 6 7 8 9 10;");
	
	auto ret = unit_vector(mtrx);

	double v_length = pow(1, 2) + pow(2, 2) + pow(3, 2) + pow(4, 2) + pow(5, 2) +
					  pow(6, 2) + pow(7, 2) + pow(8, 2) + pow(9, 2) + pow(10, 2);
	v_length = sqrt(v_length);
	
	assert(ret.get_single_element(0, 0) == 1 / v_length);
	assert(ret.get_single_element(0, 1) == 2 / v_length);
	assert(ret.get_single_element(0, 2) == 3 / v_length);
	assert(ret.get_single_element(0, 3) == 4 / v_length);
	assert(ret.get_single_element(0, 4) == 5 / v_length);
	assert(ret.get_single_element(0, 5) == 6 / v_length);
	assert(ret.get_single_element(0, 6) == 7 / v_length);
	assert(ret.get_single_element(0, 7) == 8 / v_length);
	assert(ret.get_single_element(0, 8) == 9 / v_length);
	assert(ret.get_single_element(0, 9) == 10 / v_length);

	std::cout << ">> Test 93 successful." << std::endl;
	return 0;
}


int test94() {
	// Test: use of unit_vector with 5x1 matrix then transpose

	Matrix mtrx("4; 53; 3; 23; 2;");
	
	mtrx.transpose();
	auto ret = unit_vector(mtrx);

	double v_length = pow(4, 2) + pow(53, 2) + pow(3, 2) + pow(23, 2) + pow(2, 2);
	v_length = sqrt(v_length);
	
	assert(ret.get_single_element(0, 0) == 4 / v_length);
	assert(ret.get_single_element(0, 1) == 53 / v_length);
	assert(ret.get_single_element(0, 2) == 3 / v_length);
	assert(ret.get_single_element(0, 3) == 23 / v_length);
	assert(ret.get_single_element(0, 4) == 2 / v_length);

	std::cout << ">> Test 94 successful." << std::endl;
	return 0;
}


int test95() {
	// Test: use of unit_vector with 5x1 matrix then transpose -> fails

	Matrix mtrx("4; 53; 3; 23; 2;");
	
	try {
		auto ret = unit_vector(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NOT_SINGLE_ROW);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The number of rows in evauluated matrix must be 1.");
	}

	std::cout << ">> Test 95 successful." << std::endl;
	return 0;
}


int test96() {
	// Test: use of unit_vector with 5x5 matrix then transpose -> fails

	Matrix mtrx("9 5 5 6 5; 41 1 3 35 45; 5 63 1 6 85; 6 87 86 6 8; 46 534 6 584 6;");
	
	try {
		auto ret = unit_vector(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NOT_SINGLE_ROW);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The number of rows in evauluated matrix must be 1.");
	}

	std::cout << ">> Test 96 successful." << std::endl;
	return 0;
}


int test97() {
	// Test: use of projection_onto with two 1x3 matrices

	Matrix vect("8 5 45;");
	Matrix onto("9 65 4;");
	
	auto ret = projection_onto(onto, vect);

	double proj = dot_product(onto, vect);
	double onto_length = pow(onto.get_single_element(0, 0), 2) +
						 pow(onto.get_single_element(0, 1), 2) +
						 pow(onto.get_single_element(0, 2), 2);
	proj = proj / onto_length;

	assert(ret.get_single_element(0, 0) == onto.get_single_element(0, 0) * proj);
	assert(ret.get_single_element(0, 1) == onto.get_single_element(0, 1) * proj);
	assert(ret.get_single_element(0, 2) == onto.get_single_element(0, 2) * proj);
	
	std::cout << ">> Test 97 successful." << std::endl;
	return 0;
}


int test98() {
	// Test: use of projection_onto with two 1x5 matrices

	Matrix vect("985 6 211 3 55;");
	Matrix onto("98 5 585 6 41;");
	
	auto ret = projection_onto(onto, vect);

	double proj = dot_product(onto, vect);
	double onto_length = pow(onto.get_single_element(0, 0), 2) +
						 pow(onto.get_single_element(0, 1), 2) +
						 pow(onto.get_single_element(0, 2), 2) +
						 pow(onto.get_single_element(0, 3), 2) +
						 pow(onto.get_single_element(0, 4), 2);
	proj = proj / onto_length;

	assert(ret.get_single_element(0, 0) == onto.get_single_element(0, 0) * proj);
	assert(ret.get_single_element(0, 1) == onto.get_single_element(0, 1) * proj);
	assert(ret.get_single_element(0, 2) == onto.get_single_element(0, 2) * proj);
	assert(ret.get_single_element(0, 3) == onto.get_single_element(0, 3) * proj);
	assert(ret.get_single_element(0, 4) == onto.get_single_element(0, 4) * proj);
	
	std::cout << ">> Test 98 successful." << std::endl;
	return 0;
}


int test99() {
	// Test: use of projection_onto two 2x3 and 1x3 matrices -> fails

	Matrix vect("8 5 45; 8 5 45;");
	Matrix onto("9 65 4;");

	try {
		auto ret = projection_onto(onto, vect);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NOT_SINGLE_ROW);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The number of rows in evauluated matrix must be 1.");
	}
	
	std::cout << ">> Test 99 successful." << std::endl;
	return 0;
}


int test100() {
	// Test: use of projection_onto two 1x3 and 2x3 matrices -> fails

	Matrix vect("8 5 45;");
	Matrix onto("9 65 4; 9 65 4;");

	try {
		auto ret = projection_onto(onto, vect);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NOT_SINGLE_ROW);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The number of rows in evauluated matrix must be 1.");
	}
	
	std::cout << ">> Test 100 successful." << std::endl;
	return 0;
}


int test101() {
	// Test: use of projection_onto two 1x4 and 1x3 matrices -> fails

	Matrix vect("8 5 45 85;");
	Matrix onto("9 65 4;");

	try {
		auto ret = projection_onto(onto, vect);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}
	
	std::cout << ">> Test 101 successful." << std::endl;
	return 0;
}


int test102() {
	// Test: use of projection_onto two 1x3 and 1x4 matrices -> fails

	Matrix vect("8 5 45;");
	Matrix onto("9 65 4 96;");

	try {
		auto ret = projection_onto(onto, vect);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}
	
	std::cout << ">> Test 102 successful." << std::endl;
	return 0;
}


int test103() {
	// Test: use of gram_schmidt() with 3 1x3 matrices 

	Matrix vect1("1 -1 1;");
	Matrix vect2("1 0 1;");
	Matrix vect3("1 1 2;");

	std::vector<Matrix> vect_space = {vect1, vect2, vect3};

	auto ret = gram_schmidt(vect_space);

	Matrix u1 = vect1;
	Matrix u2_p1 = projection_onto(u1, vect2);
	Matrix u2 = vect2 - u2_p1;
	Matrix u3_p1 = projection_onto(u1, vect3);
	Matrix u3_p2 = projection_onto(u2, vect3);
	Matrix u3 = vect3 - u3_p1 - u3_p2;

	u1.matrix_scale(1 / sqrt(dot_product(u1, u1)));
	u2.matrix_scale(1 / sqrt(dot_product(u2, u2)));
	u3.matrix_scale(1 / sqrt(dot_product(u3, u3)));

	assert(ret.size() == 3);
	assert(ret[0].get_n() == 3);
	assert(ret[1].get_n() == 3);
	assert(ret[2].get_n() == 3);
	assert(ret[0].get_single_element(0, 0) == u1.get_single_element(0, 0));
	assert(ret[0].get_single_element(0, 1) == u1.get_single_element(0, 1));
	assert(ret[0].get_single_element(0, 2) == u1.get_single_element(0, 2));
	assert(ret[1].get_single_element(0, 0) == u2.get_single_element(0, 0));
	assert(ret[1].get_single_element(0, 1) == u2.get_single_element(0, 1));
	assert(ret[1].get_single_element(0, 2) == u2.get_single_element(0, 2));
	assert(ret[2].get_single_element(0, 0) == u3.get_single_element(0, 0));
	assert(ret[2].get_single_element(0, 1) == u3.get_single_element(0, 1));
	assert(ret[2].get_single_element(0, 2) == u3.get_single_element(0, 2));
		
	std::cout << ">> Test 103 successful." << std::endl;
	return 0;
}


int test104() {
	// Test: use of gram_schmidt() with 3 1x5 matrices 

	Matrix vect1("1 -1 1 5 6;");
	Matrix vect2("1 0 1 9 3;");
	Matrix vect3("1 1 2 5 4;");

	std::vector<Matrix> vect_space = {vect1, vect2, vect3};

	auto ret = gram_schmidt(vect_space);

	Matrix u1 = vect1;
	Matrix u2_p1 = projection_onto(u1, vect2);
	Matrix u2 = vect2 - u2_p1;
	Matrix u3_p1 = projection_onto(u1, vect3);
	Matrix u3_p2 = projection_onto(u2, vect3);
	Matrix u3 = vect3 - u3_p1 - u3_p2;

	u1.matrix_scale(1 / sqrt(dot_product(u1, u1)));
	u2.matrix_scale(1 / sqrt(dot_product(u2, u2)));
	u3.matrix_scale(1 / sqrt(dot_product(u3, u3)));

	assert(ret.size() == 3);
	assert(ret[0].get_n() == 5);
	assert(ret[1].get_n() == 5);
	assert(ret[2].get_n() == 5);
	assert(ret[0].get_single_element(0, 0) == u1.get_single_element(0, 0));
	assert(ret[0].get_single_element(0, 1) == u1.get_single_element(0, 1));
	assert(ret[0].get_single_element(0, 2) == u1.get_single_element(0, 2));
	assert(ret[0].get_single_element(0, 3) == u1.get_single_element(0, 3));
	assert(ret[0].get_single_element(0, 4) == u1.get_single_element(0, 4));
	assert(ret[1].get_single_element(0, 0) == u2.get_single_element(0, 0));
	assert(ret[1].get_single_element(0, 1) == u2.get_single_element(0, 1));
	assert(ret[1].get_single_element(0, 2) == u2.get_single_element(0, 2));
	assert(ret[1].get_single_element(0, 3) == u2.get_single_element(0, 3));
	assert(ret[1].get_single_element(0, 4) == u2.get_single_element(0, 4));
	assert(ret[2].get_single_element(0, 0) == u3.get_single_element(0, 0));
	assert(ret[2].get_single_element(0, 1) == u3.get_single_element(0, 1));
	assert(ret[2].get_single_element(0, 2) == u3.get_single_element(0, 2));
	assert(ret[2].get_single_element(0, 3) == u3.get_single_element(0, 3));
	assert(ret[2].get_single_element(0, 4) == u3.get_single_element(0, 4));
		
	std::cout << ">> Test 104 successful." << std::endl;
	return 0;
}


int test105() {
	// Test: use of gram_schmidt() with 5 1x4 matrices 

	Matrix vect1("5 9 8 4;");
	Matrix vect2("99 3 11 5;");
	Matrix vect3("81 17 22 8;");
	Matrix vect4("1 1 1 88;");
	Matrix vect5("99 6 5 77;");

	std::vector<Matrix> vect_space = {vect1, vect2, vect3, vect4, vect5};

	auto ret = gram_schmidt(vect_space);

	Matrix u1 = vect1;
	Matrix u2_p1 = projection_onto(u1, vect2);
	Matrix u2 = vect2 - u2_p1;
	Matrix u3_p1 = projection_onto(u1, vect3);
	Matrix u3_p2 = projection_onto(u2, vect3);
	Matrix u3 = vect3 - u3_p1 - u3_p2;
	Matrix u4_p1 = projection_onto(u1, vect4);
	Matrix u4_p2 = projection_onto(u2, vect4);
	Matrix u4_p3 = projection_onto(u3, vect4);
	Matrix u4 = vect4 - u4_p1 - u4_p2 - u4_p3;
	Matrix u5_p1 = projection_onto(u1, vect5);
	Matrix u5_p2 = projection_onto(u2, vect5);
	Matrix u5_p3 = projection_onto(u3, vect5);
	Matrix u5_p4 = projection_onto(u4, vect5);
	Matrix u5 = vect5 - u5_p1 - u5_p2 - u5_p3 - u5_p4;

	u1.matrix_scale(1 / sqrt(dot_product(u1, u1)));
	u2.matrix_scale(1 / sqrt(dot_product(u2, u2)));
	u3.matrix_scale(1 / sqrt(dot_product(u3, u3)));
	u4.matrix_scale(1 / sqrt(dot_product(u4, u4)));
	u5.matrix_scale(1 / sqrt(dot_product(u5, u5)));

	assert(ret.size() == 5);
	assert(ret[0].get_n() == 4);
	assert(ret[1].get_n() == 4);
	assert(ret[2].get_n() == 4);
	assert(ret[3].get_n() == 4);
	assert(ret[4].get_n() == 4);
	assert(ret[0].get_single_element(0, 0) == u1.get_single_element(0, 0));
	assert(ret[0].get_single_element(0, 1) == u1.get_single_element(0, 1));
	assert(ret[0].get_single_element(0, 2) == u1.get_single_element(0, 2));
	assert(ret[0].get_single_element(0, 3) == u1.get_single_element(0, 3));
	assert(ret[1].get_single_element(0, 0) == u2.get_single_element(0, 0));
	assert(ret[1].get_single_element(0, 1) == u2.get_single_element(0, 1));
	assert(ret[1].get_single_element(0, 2) == u2.get_single_element(0, 2));
	assert(ret[1].get_single_element(0, 3) == u2.get_single_element(0, 3));
	assert(ret[2].get_single_element(0, 0) == u3.get_single_element(0, 0));
	assert(ret[2].get_single_element(0, 1) == u3.get_single_element(0, 1));
	assert(ret[2].get_single_element(0, 2) == u3.get_single_element(0, 2));
	assert(ret[2].get_single_element(0, 3) == u3.get_single_element(0, 3));
	assert(ret[3].get_single_element(0, 0) == u4.get_single_element(0, 0));
	assert(ret[3].get_single_element(0, 1) == u4.get_single_element(0, 1));
	assert(ret[3].get_single_element(0, 2) == u4.get_single_element(0, 2));
	assert(ret[3].get_single_element(0, 3) == u4.get_single_element(0, 3));
	assert(ret[4].get_single_element(0, 1) == u5.get_single_element(0, 1));
	assert(ret[4].get_single_element(0, 0) == u5.get_single_element(0, 0));
	assert(ret[4].get_single_element(0, 2) == u5.get_single_element(0, 2));
	assert(ret[4].get_single_element(0, 3) == u5.get_single_element(0, 3));
		
	std::cout << ">> Test 105 successful." << std::endl;
	return 0;
}


int test106() {
	// Test: use of gram_schmidt() with 1 1x3 matrix 

	Matrix vect1("1 -1 1;");

	std::vector<Matrix> vect_space = {vect1};

	auto ret = gram_schmidt(vect_space);

	Matrix u1 = vect1;

	u1.matrix_scale(1 / sqrt(dot_product(u1, u1)));

	assert(ret.size() == 1);
	assert(ret[0].get_n() == 3);
	assert(ret[0].get_single_element(0, 0) == u1.get_single_element(0, 0));
	assert(ret[0].get_single_element(0, 1) == u1.get_single_element(0, 1));
	assert(ret[0].get_single_element(0, 2) == u1.get_single_element(0, 2));
		
	std::cout << ">> Test 106 successful." << std::endl;
	return 0;
}


int test107() {
	// Test: use of gram_schmidt() with empty space -> fails 

	std::vector<Matrix> vect_space = {};


	try {
		auto ret = gram_schmidt(vect_space);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::EMPTY_SPACE);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Vector space is empty. Should contain at least one vector.");
	}
		
	std::cout << ">> Test 107 successful." << std::endl;
	return 0;
}


int test108() {
	// Test: use of gram_schmidt() with vector space with uneven vectors

	Matrix vect1("1 -1 1 5 6;");
	Matrix vect2("1 0 1;");
	Matrix vect3("1 1 5 4;");

	std::vector<Matrix> vect_space = {vect1, vect2, vect3};

	try {
		auto ret = gram_schmidt(vect_space);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INCONS_MATRX_COLS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The column count is not consistent between both matrices.");
	}
		
	std::cout << ">> Test 108 successful." << std::endl;
	return 0;
}


int test109() {
	// Test: use of gram_schmidt() with 3 0x0 matrices 

	Matrix vect1(0, 0);
	Matrix vect2(0, 0);
	Matrix vect3(0, 0);

	std::vector<Matrix> vect_space = {vect1, vect2, vect3};

	try {
		auto ret = gram_schmidt(vect_space);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NOT_SINGLE_ROW);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: The number of rows in evauluated matrix must be 1.");
	}
		
	std::cout << ">> Test 109 successful." << std::endl;
	return 0;
}


int test110() {
	// Test: use of gram_schmidt() with 3x3 matrix 

	Matrix mtrx("1 2 3; 4 5 6; 7 8 9;");

	auto ret = rank(mtrx);
	
	assert(ret == 2);
		
	std::cout << ">> Test 110 successful." << std::endl;
	return 0;
}


int test111() {
	// Test: use of gram_schmidt() with 4x4 matrix 

	Matrix mtrx("9 85 2 41; 6 5 68 5; 222 87 5 312; 2 3 35 58;");

	auto ret = rank(mtrx);
	
	assert(ret == 4);
		
	std::cout << ">> Test 111 successful." << std::endl;
	return 0;
}


int test112() {
	// Test: use of gram_schmidt() with 1x5 matrix 

	Matrix mtrx("1 2 3 4 5;");

	auto ret = rank(mtrx);
	
	assert(ret == 1);
		
	std::cout << ">> Test 112 successful." << std::endl;
	return 0;
}


int test113() {
	// Test: use of gram_schmidt() with 5x1 matrix 

	Matrix mtrx("1; 2; 3; 4; 5;");

	auto ret = rank(mtrx);
	
	assert(ret == 1);
		
	std::cout << ">> Test 113 successful." << std::endl;
	return 0;
}


int test114() {
	// Test: use of gram_schmidt() with 2x5 matrix 

	Matrix mtrx("5 6 8 2 4; 2 7 65 9 68");

	auto ret = rank(mtrx);
	
	assert(ret == 2);
		
	std::cout << ">> Test 114 successful." << std::endl;
	return 0;
}


int test115() {
	// Test: use of gram_schmidt() with 5x2 matrix 

	Matrix mtrx("5 6; 8 2; 4 2; 7 65; 9 68;");

	auto ret = rank(mtrx);
	
	assert(ret == 2);
		
	std::cout << ">> Test 115 successful." << std::endl;
	return 0;
}


int test116() {
	// Test: use of gram_schmidt() with 2x4 matrix 

	Matrix mtrx(2, 4);

	auto ret = rank(mtrx);
	
	assert(ret == 0);
		
	std::cout << ">> Test 116 successful." << std::endl;
	return 0;
}


int test117() {
	// Test: use of gram_schmidt() with 1x1 matrix 

	Matrix mtrx("5");

	auto ret = rank(mtrx);
	
	assert(ret == 1);
		
	std::cout << ">> Test 117 successful." << std::endl;
	return 0;
}


int test118() {
	// Test: use of gram_schmidt() with 0x0 matrix 

	Matrix mtrx(0, 0);

	try {
		auto ret = rank(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 0.");
	}
		
	std::cout << ">> Test 118 successful." << std::endl;
	return 0;
}


int test119() {
	// Test: use of adjoint() with 3x3 matrix 

	Matrix mtrx("1 -1 2; 2 3 5; 1 0 3;");

	auto ret = adjoint(mtrx);

	Matrix res("9 3 -11; -1 1 -1; -3 -1 5;");

	assert(ret.equal(res));

	std::cout << ">> Test 119 successful." << std::endl;
	return 0;
}


int test120() {
	// Test: use of adjoint() with 4x4 matrix 

	Matrix mtrx("8 9 82 6; 5 63 6 6; 3 3 65 4; 1 31 1 2;");

	auto ret = adjoint(mtrx);

	Matrix res("-3426 1262 4236 -1980;"
	           "-246 472 286 -1250;"
			   "-176 422 36 -810;"
			   "5614 -8158 -6569 15585;");

	assert(ret.equal(res));

	std::cout << ">> Test 120 successful." << std::endl;
	return 0;
}


int test121() {
	// Test: use of adjoint() with 5x5 matrix 

	Matrix mtrx("8 26 36 2 45; 9 6 74 52 22; 54 5 7 23 65; 1 2 85 32 6; 1 23 85 23 7;");

	auto ret = adjoint(mtrx);

	Matrix res("-2315400 -1741206 1935322 -343664 2680798;"
	           "-387384 1311361 -143285 -4656372 3690585;"
			   "132304 -1204788 147208 1864860 -29432;"
			   "-662396 3101825 -374597 -2639608 250589;"
			   "2173500 377844 -362388 1376872 -2596516;");

	assert(ret.equal(res));

	std::cout << ">> Test 121 successful." << std::endl;
	return 0;
}


int test122() {
	// Test: use of adjoint() with 2x2 matrix 

	Matrix mtrx("9 82; 2 3;");

	auto ret = adjoint(mtrx);

	Matrix res("3 -82; -2 9;");

	assert(ret.equal(res));

	std::cout << ">> Test 122 successful." << std::endl;
	return 0;
}


int test123() {
	// Test: use of adjoint() with 1x1 matrix -> fails

	Matrix mtrx("8;");

	try {
		auto ret = adjoint(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS_ONE);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 1.");
	}

	std::cout << ">> Test 123 successful." << std::endl;
	return 0;
}


int test124() {
	// Test: use of adjoint() with 2x5 matrix -> fails

	Matrix mtrx(2, 5);

	try {
		auto ret = adjoint(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 124 successful." << std::endl;
	return 0;
}


int test125() {
	// Test: use of adjoint() with 0x0 matrix -> fails

	Matrix mtrx(0, 0);

	try {
		auto ret = adjoint(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS_ONE);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 1.");
	}

	std::cout << ">> Test 125 successful." << std::endl;
	return 0;
}


int test126() {
	// Test: use of cofactors() with 3x3 matrix 

	Matrix mtrx("1 -1 2; 2 3 5; 1 0 3;");

	auto ret = cofactors(mtrx);

	Matrix res("9 -1 -3; 3 1 -1; -11 -1 5;");

	assert(ret.equal(res));

	std::cout << ">> Test 126 successful." << std::endl;
	return 0;
}


int test127() {
	// Test: use of cofactors() with 4x4 matrix 

	Matrix mtrx("8 9 82 6; 5 63 6 6; 3 3 65 4; 1 31 1 2;");

	auto ret = cofactors(mtrx);

	Matrix res("-3426 -246 -176 5614;"
	           "1262 472 422 -8158;"
			   "4236 286 36 -6569;"
			   "-1980 -1250 -810 15585;");

	assert(ret.equal(res));

	std::cout << ">> Test 127 successful." << std::endl;
	return 0;
}


int test128() {
	// Test: use of cofactors() with 5x5 matrix 

	Matrix mtrx("8 26 36 2 45; 9 6 74 52 22; 54 5 7 23 65; 1 2 85 32 6; 1 23 85 23 7;");

	auto ret = cofactors(mtrx);

	Matrix res("-2315400 -387384 132304 -662396 2173500;"
	           "-1741206 1311361 -1204788 3101825 377844;"
			   "1935322 -143285 147208 -374597 -362388;"
			   "-343664 -4656372 1864860 -2639608 1376872;"
			   "2680798 3690585 -29432 250589 -2596516;");

	assert(ret.equal(res));

	std::cout << ">> Test 128 successful." << std::endl;
	return 0;
}


int test129() {
	// Test: use of cofactors() with 2x2 matrix 

	Matrix mtrx("9 82; 2 3;");

	auto ret = cofactors(mtrx);

	Matrix res("3 -2; -82 9;");

	assert(ret.equal(res));

	std::cout << ">> Test 129 successful." << std::endl;
	return 0;
}


int test130() {
	// Test: use of cofactors() with 1x1 matrix -> fails

	Matrix mtrx("8;");

	try {
		auto ret = cofactors(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS_ONE);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 1.");
	}

	std::cout << ">> Test 130 successful." << std::endl;
	return 0;
}


int test131() {
	// Test: use of cofactors() with 2x5 matrix -> fails

	Matrix mtrx(2, 5);

	try {
		auto ret = cofactors(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::NON_SQR_MTRX);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: Evaluated matrix is not square.");
	}

	std::cout << ">> Test 131 successful." << std::endl;
	return 0;
}


int test132() {
	// Test: use of cofactors() with 0x0 matrix -> fails

	Matrix mtrx(0, 0);

	try {
		auto ret = cofactors(mtrx);
	}
	catch(LALIB_Error ex){
		assert(ex.get_error_code() == ErrorCode::INVALID_DIMS_ONE);
		std::string err_msg(ex.what());
		assert(err_msg == "Error: One of the dimensions of the evaluated matrix is <= 1.");
	}

	std::cout << ">> Test 132 successful." << std::endl;
	return 0;
}


int main() {
	bool all  = false;
	bool t1   = false;
	bool t2   = false;
	bool t3   = false;
	bool t4   = false;
	bool t5   = false;
	bool t6   = false;
	bool t7   = false;
	bool t8   = false;
	bool t9   = false;
	bool t10  = false;
	bool t11  = false;
	bool t12  = false;
	bool t13  = false;
	bool t14  = false;
	bool t15  = false;
	bool t16  = false;
	bool t17  = false;
	bool t18  = false;
	bool t19  = false;
	bool t20  = false;
	bool t21  = false;
	bool t22  = false;
	bool t23  = false;
	bool t24  = false;
	bool t25  = false;
	bool t26  = false;
	bool t27  = false;
	bool t28  = false;
	bool t29  = false;
	bool t30  = false;
	bool t31  = false;
	bool t32  = false;
	bool t33  = false;
	bool t34  = false;
	bool t35  = false;
	bool t36  = false;
	bool t37  = false;
	bool t38  = false;
	bool t39  = false;
	bool t40  = false;
	bool t41  = false;
	bool t42  = false;
	bool t43  = false;
	bool t44  = false;
	bool t45  = false;
	bool t46  = false;
	bool t47  = false;
	bool t48  = false;
	bool t49  = false;
	bool t50  = false;
	bool t51  = false;
	bool t52  = false;
	bool t53  = false;
	bool t54  = false;
	bool t55  = false;
	bool t56  = false;
	bool t57  = false;
	bool t58  = false;
	bool t59  = false;
	bool t60  = false;
	bool t61  = false;
	bool t62  = false;
	bool t63  = false;
	bool t64  = false;
	bool t65  = false;
	bool t66  = false;
	bool t67  = false;
	bool t68  = false;
	bool t69  = false;
	bool t70  = false;
	bool t71  = false;
	bool t72  = false;
	bool t73  = false;
	bool t74  = false;
	bool t75  = false;
	bool t76  = false;
	bool t77  = false;
	bool t78  = false;
	bool t79  = false;
	bool t80  = false;
	bool t81  = false;
	bool t82  = false;
	bool t83  = false;
	bool t84  = false;
	bool t85  = false;
	bool t86  = false;
	bool t87  = false;
	bool t88  = false;
	bool t89  = false;
	bool t90  = false;
	bool t91  = false;
	bool t92  = false;
	bool t93  = false;
	bool t94  = false;
	bool t95  = false;
	bool t96  = false;
	bool t97  = false;
	bool t98  = false;
	bool t99  = false;
	bool t100 = false;
	bool t101 = false;
	bool t102 = false;
	bool t103 = false;
	bool t104 = false;
	bool t105 = false;
	bool t106 = false;
	bool t107 = false;
	bool t108 = false;
	bool t109 = false;
	bool t110 = false;
	bool t111 = false;
	bool t112 = false;
	bool t113 = false;
	bool t114 = false;
	bool t115 = false;
	bool t116 = false;
	bool t117 = false;
	bool t118 = false;
	bool t119 = true;
	bool t120 = true;
	bool t121 = true;
	bool t122 = true;
	bool t123 = true;
	bool t124 = true;
	bool t125 = true;
	bool t126 = true;
	bool t127 = true;
	bool t128 = true;
	bool t129 = true;
	bool t130 = true;
	bool t131 = true;
	bool t132 = true;

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
	if(t14 || all){
		test14();
	}
	if(t15 || all){
		test15();
	}
	if(t16 || all){
		test16();
	}
	if(t17 || all){
		test17();
	}
	if(t18 || all){
		test18();
	}
	if(t19 || all){
		test19();
	}
	if(t20 || all){
		test20();
	}
	if(t21 || all){
		test21();
	}
	if(t22 || all){
		test22();
	}
	if(t23 || all){
		test23();
	}
	if(t24 || all){
		test24();
	}
	if(t25 || all){
		test25();
	}
	if(t26 || all){
		test26();
	}
	if(t27 || all){
		test27();
	}
	if(t28 || all){
		test28();
	}
	if(t29 || all){
		test29();
	}
	if(t30 || all){
		test30();
	}
	if(t31 || all){
		test31();
	}
	if(t32 || all){
		test32();
	}
	if(t33 || all){
		test33();
	}
	if(t34 || all){
		test34();
	}
	if(t35 || all){
		test35();
	}
	if(t36 || all){
		test36();
	}
	if(t37 || all){
		test37();
	}
	if(t38 || all){
		test38();
	}
	if(t39 || all){
		test39();
	}
	if(t40 || all){
		test40();
	}
	if(t41 || all){
		test41();
	}
	if(t42 || all){
		test42();
	}
	if(t43 || all){
		test43();
	}
	if(t44 || all){
		test44();
	}
	if(t45 || all){
		test45();
	}
	if(t46 || all){
		test46();
	}
	if(t47 || all){
		test47();
	}
	if(t48 || all){
		test48();
	}
	if(t49 || all){
		test49();
	}
	if(t50 || all){
		test50();
	}
	if(t51 || all){
		test51();
	}
	if(t52 || all){
		test52();
	}
	if(t53 || all){
		test53();
	}
	if(t54 || all){
		test54();
	}
	if(t55 || all){
		test55();
	}
	if(t56 || all){
		test56();
	}
	if(t57 || all){
		test57();
	}
	if(t58 || all){
		test58();
	}
	if(t59 || all){
		test59();
	}
	if(t60 || all){
		test60();
	}
	if(t61 || all){
		test61();
	}
	if(t62 || all){
		test62();
	}
	if(t63 || all){
		test63();
	}
	if(t64 || all){
		test64();
	}
	if(t65 || all){
		test65();
	}
	if(t66 || all){
		test66();
	}
	if(t67 || all){
		test67();
	}
	if(t68 || all){
		test68();
	}
	if(t69 || all){
		test69();
	}
	if(t70 || all){
		test70();
	}
	if(t71 || all){
		test71();
	}
	if(t72 || all){
		test72();
	}
	if(t73 || all){
		test73();
	}
	if(t74 || all){
		test74();
	}
	if(t75 || all){
		test75();
	}
	if(t76 || all){
		test76();
	}
	if(t77 || all){
		test77();
	}
	if(t78 || all){
		test78();
	}
	if(t79 || all){
		test79();
	}
	if(t80 || all){
		test80();
	}
	if(t81 || all){
		test81();
	}
	if(t82 || all){
		test82();
	}
	if(t83 || all){
		test83();
	}
	if(t84 || all){
		test84();
	}
	if(t85 || all){
		test85();
	}
	if(t86 || all){
		test86();
	}
	if(t87 || all){
		test87();
	}
	if(t88 || all){
		test88();
	}
	if(t89 || all){
		test89();
	}
	if(t90 || all){
		test90();
	}
	if(t91 || all){
		test91();
	}
	if(t92 || all){
		test92();
	}
	if(t93 || all){
		test93();
	}
	if(t94 || all){
		test94();
	}
	if(t95 || all){
		test95();
	}
	if(t96 || all){
		test96();
	}
	if(t97 || all){
		test97();
	}
	if(t98 || all){
		test98();
	}
	if(t99 || all){
		test99();
	}
	if(t100 || all){
		test100();
	}
	if(t101 || all){
		test101();
	}
	if(t102 || all){
		test102();
	}
	if(t103 || all){
		test103();
	}
	if(t104 || all){
		test104();
	}
	if(t105 || all){
		test105();
	}
	if(t106 || all){
		test106();
	}
	if(t107 || all){
		test107();
	}
	if(t108 || all){
		test108();
	}
	if(t109 || all){
		test109();
	}
	if(t110 || all){
		test110();
	}
	if(t111 || all){
		test111();
	}
	if(t112 || all){
		test112();
	}
	if(t113 || all){
		test113();
	}
	if(t114 || all){
		test114();
	}
	if(t115 || all){
		test115();
	}
	if(t116 || all){
		test116();
	}
	if(t117 || all){
		test117();
	}
	if(t118 || all){
		test118();
	}
	if(t119 || all){
		test119();
	}
	if(t120 || all){
		test120();
	}
	if(t121 || all){
		test121();
	}
	if(t122 || all){
		test122();
	}
	if(t123 || all){
		test123();
	}
	if(t124 || all){
		test124();
	}
	if(t125 || all){
		test125();
	}
	if(t126 || all){
		test126();
	}
	if(t127 || all){
		test127();
	}
	if(t128 || all){
		test128();
	}
	if(t129 || all){
		test129();
	}
	if(t130 || all){
		test130();
	}
	if(t131 || all){
		test131();
	}
	if(t132 || all){
		test132();
	}

	return 0;
}
