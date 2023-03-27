#pragma once
extern "C"
{
#include "REMath.h"
#include <stdio.h>
}

template<typename T>
struct Matrix
{
public:
	struct _matrix
	{
		int rows, columns;
		T** m;

		_matrix()
		{
			columns = rows = 0;
		}
		_matrix(T initVal, int rows, int columns)
			: rows(rows), columns(columns)
		{
			m = new T*[rows];
			for (int i = 0; i < rows; i++)
				m[i] = new T[columns];
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					m[i][j] = initVal;
		}
		T* operator[](int index)
		{
			return m[index];
		}
	} matrix;

public:
	void Print()
	{
		int i, j;
		for (i = 0; i < matrix.rows; i++)
		{
			for (j = 0; j < matrix.columns; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}
	}

public:
	Matrix(T initVal, int rows, int columns) 
	{
		matrix = _matrix(initVal, rows, columns);
	}

	T* operator[](int index) const
	{
		return matrix.m[index];
	}
	_matrix operator+(const Matrix& mat) const
	{
		_matrix res = _matrix(0, matrix.rows, matrix.columns);
		for (int i = 0; i < matrix.rows; i++)
			for (int j = 0; j < matrix.columns; j++)
				res[i][j] = matrix.m[i][j] + mat[i][j];
		return res;
	}
	_matrix operator-(const Matrix& mat) const
	{
		_matrix res = _matrix(0, matrix.rows, matrix.columns);
		for (int i = 0; i < matrix.rows; i++)
			for (int j = 0; j < matrix.columns; j++)
				res[i][j] = this[i][j] - mat[i][j];
		return res;
	}
	_matrix operator*(const Matrix& mat) const
	{
		if (matrix.columns != mat.matrix.rows)
			return _matrix();

		_matrix res(0, matrix.rows, mat.matrix.columns);
		for (int x = 0; x < matrix.rows; x++)
			for (int i = 0; i < mat.matrix.columns; i++)
				for (int y = 0; y < matrix.columns; y++)
					res[x][i] += matrix.m[x][y] * mat[y][i];
		return res;
	}
	_matrix operator*(float scalar) const
	{
		_matrix res(0, matrix.rows, matrix.columns);
		for (int i = 0; i < matrix.rows; i++)
			for (int j = 0; j < matrix.columns; j++)
				res = matrix[i][j] * scalar;
		return res;
	}
	_matrix operator/(float scalar) const
	{
		_matrix res(0, matrix.rows, matrix.columns);
		for (int i = 0; i < matrix.rows; i++)
			for (int j = 0; j < matrix.columns; j++)
				res = this[i][j] * scalar;
		return res;
	}
	void operator=(const Matrix& mat) 
	{
		matrix.m = mat.matrix.m;
		matrix.rows = mat.matrix.rows;
		matrix.columns = mat.matrix.columns;
	}
	void operator=(const _matrix& mat)
	{
		matrix.columns = mat.columns;
		matrix.rows = mat.rows;
		matrix.m = mat.m;
	}
	void Transpose()
	{
		_matrix mat(0, matrix.rows, matrix.columns);
		for (int i = 0; i < matrix.rows; i++)
			for (int j = 0; j < matrix.columns; j++)
				mat[j][i] = this[i][j];
		this = mat;
	}
};

