#pragma once

#include "../LinearAlgebra/Matrix.h"

namespace Cortex
{
	class LinearRegressor
	{

	public:
		LinearRegressor();

		void fit(Cortex::Matrix X, Cortex::Matrix y);
		Cortex::Matrix get_parameters();
		double predict(Cortex::Matrix input);

	private:
		Cortex::Matrix m_parameters;

	};

}