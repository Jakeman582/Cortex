#pragma once

#include "../LinearAlgebra/Matrix.h"

namespace Cortex
{
	double mean(Cortex::Matrix data);
	double median(Cortex::Matrix data);
	double variance(Cortex::Matrix data);
	double standard_deviation(Cortex::Matrix data);
}
