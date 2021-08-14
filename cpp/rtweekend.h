#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

//定数
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//ユーティリティ関数
inline double degrees_to_radiaans(double degrees)
{
	return degrees * pi / 180.0;
}

inline double random_double()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937_64 generator;
	return distribution(generator);
}

inline double random_double(double min, double max)
{
	// Returns a randodm real in [min,max].
	return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max)
{
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}

//共通ヘッダー
#include "ray.h"
#include "vec3.h"

#endif