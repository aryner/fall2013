#include <iostream>
#include <string>

using namespace::std;

class peeps
{
public:
	peeps():name("akee"),num(42)
	{
	}

	peeps(string thing):num(42)
	{
		name = thing;
	}

	int getNum()
	{
		return num;
	}
	string getName()
	{
		return name;
	}

	void operator=(const peeps & rhs)
	{
		num = rhs.num;
		name = rhs.name;
	}

	friend ostream & operator<<(ostream & os, const peeps & peep)
	{
		os << peep.name << " " << peep.num;
		return os;
	}

private:
	int num;
	string name;

};
