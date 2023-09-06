#pragma once

#include <string>

namespace Cortex
{

	class Matrix
	{

	public:
		Matrix();
		Matrix(int rows, int columns);
		Matrix(const Matrix& other);
		~Matrix();

		int get_rows() const;
		int get_columns() const;
		int get_size() const;

		void reshape(int rows, int columns);

		Matrix& transpose();

		Matrix& operator=(const Matrix& right);
		Matrix& operator+=(const Matrix& right);
		Matrix& operator-=(const Matrix& right);

		Matrix& operator*=(double scale);
		Matrix& operator*=(const Matrix& other);

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
Cortex::Matrix operator-(const Cortex::Matrix& left, const Cortex::Matrix& right);

Cortex::Matrix operator*(double scale, const Cortex::Matrix& other);
Cortex::Matrix operator*(const Cortex::Matrix& other, double scale);
Cortex::Matrix operator*(const Cortex::Matrix& left, const Cortex::Matrix& right);