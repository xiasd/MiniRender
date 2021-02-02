
#include "Image.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream>
const unsigned int white[4] = { 255, 255, 255, 255 };
const unsigned int red[4] = { 255, 0, 0, 255 };
const unsigned int black[4] = { 0, 0, 0, 255 };


void line(int x0, int y0, int x1, int y1,Image img,const unsigned int* color) {
	bool steep = false;
	if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}
	if (x0 > x1) {
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int dx = x1 - x0;
	int dy = y1 - y0;

	int derror = 2 * std::abs(dy);
	int error = 0;

	int y = y0;

	for (int x = x0; x <= x1; x++) {
		if (steep) {
			img.set(y, x, color);
		}
		else {
			img.set(x, y, color);
		}
		error += derror;
		if (error > dx) {
			y += y1>y0?1:-1;
			error -= 2 * dx;
		}
	}
}

int main() {
	Image image(1000, 1000, "line.png");
	line(100, 100, 900, 900, image, black);
	line(200, 130, 400, 800, image, red);
	line(800, 400, 130, 200, image, red);
	image.save();
	std::cout << unsigned char(255);
	return 0;
}

