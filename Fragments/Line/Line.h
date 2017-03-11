#pragma once

#include "../Fragments/DrawInterface.h"

typedef void (*FlipFunc)(int x, int y, int& xout, int& yout);

void NoFlip(int x, int y, int& xout, int& yout);
void SlashFlip(int x, int y, int& xout, int& yout);

FlipFunc AccmFlip(FlipFunc a, FlipFunc b);

void FlipPutPixel(int x, int y, unsigned color, DrawContext* dc, FlipFunc flip);

int Round(float i);

void DDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc);
void XBiasDDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc, FlipFunc flip);
void MidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc);
void XBiasSlopWithinOneMidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc, FlipFunc flip);

