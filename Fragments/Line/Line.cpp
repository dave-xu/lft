#include "Line.h"

void DDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc)
{
	if(x0 == x1)
	{
		if(y0 > y1)
		{
			std::swap(y0, y1);
		}
		for(int y = y0; y <= y1; ++y)
		{
			dc->PutPixel(x0, y, color);
		}
		return;
	}
	if(x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	float dx = float(x1 - x0);
	float dy = float(y1 - y0);
	float slope = dy / dx;
	int range = x1 - x0;
	for(int i = 0; i <= range; ++i)
	{
		int x = x0 + i;
		int y = int(y0 + i * slope + 0.5f); 
		dc->PutPixel(x, y, color);
	}
}



void MidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc)
{
	if(x0 == x1)
	{
		if(y0 > y1)
		{
			std::swap(y0, y1);
		}
		for(int y = y0; y <= y1; ++y)
		{
			dc->PutPixel(x0, y, color);
		}
		return;
	}
	if(x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(std::abs(dy) <= std::abs(dx))
	{
		int d = dx - 2 * dy;
		int selLower = -2 * dy;
		int selUpper = 2 * (dx - dy);
		int x = x0;
		int y = y0;
		dc->PutPixel(x, y, 0xffff0000);
		while(x < x1)
		{
			if(d > 0)
			{
				d += selLower;
			}
			else
			{
				d += selUpper;
				++y;
			}
			++x;
			dc->PutPixel(x, y, 0xffff0000);
		}
	}
	else
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		std::swap(dx, dy);

		int d = dx - 2 * dy;
		int selLower = -2 * dy;
		int selUpper = 2 * (dx - dy);
		int x = x0;
		int y = y0;
		dc->PutPixel(y, x, 0xffff0000);
		while(x < x1)
		{
			if(d > 0)
			{
				d += selLower;
			}
			else
			{
				d += selUpper;
				++y;
			}
			++x;
			dc->PutPixel(y, x, 0xffff0000);
		}
	}
}