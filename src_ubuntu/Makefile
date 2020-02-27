TARGET = la_lib

OBJS = 	Determinant.o\
		LinearAlgebraLibrary.o\
		Matrix.o\
		MatrixMultiplication.o\
		Orthogonalization.o\
		REF.o\
		RREF.o\
		Transpose.o

CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = 

$(TARGET):	$(OBJS)	
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean_obj: 
		rm -f *.o

clean:
		rm -f *.o $(TARGET)

Determinant.o:	Determinant.h Determinant.cpp 
LinearAlgebraLibrary.o:	LinearAlgebraLibrary.h LinearAlgebraLibrary.cpp
Matrix.o:	Matrix.h Matrix.cpp 
MatrixMultiplication.o:	MatrixMultiplication.h MatrixMultiplication.cpp
Orthogonalization.o:	Orthogonalization.h Orthogonalization.cpp
REF.o: REF.h REF.cpp
RREF.o:	RREF.h RREF.cpp
Transpose.o: Transpose.h Transpose.cpp

#Recipe used in command line
#g++ -std=c++17 FileSystemCrawler.cpp -o output -lstdc++fs
