#include "DrawInterface.h"

int main()
{
	DrawContext dc;
	dc.Init(256, 256, "bitmap.bmp");
	for(unsigned i = 0; i < 256; ++i)
	{
		for(unsigned j = 0; j < 256; ++j)
		{
			dc.PutPixel(i, j, 0xffff0000);
		}
	}
	dc.Flush();
	dc.Clean();
}