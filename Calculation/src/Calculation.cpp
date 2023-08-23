#include <iostream>
#include <chrono>
#include <random>

#include <LinearAlgebra/Matrix.h>
#include <Statistics/Statistics.h>
#include <Regression/LinearRegressor.h>

int main()
{

	int number_data = 10000;
	
	Cortex::Matrix data(number_data, 1);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(0.0, 1.0);

	for(int r = 0; r < number_data; ++r)
	{
		data(r, 0) = distribution(generator);
	}

	double mean = Cortex::mean(data);
	double standard_deviation = Cortex::standard_deviation(data);

	std::cout << "Mean:               " << mean << std::endl <<
		"Standard Deviation: " << standard_deviation << std::endl;

}