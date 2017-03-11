#include "Line.h"

void NoFlip(int x, int y, int& xout, int& yout)
{
	xout = x;
	yout = y;
}

void SlashFlip(int x, int y, int& xout, int& yout)
{
	xout = y;
	yout = x;
}

void FlipPutPixel(int x, int y, unsigned color, DrawContext* dc, FlipFunc flip)
{
	int xout, yout;
	flip(x, y, xout, yout);
	dc->PutPixel(xout, yout, color);
}

int Round(float i)
{
	if(i >= 0)
	{
		return int(i + 0.5f);
	}
	else
	{
		return int(i - 0.5f);
	}
}

void DDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc)
{
	if(x0 == x1 && y0 == y1)
	{
		dc->PutPixel(x0, y0, color);
		return;
	}
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(std::abs(dy) > std::abs(dx))
	{
		int xout0, yout0, xout1, yout1;
		SlashFlip(x0, y0, xout0, yout0);
		SlashFlip(x1, y1, xout1, yout1);
		XBiasDDA(xout0, yout0, xout1, yout1, color, dc, SlashFlip);
	}
	else
	{
		XBiasDDA(x0, y0, x1, y1, color, dc, NoFlip);
	}
}

void XBiasDDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc, FlipFunc flip)
{
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
		float y = y0 + i * slope;
		y = Round(y);
		FlipPutPixel(x, y, color, dc, flip);
	}
}

void MidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc)
{
	if(x0 == x1 && y0 == y1)
	{
		dc->PutPixel(x0, y0, color);
		return;
	}
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(std::abs(dy) > std::abs(dx))
	{
		int xout0, yout0, xout1, yout1;
		SlashFlip(x0, y0, xout0, yout0);
		SlashFlip(x1, y1, xout1, yout1);
		XBiasSlopWithinOneMidPoint(xout0, yout0, xout1, yout1, color, dc, SlashFlip);
	}
	else
	{
		XBiasSlopWithinOneMidPoint(x0, y0, x1, y1, color, dc, NoFlip);
	}
}


void XBiasSlopWithinOneMidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc, FlipFunc flip)
{
	if(x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(dy >= 0)
	{
		int d = dx - 2 * dy;
		int selLower = -2 * dy;
		int selUpper = 2 * (dx - dy);
		int x = x0;
		int y = y0;
		FlipPutPixel(x, y, color, dc, flip);
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
			FlipPutPixel(x, y, color, dc, flip);
		}
	}
	else
	{
		int d = -dx - 2 * dy;
		int selLower = -2 * (dx + dy);
		int selUpper = -2 * dy;
		int x = x0;
		int y = y0;
		FlipPutPixel(x, y, color, dc, flip);
		while(x < x1)
		{
			if(d > 0)
			{
				d += selLower;
				--y;
			}
			else
			{
				d += selUpper;
			}
			++x;
			FlipPutPixel(x, y, color, dc, flip);
		}
	}
}