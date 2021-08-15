#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
class vec3
{
private:
	double e[3];

public:
	//コンストラクター
	vec3(double e0 = 0., double e1 = 0., double e2 = 0.);
	//デストラクター
	~vec3();
	//アクセサー
	double x() const;
	double y() const;
	double z() const;
	//演算子のオーバーロード
	vec3 operator-() const;			//正負の反転
	double operator[](int i) const; //コピーを返却（オブジェクトがconst修飾されたら）
	double &operator[](int i);		//リファレンスを返却

	vec3 &operator+=(const vec3 &); //各要素に加算および代入
	vec3 &operator*=(const double); //各要素に乗算および代入
	vec3 &operator/=(const double); //各要素に除算および代入

	//ベクトルの長さを得る
	double length() const;
	double length_squared() const;

	//ユーティリティ関数群
	//	inline std::ostream& operator<<(std::ostream);

	inline vec3 operator+(const vec3 &v) const;
	inline vec3 operator-(const vec3 &v) const;
	inline vec3 operator*(const vec3 &v) const;
	inline vec3 operator*(const double) const;
	inline vec3 operator/(const vec3 &v) const;
	inline vec3 operator/(double) const;

	static inline double dot(const vec3 &u, const vec3 &v);
	static inline vec3 cross(const vec3 &u, const vec3 &v);
	static inline vec3 unit_vector(const vec3 &v);
	inline static vec3 random();
	inline static vec3 random(double, double);
	static vec3 random_in_unit_sphere();
	inline static vec3 random_unit_vector();
};

//コンストラクター
vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
//デストラクター
vec3::~vec3() {}

//アクセサー
double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

//演算子のオーバーロード
vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }
double vec3::operator[](int i) const { return e[i]; }
double &vec3::operator[](int i) { return e[i]; }

vec3 &vec3::operator+=(const vec3 &v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}
vec3 &vec3::operator*=(const double t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
vec3 &vec3::operator/=(const double t)
{
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;
	return *this;
}

//ベクトルの長さを得る
double vec3::length() const { return std::sqrt(length_squared()); }
double vec3::length_squared() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

//ユーティリティ関数群
//inline std::ostream& vec3::operator<<(std::ostream&out){return out  << v.e[0] <<' '<< v.e[1] <<' '<< v.e[2];}
inline std::ostream &operator<<(std::ostream &out, const vec3 &v) { return out << v.x() << ' ' << v.y() << ' ' << v.z(); }

inline vec3 vec3::operator+(const vec3 &v) const { return vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]); }
inline vec3 vec3::operator-(const vec3 &v) const { return vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]); }
inline vec3 vec3::operator*(const vec3 &v) const { return vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]); }
inline vec3 vec3::operator*(const double t) const { return vec3(e[0] * t, e[1] * t, e[2] * t); }
inline vec3 vec3::operator/(const vec3 &v) const { return vec3(e[0] / v.e[0], e[1] / v.e[1], e[2] / v.e[2]); }
inline vec3 vec3::operator/(double t) const { return vec3(e[0] / t, e[1] / t, e[2] / t); }

inline vec3 operator*(double t, const vec3 &v) { return vec3(t * v.x(), t * v.y(), t * v.z()); }

inline double vec3::dot(const vec3 &u, const vec3 &v) { return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2]; }
inline vec3 vec3::cross(const vec3 &u, const vec3 &v) { return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], u.e[2] * v.e[0] - u.e[0] * v.e[2], u.e[0] * v.e[1] - u.e[1] * v.e[0]); }
inline vec3 vec3::unit_vector(const vec3 &v) { return v / v.length(); }
inline vec3 vec3::random()
{
	return vec3(random_double(), random_double(), random_double());
}
inline vec3 vec3::random(double min, double max)
{
	return vec3(
		random_double(min, max),
		random_double(min, max),
		random_double(min, max));
}

vec3 vec3::random_in_unit_sphere()
{
	while (true)
	{
		auto p = vec3::random(-1, 1);
		if (p.length_squared() >= 1)
			continue;
		return p;
	}
}

inline vec3 vec3::random_unit_vector()
{
	return unit_vector(random_in_unit_sphere());
}

// vec3の型エイリアス

using point3 = vec3; // 三次元の点
using color = vec3;	 // 光の三原色

#endif
