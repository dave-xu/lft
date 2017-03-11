#include "Line.h"
#include "../Fragments/DrawInterface.h"

int main()
{
	DrawContext dc;
	dc.Init(512, 512, "bitmap.bmp");
	//DDA(		20, 40, 40, 20, 0xffffff00, &dc);

	MidPoint(	20, 40, 20, 20, 0xffff0000, &dc);
	MidPoint(	25, 40, 25, 80, 0xffff0000, &dc);
	MidPoint(	28, 35, 48, 35, 0xffff0000, &dc);
	MidPoint(	58, 60, 48, 60, 0xffff0000, &dc);

	MidPoint(	20, 40, 50, 100, 0xffff0000, &dc);
	MidPoint(	20, 40, 50, 50, 0xffff0000, &dc);
	MidPoint(	20, 40, 40, 20, 0xffff0000, &dc);
	MidPoint(	20, 40, 50, 20, 0xffff0000, &dc);
	dc.Flush();
	return 0;
}