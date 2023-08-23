#include <cmath>

#include "../LinearAlgebra/Matrix.h"

#include "Statistics.h"

double Cortex::mean(Cortex::Matrix data)
{
	double sum = 0.0;

	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			sum += data(r, c);
		}
	}

	double number_elements = (double) data.get_rows() * data.get_columns();

	return sum / number_elements;
}

double Cortex::variance(Cortex::Matrix data)
{
	double mean = Cortex::mean(data);

	double sum = 0.0;
	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			double difference = data(r, c) - mean;
			sum += difference * difference;
		}
	}

	double number_elements = (double)data.get_rows() * data.get_columns();
	return sum / number_elements;
}

double Cortex::standard_deviation(Cortex::Matrix data)
{
	return sqrt(Cortex::variance(data));
}