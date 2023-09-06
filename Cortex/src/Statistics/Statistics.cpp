#include <iostream>
#include <vector>
#include <chrono>
#include <random>
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

double Cortex::median(Cortex::Matrix data)
{
	std::vector<double> data_copy;
	data_copy.reserve(data.get_size());
	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			data_copy.push_back(data(r, c));
		}
	}

	if(data.get_size() % 2 == 1)
	{
		int middle_index = data.get_size() / 2;
		std::nth_element(data_copy.begin(), data_copy.begin() + middle_index, data_copy.end());
		return data_copy[middle_index];
	}
	else
	{
		int right_middle_index = data.get_size() / 2;
		int left_middle_index = right_middle_index - 1;

		std::nth_element(data_copy.begin(), data_copy.begin() + left_middle_index, data_copy.end());
		double left_middle = data_copy[left_middle_index];

		std::nth_element(data_copy.begin(), data_copy.begin() + right_middle_index, data_copy.end());
		double right_middle = data_copy[right_middle_index];

		return (left_middle + right_middle) / 2.0;
	}
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