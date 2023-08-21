#include <iostream>
#include "LinearRegressor.h"

Cortex::LinearRegressor::LinearRegressor()
	: m_parameters(Cortex::Matrix())
{}

void Cortex::LinearRegressor::fit(Cortex::Matrix X, Cortex::Matrix y)
{

	m_parameters.reshape(X.get_columns() + 1, 1);

	// Add a column of 1s to the front of the training data to account for the constant factor
	// Copy the rest of the data one column over
	Cortex::Matrix training_data = Cortex::Matrix(X.get_rows(), X.get_columns() + 1);
	for(int r = 0; r < training_data.get_rows(); ++r)
	{
		training_data(r, 0) = 1.0;
	}
	for(int r = 0; r < X.get_rows(); ++r)
	{
		for(int c = 0; c < X.get_columns(); ++c)
		{
			training_data(r, c + 1) = X(r, c);
		}
	}

	// TODO: Do this iteration 1000 times for now, then change to arbitrary number of iterations
	for(int i = 0; i < 10000; ++i)
	{
		Cortex::Matrix grad = Cortex::Matrix(1, training_data.get_columns());
		
		// For every parameter, we need to get calculate it's gradient
		for(int k = 0; k < training_data.get_columns(); ++k)
		{

			// We'll need to grab each column of data depending on the parameter we're on
			Cortex::Matrix parameter_data = Cortex::Matrix(1, training_data.get_rows());
			for(int p = 0; p < training_data.get_rows(); ++p)
			{
				parameter_data(0, p) = training_data(p, k);
			}

			grad(0, k) = (2 * (parameter_data * ((training_data * m_parameters) - y)))(0, 0);

		}

		// TODO: Turn the learning rate into a variable, instead of a hard-coded value
		m_parameters -= 0.00000001*grad.transpose();
	}

}

Cortex::Matrix Cortex::LinearRegressor::get_parameters()
{
	return m_parameters;
}

double Cortex::LinearRegressor::predict(Cortex::Matrix input)
{
	return 0.0;
}