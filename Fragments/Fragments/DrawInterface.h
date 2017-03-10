#pragma once

#include "../FreeImage/FreeImage.h"
#include <string>

#pragma comment(lib, "../FreeImage/FreeImageLibd.lib")

class DrawContext
{
public:
	DrawContext();
	virtual ~DrawContext();
	bool Init(int width, int height, const std::string& name);
	bool Flush();
	void Clean();

public:
	bool PutPixel(int x, int y, unsigned color);

private:
	FIBITMAP* pCanvas_;
};
