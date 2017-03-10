#pragma once

#include "../Fragments/DrawInterface.h"

void DDA(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc);
void MidPoint(int x0, int y0, int x1, int y1, unsigned color, DrawContext* dc);

