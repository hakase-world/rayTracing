#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

//定数
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//ユーティリティ関数
inline double degrees_to_radiaans(double degrees)
{
	return degrees * pi / 180.0;
}

//共通ヘッダー
#include "ray.h"
#include "vec3.h"

#endif