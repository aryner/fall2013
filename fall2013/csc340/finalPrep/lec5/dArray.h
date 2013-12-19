#include <iostream>

using namespace::std;

class dArray
{
public:
	dArray():size(0),maxSize(10)
	{
		try{
			items = new int[10];
		 }catch(bad_alloc e){}
	}

	dArray(dArray & ray):size(ray.size),maxSize(ray.maxSize)
	{
		try{
			items = new int[ray.maxSize];
			for(int i=0; i<ray.size; i++)
				items[i] = ray.items[i];
				
		}catch(bad_alloc e){}
	}
	~dArray()
	{
		delete [] items;
	}

	void push(int thing)
	{
		items[size] = thing;
		size++;
	}

	void operator=(const dArray & rhs)
	{
		if(size != rhs.size)
		{
			delete [] items;
			size = rhs.size;
			try{
				items = new int[maxSize];
			}catch(bad_alloc e){}
		}
		for(int i=0; i<size; i++)
			items[i] = rhs.items[i];
	}

	friend ostream & operator<<(ostream & os, const dArray rhs)
	{
		os << "<";

		for(int i=0; i<rhs.size; i++){
			os << rhs.items[i];
			if(i<rhs.size-1)
				os << ",";
		}

		os << ">";

		return os;
	}

private:
	int size;
	int maxSize;
	int *items;
};
