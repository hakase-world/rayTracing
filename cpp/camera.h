﻿#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

class camera
{
private:
	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u, v, w;
	double lens_radius;

public:
	camera(point3, point3, vec3, double, double, double, double);
	ray get_ray(double, double) const;
};

camera::camera(point3 lookfrom, point3 lookat, vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist)
{
	auto theta = degrees_to_radiaans(vfov);
	auto h = std::tan(theta / 2);
	auto viewport_height = 2.0 * h;
	auto viewport_width = aspect_ratio * viewport_height;

	w = vec3::unit_vector(lookfrom - lookat);
	u = vec3::unit_vector(vec3::cross(vup, w));
	v = vec3::cross(w, u);

	origin = lookfrom;
	horizontal = focus_dist * viewport_width * u;
	vertical = focus_dist * viewport_height * v;
	lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

	lens_radius = aperture /2;
}

ray camera::get_ray(double s, double t) const
{
	vec3 rd = lens_radius * random_in_unit_disk();
	vec3 offset = u * rd.x() + v * rd.y();
	return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin-offset);
}

#endif