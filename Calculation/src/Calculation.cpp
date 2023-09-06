#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

//#include <Cortex/Utilities.h>
#include <LinearAlgebra/Matrix.h>
#include <Statistics/Statistics.h>
#include <Regression/LinearRegressor.h>

int main()
{

	const int number_data = 10;
	std::vector<double> numbers;
	numbers.reserve(number_data);
	for(int index = 0; index < number_data; ++index)
	{
		numbers.push_back(index);
	}

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
	
	Cortex::Matrix data(number_data, 1);
	int index = 0;
	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			data(r, c) = numbers[index];
			index++;
		}
	}

	double median = Cortex::median(data);
	std::cout << "Median: " << median << std::endl;

}