#include "Matrix.h"


Cortex::Matrix::Matrix(int rows, int columns)
	: m_rows(rows), m_columns(columns)
{
	m_buffer = new double[m_rows * m_columns];

	for (int r = 0; r < m_rows; ++r)
	{
		for(int c= 0; c < m_columns; ++c)
		{
			(*this)(r, c) = 0.0;
		}
	}
}

Cortex::Matrix::Matrix(const Cortex::Matrix& other)
	: m_rows(other.m_rows), m_columns(other.m_columns)
{
	delete[] m_buffer;
	m_buffer = new double[m_rows * m_columns];

	for(int r = 0; r < m_rows; ++r)
	{
		for(int c = 0; c < m_columns; ++c)
		{
			(*this)(r, c) = other(r, c);
		}
	}
}

Cortex::Matrix::~Matrix()
{
	delete[] m_buffer;
}

Cortex::Matrix& Cortex::Matrix::operator=(const Cortex::Matrix& right)
{
	if (this != &right)
	{
		delete[] m_buffer;

		m_rows = right.m_rows;
		m_columns = right.m_columns;

		m_buffer = new double[m_rows * m_columns];

		for(int r = 0; r < m_rows; ++r)
		{
			for(int c = 0; c < m_columns; ++c)
			{
				(*this)(r, c) = right(r, c);
			}
		}
	}

	return *this;
}

Cortex::Matrix& Cortex::Matrix::operator+=(const Cortex::Matrix& right)
{
	for(int r = 0; r < m_rows; ++r)
	{
		for(int c = 0; c < m_columns; ++c)
		{
			(*this)(r, c) += right(r, c);
		}
	}

	return *this;
}

Cortex::Matrix operator+(const Cortex::Matrix& left, const Cortex::Matrix& right)
{
	Cortex::Matrix sum = left;
	sum += right;
	return sum;
}

double Cortex::Matrix::operator()(int row, int column) const
{
	return m_buffer[row * m_columns + column];
}

double& Cortex::Matrix::operator()(int row, int column)
{
	return m_buffer[row * m_columns + column];
}

std::string Cortex::Matrix::to_string()
{
	std::string matrix_string;

	for(int r = 0; r < m_rows; ++r)
	{
		for(int c = 0; c < m_columns; ++c)
		{
			if (c != 0) matrix_string += ", ";
			matrix_string += std::to_string((*this)(r, c));
		}

		matrix_string += "\n";
	}

	return matrix_string;
}