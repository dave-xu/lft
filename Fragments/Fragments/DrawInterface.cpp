#include "DrawInterface.h"

DrawContext::DrawContext()
	: pCanvas_(0)
{
}

DrawContext::~DrawContext()
{
}

bool DrawContext::Init(int width, int height, const std::string& name)
{
	FreeImage_Initialise();
	pCanvas_ = FreeImage_Allocate(width, height, 32, \
		FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
	if(pCanvas_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DrawContext::Flush()
{
	return FreeImage_Save(FIF_BMP, pCanvas_, "bitmap.bmp") != 0;
}

void DrawContext::Clean()
{
	FreeImage_Save(FIF_BMP, pCanvas_, "bitmap.bmp");
}

bool DrawContext::PutPixel(int x, int y, unsigned color)
{
	int height = FreeImage_GetHeight(pCanvas_);
	int width = FreeImage_GetWidth(pCanvas_);
	int bytespp = FreeImage_GetLine(pCanvas_) / FreeImage_GetWidth(pCanvas_);
	BYTE *bits = FreeImage_GetScanLine(pCanvas_, y);
	bits = &bits[bytespp*x];
	bits[FI_RGBA_RED]   = (color & 0x00ff0000) >> 16;
	bits[FI_RGBA_GREEN] = (color & 0x0000ff00) >> 8;
	bits[FI_RGBA_BLUE]  = (color & 0x000000ff);
	bits[FI_RGBA_ALPHA] = (color & 0xff000000) >> 24;
	return true;
}

