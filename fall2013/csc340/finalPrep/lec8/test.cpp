#include "thingy.h"
#include <string>

int main()
{
	thingy<int> test;
	for(int i=0; i<5; i++)
		test.push(i);

	cout << test.pop() << endl;

	cout << test << endl;

	thingy<string> workz;
	workz.push("one");
	workz.push("two");
	workz.push("six");

	cout << workz << endl;
}
