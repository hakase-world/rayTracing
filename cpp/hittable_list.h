#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable
{
public:
	//コンストラクター
	hittable_list();
	hittable_list(std::shared_ptr<hittable>);

	//アクセサー
	//std::vector<std::shared_ptr<hittable>> objects();

	//メンバ関数
	void clear();
	void add(std::shared_ptr<hittable>);

	virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

public:
	std::vector<std::shared_ptr<hittable>> objects;
};

//コンストラクター
hittable_list::hittable_list(){};
hittable_list::hittable_list(std::shared_ptr<hittable> object)
{
	add(object);
}

void hittable_list::add(std::shared_ptr<hittable> object)
{
	objects.push_back(object);
}

void hittable_list::clear()
{
	objects.clear();
}

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	auto closest_so_far = t_max;

	for (const auto &object : objects)
	{
		if (object->hit(r, t_min, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}

	return hit_anything;
}

#endif
