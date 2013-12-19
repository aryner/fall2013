#include "dArray.h"

int main()
{
	dArray one;
	for(int i=0; i<10; i++)
		one.push(i);

	cout << one << endl;

	dArray two(one);

	cout << two << endl;
	
	dArray three;

	three = two;

	cout << three << endl;
}
