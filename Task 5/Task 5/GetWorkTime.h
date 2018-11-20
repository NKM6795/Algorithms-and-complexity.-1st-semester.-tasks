#pragma once


#include <time.h>
#include "Geometry.h"

template<typename T>
float getWorkTime(size_t dim, size_t dimForTransition)
{
	Matrix<T> first(dim, dim), second(dim, dim), result(dim, dim);

	first.randomFilling();
	first.resizeToTwoToThePower();
	second.randomFilling();
	second.resizeToTwoToThePower();

	clock_t timer = clock();

	result = StrassenMultiplication(first, second, dimForTransition);

	timer = clock() - timer;

	return float(timer) / CLOCKS_PER_SEC;
}