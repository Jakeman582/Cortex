#include <iostream>

#include <LinearAlgebra/Matrix.h>

int main()
{

	Cortex::Matrix basic_matrix;
	std::cout << basic_matrix.to_string() << std::endl;

	Cortex::Matrix row_vector(1, 3);
	std::cout << row_vector.to_string() << std::endl;

	Cortex::Matrix column_vector(3, 1);
	std::cout << column_vector.to_string() << std::endl;

	Cortex::Matrix matrix_1(3, 3);
	Cortex::Matrix matrix_2(3, 3);

	std::cout << matrix_1.to_string() << "\n" << matrix_2.to_string() << "\n";

	matrix_1(0, 0) = 1.0;
	matrix_2(2, 2) = 1.0;

	std::cout << matrix_1.to_string() << "\n" << matrix_2.to_string() << "\n";

	Cortex::Matrix sum = matrix_1 + matrix_2;
	std::cout << sum.to_string() << "\n";

	Cortex::Matrix matrix_3(3, 3);
	matrix_3(1, 1) = 1.0;

	sum += matrix_3;
	std::cout << sum.to_string() << "\n";

	Cortex::Matrix A(3, 3);
	A(0, 0) = 1, A(0, 1) = 2, A(0, 2) = 3;
	A(1, 0) = 4, A(1, 1) = 5, A(1, 2) = 6;
	A(2, 0) = 7, A(2, 1) = 8, A(2, 2) = 9;

	Cortex::Matrix B(3, 3);
	B(0, 0) = 4, B(0, 1) = 9, B(0, 2) = 9;
	B(1, 0) = 6, B(1, 1) = 2, B(1, 2) = 9;
	B(2, 0) = 6, B(2, 1) = 6, B(2, 2) = 0;

	std::cout << (A * B).to_string() << std::endl;

	Cortex::Matrix C(3, 3);
	C(0, 0) = 1, C(0, 1) = 1, C(0, 2) = 1;
	C(1, 0) = 2, C(1, 1) = 2, C(1, 2) = 2;
	C(2, 0) = 4, C(2, 1) = 4, C(2, 2) = 4;
	A *= C;
	std::cout << A.to_string() << "\n";

}