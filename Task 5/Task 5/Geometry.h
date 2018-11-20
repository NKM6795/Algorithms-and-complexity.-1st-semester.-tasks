#pragma once


#include <vector>


using namespace std;


//Matrix
template<typename T>
class Matrix
{
	size_t dimRows, dimCols;
	vector<vector<T> > matrix;

public:
	Matrix(size_t dimRows, size_t dimCols) : dimRows(dimRows), dimCols(dimCols)
	{
		matrix = vector<vector<T> >(dimRows, vector<T>(dimCols, 0));
	}

	vector<T> &operator [] (const size_t i)
	{
		return matrix[i];
	}

	const vector<T> &operator [] (const size_t i) const
	{
		return matrix[i];
	}

	vector<T> col(const size_t i) const
	{
		vector<T> result(dimRows);

		for (size_t j = dimRows; j--; result[j] = matrix[j][i]);

		return result;
	}

	size_t getDimRows() const
	{
		return dimRows;
	}

	size_t getDimCols() const
	{
		return dimCols;
	}

	void randomFilling()
	{
		for (size_t i = dimRows; i--; )
		{
			for (size_t j = dimCols; j--; matrix[i][j] = T(rand() % 1000000) / 100);
		}
	}

	void resizeToTwoToThePower()
	{
		size_t dim = dimRows;
		size_t power = 1;
		while (dim > 1)
		{
			++power;
			dim /= 2;
		}

		while (power != 0)
		{
			--power;
			dim *= 2;
		}

		Matrix<T> result(dim, dim);

		for (size_t i = dimRows; i--; )
		{
			for (size_t j = dimCols; j--; result[i][j] = matrix[i][j]);
		}

		*this = result;
	}

	vector<Matrix<T> > getDivisionIntoFourBlocks() const
	{
		vector<Matrix<T> > result(4, Matrix<T>(dimRows / 2, dimCols / 2));

		for (size_t i = 0; i < dimRows; ++i)
		{
			for (size_t j = 0; j < dimCols; ++j)
			{
				if (i < dimRows / 2 && j < dimCols / 2)
				{
					result[0][i][j] = matrix[i][j];
				}
				else if (i >= dimRows / 2 && j < dimCols / 2)
				{
					result[1][i - dimRows / 2][j] = matrix[i][j];
				}
				else if (i < dimRows / 2 && j >= dimCols / 2)
				{
					result[2][i][j - dimCols / 2] = matrix[i][j];
				}
				else if (i >= dimRows / 2 && j >= dimCols / 2)
				{
					result[3][i - dimRows / 2][j - dimCols / 2] = matrix[i][j];
				}
			}
		}

		return result;
	}

	void setUnion(vector<Matrix<T> > matrixs)
	{
		Matrix<T> result(dimRows, dimCols);

		for (size_t i = 0; i < dimRows; ++i)
		{
			for (size_t j = 0; j < dimCols; ++j)
			{
				if (i < dimRows / 2 && j < dimCols / 2)
				{
					result[i][j] = matrixs[0][i][j];
				}
				else if (i >= dimRows / 2 && j < dimCols / 2)
				{
					result[i][j] = matrixs[1][i - dimRows / 2][j];
				}
				else if (i < dimRows / 2 && j >= dimCols / 2)
				{
					result[i][j] = matrixs[2][i][j - dimCols / 2];
				}
				else if (i >= dimRows / 2 && j >= dimCols / 2)
				{
					result[i][j] = matrixs[3][i - dimRows / 2][j - dimCols / 2];
				}
			}
		}

		*this = result;
	}
};


template<typename T>
T operator * (const vector<T> &left, const vector<T> &right)
{
	T result = T();

	for (size_t i = left.size(); i--; result += left[i] * right[i]);

	return result;
}


//Operations with Matrix
template <typename T>
Matrix<T> operator * (const Matrix<T> &left, const Matrix<T> &right)
{
	size_t dimRows = left.getDimRows(),
		dimCols = right.getDimCols();

	Matrix<T> result(dimRows, dimCols);

	for (size_t i = left.getDimRows(); i--; )
	{
		for (size_t j = right.getDimCols(); j--; result[i][j] = left[i] * right.col(j));
	}

	return result;
}

template <typename T>
Matrix<T> operator + (const Matrix<T> &left, const Matrix<T> &right)
{
	Matrix<T> result(left.getDimRows(), right.getDimCols());

	for (size_t i = left.getDimRows(); i--; )
	{
		for (size_t j = left.getDimCols(); j--; result[i][j] = left[i][j] + right[i][j]);
	}

	return result;
}

template <typename T>
Matrix<T> operator - (const Matrix<T> &left, const Matrix<T> &right)
{
	Matrix<T> result(left.getDimRows(), right.getDimCols());

	for (size_t i = left.getDimRows(); i--; )
	{
		for (size_t j = left.getDimCols(); j--; result[i][j] = left[i][j] - right[i][j]);
	}

	return result;
}

template <typename T>
Matrix<T> StrassenMultiplication(const Matrix<T> &left, const Matrix<T> &right, size_t dimForTransition)
{
	if (left.getDimRows() <= dimForTransition)
	{
		return left * right;
	}
	
	vector<Matrix<T> > leftMatrixs = left.getDivisionIntoFourBlocks(),
		rightMatrixs = right.getDivisionIntoFourBlocks();

	vector<Matrix<T> > pMatrixs(7, Matrix<T>(left.getDimRows() / 2, left.getDimCols() / 2));

	pMatrixs[0] = StrassenMultiplication(leftMatrixs[0] + leftMatrixs[3], rightMatrixs[0] + rightMatrixs[3], dimForTransition);
	pMatrixs[1] = StrassenMultiplication(leftMatrixs[2] + leftMatrixs[3], rightMatrixs[0], dimForTransition);
	pMatrixs[2] = StrassenMultiplication(leftMatrixs[0], rightMatrixs[1] - rightMatrixs[3], dimForTransition);
	pMatrixs[3] = StrassenMultiplication(leftMatrixs[3], rightMatrixs[2] - rightMatrixs[0], dimForTransition);
	pMatrixs[4] = StrassenMultiplication(leftMatrixs[0] + leftMatrixs[1], rightMatrixs[3], dimForTransition);
	pMatrixs[5] = StrassenMultiplication(leftMatrixs[2] - leftMatrixs[0], rightMatrixs[0] + rightMatrixs[1], dimForTransition);
	pMatrixs[6] = StrassenMultiplication(leftMatrixs[1] - leftMatrixs[3], rightMatrixs[2] + rightMatrixs[3], dimForTransition);

	vector<Matrix<T> > preResult(4, Matrix<T>(left.getDimRows() / 2, left.getDimCols() / 2));

	preResult[0] = pMatrixs[0] + pMatrixs[3] - pMatrixs[4] + pMatrixs[6];
	preResult[1] = pMatrixs[2] + pMatrixs[4];
	preResult[2] = pMatrixs[1] + pMatrixs[3];
	preResult[3] = pMatrixs[0] - pMatrixs[1] + pMatrixs[2] + pMatrixs[5];

	Matrix<T> result(left.getDimRows(), right.getDimCols());

	result.setUnion(preResult);
	return result;
}


template <typename T>
ostream &operator << (ostream& os, Matrix<T> &matrix)
{
	for (size_t i = 0; i < matrix.getDimRows(); ++i)
	{
		for (size_t j = 0; j < matrix.getDimCols(); ++j)
		{
			os << matrix[i][j] << ' ';
		}
		os << '\n';
	}

	return os;
}
