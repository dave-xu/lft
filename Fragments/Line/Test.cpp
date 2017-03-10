#include "Line.h"
#include "../Fragments/DrawInterface.h"

int main()
{
	DrawContext dc;
	dc.Init(512, 512, "bitmap.bmp");
	DDA(		20, 20, 200, 210, 0xffffff00, &dc);
	MidPoint(	20, 20, 200, 210, 0xffff0000, &dc);
	dc.Flush();
	return 0;
}