#include "cycler.h"

int main() 
{
	cycler test("Alex");

	cout << test << endl;
	cout << test.getNum() << " " << test.getName() << " " << test.getBike() << endl;

	cycler test2;
	test2 = test;
	cout << test2 << endl;
}
