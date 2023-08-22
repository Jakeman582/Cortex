#include <iostream>
#include <chrono>
#include <random>

#include <LinearAlgebra/Matrix.h>
#include <Regression/LinearRegressor.h>

int main()
{
	Cortex::LinearRegressor reg_1 = Cortex::LinearRegressor();

	// We want to generate a linear model approximating
	// 1 + 2x_1 + 3x_2 + 4x_3 + 5x_4 = y
	double t_0 = 1.0;
	double t_1 = 2.0;
	double t_2 = 3.0;
	double t_3 = 4.0;
	double t_4 = 5.0;

	// We can uniformly generate values for parameters
	unsigned seed_1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine parameter_generator(seed_1);
	std::uniform_real_distribution<double> parameter_distribution(-100.0, 100.0);

	// We'll want to distribute errors to each value according to a normal distribution
	unsigned seed_2 = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine value_generator(seed_2);
	std::normal_distribution<double> value_distribution(0.0, 1.0);
	
	// Generate 1000 sample points, for 4 features
	int number_samples = 1000;
	int number_features = 4;
	Cortex::Matrix data = Cortex::Matrix(number_samples, number_features);
	Cortex::Matrix labels = Cortex::Matrix(number_samples, 1);

	// For the number of samples, we want to generate random points, and then add a little bit 
	// of distortion to each y value to generate each sample
	for(int i = 0; i < number_samples; ++i)
	{
		double x_1 = parameter_distribution(parameter_generator);
		double x_2 = parameter_distribution(parameter_generator);
		double x_3 = parameter_distribution(parameter_generator);
		double x_4 = parameter_distribution(parameter_generator);

		double y = t_0 +
			t_1 * x_1 +
			t_2 * x_2 +
			t_3 * x_3 +
			t_4 * x_4;

		double delta_y = value_distribution(value_generator);

		data(i, 0) = x_1;
		data(i, 1) = x_2;
		data(i, 2) = x_3;
		data(i, 3) = x_4;

		labels(i, 0) = y + delta_y;

	}

	reg_1.fit(data, labels);

	std::cout << reg_1.get_parameters().to_string() << std::endl;

}