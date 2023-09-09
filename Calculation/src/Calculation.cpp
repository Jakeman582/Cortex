#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

#include <LinearAlgebra/Matrix.h>
#include <Statistics/Statistics.h>
#include <Regression/LinearRegressor.h>

int main()
{

	std::vector<double> numbers = { 14, 7, 6, 5, 12, 38, 8, 7, 10, 10, 10, 11, 4, 5, 22, 7, 5, 10, 35, 7 };
	
	Cortex::Matrix data(numbers.size(), 1);
	int index = 0;
	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			data(r, c) = numbers[index];
			index++;
		}
	}

	double q1 = Cortex::first_quartile(data);
	double median = Cortex::median(data);
	double q3 = Cortex::third_quartile(data);
	double range = Cortex::range(data);
	double iqr = Cortex::iqr(data);
	std::cout << q1 << ", " << median << ", " << q3 << ", " << range << ", " << iqr << std::endl;

}