#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
private:
	point3 orig;
	vec3 dir;
public:
//コンストラクター
	ray();
	ray(const point3&,const vec3&);
//デストラクター
	~ray();

//アクセサー
void origin(const point3 origin){orig=origin;}
point3 origin()const{return orig;}

void direction(const vec3 direction){dir=direction;}
vec3 direction()const{return dir;}

//メンバ関数
point3 at(double)const;

};

ray::ray(){}
ray::ray(const point3&origin,const vec3&direction)
:orig(origin),dir(direction){}

ray::~ray(){}

point3 ray::at(const double t)const{
	return orig+dir*t;
}

#endif
