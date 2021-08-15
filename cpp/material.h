﻿#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material
{
public:
	virtual ~material();
	virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const = 0;
};

class lambertian : public material
{
public:
	lambertian(const color &a) : albedo(a) {}

	virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override
	{
		auto scatter_direction = rec.normal + vec3::random_unit_vector();
		scattered = ray(rec.p, scatter_direction);
		attenuation = albedo;
		return true;
	}

public:
	color albedo;
};

class metal : public material
{
public:
	metal(const color &a) : albedo(a) {}

	virtual bool scatter(
		const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const
	{
		vec3 reflected = vec3::reflect(vec3::unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected);
		attenuation = albedo;
		return (vec3::dot(scattered.direction(), rec.normal) > 0);
	}

public:
	color albedo;
};

#endif
