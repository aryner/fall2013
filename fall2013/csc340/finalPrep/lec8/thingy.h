#include <iostream>
#include <string>

using namespace::std;

template <typename T>
class thingy
{
public:
	thingy():size(0)
	{
	}

	void push(T thing)
	{
		list[size] = thing;
		size++;
	}

	T pop()
	{
		size--;
		return list[size];
	}

	friend ostream & operator<<(ostream & os , const thingy<T> & x)
	{
		os << "<";
		for(int i=0; i<x.size; i++)
		{
			os << x.list[i];
			if(i<x.size-1)
				os << ",";
		}
		os << ">";
		return os;
	}


private:
	T list[10];
	int size;
};
