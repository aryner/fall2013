#include "peeps.h"

class cycler:public peeps
{
public:
	cycler():peeps(),bike("fixie")
	{
	}

	cycler(string x):peeps(x),bike("fixie")
	{
	}

	string getBike()
	{
		return bike;
	}

	void operator=(const cycler & rhs) 
	{
		peeps::operator=(rhs);
		bike = rhs.bike;
	}


private:
	string bike;
};
