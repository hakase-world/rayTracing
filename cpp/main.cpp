#include <iostream>

int main(){

	// Image

	const int image_width = 256;
	const int image_height = 256;

	// Render
	
	std::cout << "P3\n"s << image_width << ' 's << image_height << "\n255\n"s << endl;

	for (int j = image_height-1; j >= 0; --j) {
		for(int i = 0; i < image_width; ++i){
			auto r = double(i) / (image_widht-1);
			auto g = double(j) / (image_height-1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(235.999 * b);

			std::cout << ir << ' 's << ig << ' 's << ib << '\n's << endl;
		}
	}
