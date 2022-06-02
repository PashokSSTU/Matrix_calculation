#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>

struct Matrix_Size;
class Matrix;

bool operator==(const Matrix_Size size1, const Matrix_Size size2);
bool operator!=(const Matrix_Size size1, const Matrix_Size size2);
std::ostream& operator<<(std::ostream& out, const Matrix& obj);


struct Matrix_Size
{
	unsigned int rows;
	unsigned int columns;

	friend bool operator==(const Matrix_Size size1, const Matrix_Size size2);
	friend bool operator!=(const Matrix_Size size1, const Matrix_Size size2);
};

typedef Matrix_Size matrix_size_t;

class Matrix
{
public:
	
	Matrix(unsigned int rows = 3, unsigned int columns = 3) : size({ rows, columns })
	{
		matrix.resize(rows);

		for (int j = 0; j < rows; j++)
		{
			matrix[j].resize(columns);
		}
	}

	Matrix(const Matrix& _matrix)
	{
		if (this->size != _matrix.size)
		{
			this->size = _matrix.size;

			matrix.resize(_matrix.size.columns);

			for (int j = 1; j <= _matrix.size.columns; j++)
			{
				matrix.resize(_matrix.size.rows);
			}

			for (int i = 0; i < size.rows; i++)
			{
				for (int j = 0; j < size.columns; j++)
				{
					matrix[i][j] = _matrix.matrix[i][j];
				}
			}
		}
		else
		{

		}
	}

	Matrix(const std::initializer_list<std::initializer_list<double>>& list) : size({ list.size(), 0 })
	{
		for (auto& x : list)
			if (x.size() > size.columns)
				size.columns = x.size();
		
		matrix.resize(size.rows);
		for (int i = 0; i < size.rows; i++)
		{
			matrix[i].resize(size.columns);
		}

		auto it = list.begin();
		for (int i = 0; i < size.rows; i++, it++)
		{
			std::copy(it->begin(), it->end(), matrix[i].begin());
		}
	}

	~Matrix()
	{
	}

	void print();

	double& operator()(int i, int j);
	Matrix& operator=(const Matrix& obj);
	Matrix& operator=(std::initializer_list<std::initializer_list<double>> &l);

	friend std::ostream& operator<<(std::ostream& out ,const Matrix& obj);
	


private:
	matrix_size_t size;
	std::vector<std::vector<double>> matrix;
};