#pragma once

#include "../LinearAlgebra/Matrix.h"

namespace Cortex
{
	double mean(Cortex::Matrix data);
	double median(Cortex::Matrix data);
	double variance(Cortex::Matrix data);
	double standard_deviation(Cortex::Matrix data);
	double range(Cortex::Matrix data);
	double first_quartile(Cortex::Matrix data);
	double third_quartile(Cortex::Matrix data);
	double iqr(Cortex::Matrix data);
}
