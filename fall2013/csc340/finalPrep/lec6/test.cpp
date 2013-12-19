#include "linked.h"

int main() 
{
	linked test;

	for(int i=0; i<10; i++)
		test.push(i);

	cout << test << endl;
}
