#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

#include <LinearAlgebra/Matrix.h>
#include <Statistics/Statistics.h>
#include <Regression/LinearRegressor.h>
#include <Graphing/Summary.h>

int main()
{

	unsigned int seed = std::chrono::system_clock().now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::extreme_value_distribution<double> distribution(50.0, 70.0);

	Cortex::Matrix data(1000, 1);
	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			data(r, c) = distribution(generator);
		}
	}

	Cortex::box_and_whisker(data, 500, 500);

}