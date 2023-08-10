#include <iostream>

#include <LinearAlgebra/Matrix.h>

int main()
{

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

}