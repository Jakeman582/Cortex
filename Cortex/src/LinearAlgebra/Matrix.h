#pragma once

#include <string>

namespace Cortex
{

	class Matrix
	{

	public:
		Matrix(int rows, int columns);
		Matrix(const Matrix& other);
		~Matrix();

		Matrix& operator=(const Matrix& right);
		Matrix& operator+=(const Matrix& right);

		double operator()(int row, int column) const;
		double& operator()(int row, int column);

		std::string to_string();


	private:
		int m_rows;
		int m_columns;
		double* m_buffer;

	};

}

Cortex::Matrix operator+(const Cortex::Matrix& left, const Cortex::Matrix& right);