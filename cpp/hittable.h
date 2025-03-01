﻿#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class material;

struct hit_record
{
	point3 p;
	vec3 normal;
	std::shared_ptr<material> mat_ptr;
	double t;
	bool front_face;

	inline void set_face_nomal(const ray&r, const vec3&outward_nomal){
		front_face = vec3::dot(r.direction(),outward_nomal) < 0;
		normal = front_face ? outward_nomal : -outward_nomal;
	}
};

class hittable
{
public:
	virtual bool hit(const ray&r,double t_min,double t_max,hit_record&rec)const=0;
};

#endif
