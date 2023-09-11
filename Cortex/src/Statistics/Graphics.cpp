#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "../Statistics/Statistics.h"

#include "Graphics.h"

void Cortex::box_and_whisker(Cortex::Matrix data, int image_width, int image_height)
{
	char window[] = "Box and Whisker Plot";

	//cv::Mat image(image_width, image_height, CV_64FC3, cv::Scalar(1.0, 1.0, 1.0));
	cv::Mat image = cv::Mat::zeros(image_width, image_height, CV_64FC3);

	// The box and whisker plot should have 10% of the window's height, and be vertically centered
	int plot_height = 0.1 * image_height;
	int plot_top = 0.5 * image_height - 0.5 * plot_height;
	int plot_vertical_center = 0.5 * image_height;
	int plot_bottom = 0.5 * image_height + 0.5 * plot_height;

	// The box and whisker plot should have 90% of the image's width, and be centered horizontally
	int plot_width = 0.9 * image_width;
	int plot_left = 0.5 * image_width - 0.5 * plot_width;
	int plot_horizontal_center = 0.5 * image_width;
	int plot_right = 0.5 * image_width + 0.5 * plot_width;

	// Get the data's summary statistics
	double data_minimum = Cortex::minimum(data);
	double data_q1 = Cortex::first_quartile(data);
	double data_median = Cortex::median(data);
	double data_q3 = Cortex::third_quartile(data);
	double data_maximum = Cortex::maximum(data);

	// Scale the statistics so they appear in the window
	// The minimum should appear at the plot's left endpoint, and the maximum 
	// should be at the plot's right endpoint.
	//
	// The transformation is linear y = mx + b
	double m = (plot_right - plot_left) / (data_maximum - data_minimum);
	double b = plot_left - m * data_minimum;

	// Scale the summary statistics using the linear transformation
	double minimum = m * data_minimum + b;
	double q1 = m * data_q1 + b;
	double median = m * data_median + b;
	double q3 = m * data_q3 + b;
	double maximum = m * data_maximum + b;


	// Draw a rectangle around the quartiles and the median
	cv::rectangle(
		image,
		cv::Point((int)q1, plot_top), cv::Point((int)q3, plot_bottom),
		cv::Scalar(1.0, 1.0, 0),
		1,
		cv::LINE_8,
		0
	);

	// Draw the stem between the minimum and q1
	cv::line(
		image,
		cv::Point((int)minimum, plot_vertical_center), cv::Point((int)q1, plot_vertical_center),
		cv::Scalar(255, 0, 0),
		1,
		cv::LINE_8,
		0
	);

	// Draw the stem between q3 and the maximum
	cv::line(
		image,
		cv::Point((int)q3, plot_vertical_center), cv::Point((int)maximum, plot_vertical_center),
		cv::Scalar(0, 255, 0),
		1,
		cv::LINE_8,
		0
	);

	// Draw the leaf for the minimum
	cv::line(
		image,
		cv::Point((int)minimum, plot_top), cv::Point((int)minimum, plot_bottom),
		cv::Scalar(0, 0, 255),
		1,
		cv::LINE_8,
		0
	);

	// Draw the leaf for the median
	cv::line(
		image,
		cv::Point((int)median, plot_top), cv::Point((int)median, plot_bottom),
		cv::Scalar(255, 255, 0),
		1,
		cv::LINE_8,
		0
	);

	// Draw the leaf for the maximum
	cv::line(
		image,
		cv::Point((int)maximum, plot_top), cv::Point((int)maximum, plot_bottom),
		cv::Scalar(255, 0, 255),
		1,
		cv::LINE_8,
		0
	);

	cv::imshow(window, image);
	cv::waitKey(0);

}