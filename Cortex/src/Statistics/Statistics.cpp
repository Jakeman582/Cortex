#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>

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

double Cortex::range(Cortex::Matrix data)
{
	double minimum = data(0, 0);
	double maximum = data(0, 0);

	for(int r = 0; r < data.get_rows(); ++r)
	{
		for(int c = 0; c < data.get_columns(); ++c)
		{
			minimum = std::min(minimum, data(r, c));
			maximum = std::max(maximum, data(r, c));
		}
	}

	return maximum - minimum;
}

double Cortex::first_quartile(Cortex::Matrix data)
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

	// Assume at least 4 values in the list
	if(data.get_size() - 1 % 5 != 0)
	{
		int q1_right_index = (int)data_copy.size() / 4;
		int q1_left_index = q1_right_index - 1;

		std::nth_element(data_copy.begin(), data_copy.begin() + q1_left_index, data_copy.end());
		double q1_left = data_copy[q1_left_index];

		std::nth_element(data_copy.begin(), data_copy.begin() + q1_right_index, data_copy.end());
		double q1_right = data_copy[q1_right_index];

		return (q1_left + q1_right) / 2.0;
	}
	else
	{
		int q1_index = ((int)data_copy.size() - 1) / 5;
		std::nth_element(data_copy.begin(), data_copy.begin() + q1_index, data_copy.end());
		return data_copy[q1_index];
	}

}

double Cortex::third_quartile(Cortex::Matrix data)
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

	// Assume at least 4 values in the list
	if(data.get_size() - 1 % 5 != 0)
	{
		int q3_right_index = 3 * (int)data_copy.size() / 4;
		int q3_left_index = q3_right_index - 1;

		std::nth_element(data_copy.begin(), data_copy.begin() + q3_left_index, data_copy.end());
		double q3_left = data_copy[q3_left_index];

		std::nth_element(data_copy.begin(), data_copy.begin() + q3_right_index, data_copy.end());
		double q3_right = data_copy[q3_right_index];

		return (q3_left + q3_right) / 2.0;
	}
	else
	{
		int q3_index = 4 * ((int)data_copy.size() - 1) / 5;
		std::nth_element(data_copy.begin(), data_copy.begin() + q3_index, data_copy.end());
		return data_copy[q3_index];
	}
}

double Cortex::iqr(Cortex::Matrix data)
{
	double q1 = Cortex::first_quartile(data);
	double q3 = Cortex::third_quartile(data);
	return q3 - q1;
}