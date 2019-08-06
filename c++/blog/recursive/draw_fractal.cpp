#include <iostream>

using namespace std;

void drawTriangle(double x, double y, double w, double h)
{
	// {[x1, y1] - start point, [x2, y2] - right point, [x3, y3] - top point, [x1, y1] - end point, same as start point}
	int coordinates[] = {x, y, x+w, y, x+w/2, y+h, x, y};
}

void drawFractal(double x, double y, double w, double h)
{
	drawTriangle(x, y, w, h);

	if (w < .2 || h < .2)
		return;

	double halfH = h/2;
	double halfW = w/2;

	drawFractal(x, y, halfW, halfH); // left
	drawFractal(x + halfW/2, y + halfH, halfW, halfH); // top
	drawFractal(x + halfW, y, halfW, halfH); // right
}

void main()
{
	drawFractal(0, 0, 100, 100);
}
