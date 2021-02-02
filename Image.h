#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "svpng.inc"

class Image {
private:
	int w;
	int h;
	unsigned char* p;
	FILE* fp;
public:
	Image(int width, int height, const char* save_path);
	void set(int x, int y, const unsigned int* color);
	void save();
//	~Image();
};

Image::Image(const int width, const int height, const char* save_path) {
	w = width;
	h = height;
	p = new unsigned char[width * height * 4 * sizeof(char)]();
	//if (p)
		//memset(p, 0, width * height * 4 * sizeof(char));
	fp = fopen(save_path, "wb");
}

void Image::set(int x, int y, const unsigned int* color) {
	p[(y * w + x) * 4] = (unsigned char)color[0];
	p[(y * w + x) * 4 + 1] = (unsigned char)color[1];
	p[(y * w + x) * 4 + 2] = (unsigned char)color[2];
	p[(y * w + x) * 4 + 3] = (unsigned char)color[3];
}

void Image::save() {
	svpng(fp, w, h, p, 1);
	fclose(fp);
	delete[]p;
}

/*
Image::~Image() {
	delete[]p;
}
*/
