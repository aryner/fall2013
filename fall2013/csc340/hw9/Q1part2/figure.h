#ifndef _FIGURE_H
#define _FIGURE_H

#include <iostream>

using std::cout;
using std::endl;

class Figure
{
public:
	//constructor
	Figure();

	//member functions
	virtual void draw();
	virtual void erase();
	void center();
};

#endif
