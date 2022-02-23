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
	// Test: use operator*(double) on a 3 x 3 matrix and store result in new matirx

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
	bool t14 = false;
	bool t15 = false;
	bool t16 = false;
	bool t17 = false;
	bool t18 = false;
	bool t19 = false;
	bool t20 = false;
	bool t21 = false;
	bool t22 = false;
	bool t23 = false;
	bool t24 = false;
	bool t25 = false;
	bool t26 = false;
	bool t27 = false;
	bool t28 = false;
	bool t29 = false;
	bool t30 = false;
	bool t31 = false;
	bool t32 = false;
	bool t33 = false;
	bool t34 = false;
	bool t35 = false;
	bool t36 = false;
	bool t37 = false;
	bool t38 = false;
	bool t39 = false;
	bool t40 = false;
	bool t41 = false;
	bool t42 = false;
	bool t43 = false;
	bool t44 = false;
	bool t45 = false;
	bool t46 = false;
	bool t47 = false;
	bool t48 = false;
	bool t49 = false;
	bool t50 = false;
	bool t51 = false;
	bool t52 = false;
	bool t53 = false;
	bool t54 = false;
	bool t55 = false;
	bool t56 = false;
	bool t57 = false;
	bool t58 = false;
	bool t59 = false;
	bool t60 = false;
	bool t61 = false;
	bool t62 = false;
	bool t63 = false;
	bool t64 = false;
	bool t65 = false;
	bool t66 = false;
	bool t67 = false;
	bool t68 = false;
	bool t69 = false;
	bool t70 = false;
	bool t71 = false;
	bool t72 = false;
	bool t73 = false;
	bool t74 = false;
	bool t75 = false;
	bool t76 = false;
	bool t77 = false;
	bool t78 = false;
	bool t79 = false;
	bool t80 = false;
	bool t81 = false;
	bool t82 = false;
	bool t83 = false;
	bool t84 = false;

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

	return 0;
}
/*
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


