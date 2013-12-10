#include "figure.h"

Figure::Figure()
{
}

void Figure::draw()
{
	cout << "Drawing a figure..." << endl;
}

void Figure::erase()
{
	cout << "Erasing the figure..." << endl;
}

void Figure::center()
{
	draw();
	erase();
	cout << "Center was called" << endl;
}


