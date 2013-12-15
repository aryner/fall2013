#include <iostream>
#include <string>

using namespace::std;

template<class T>

void swapin(T & one, T & two)
{
	T temp = one;
	one = two;
	two = temp;
}

int main()
{
	int int1 = 1, int2 = 2;
	string string1 = "one", string2 = "two";

	cout << "int1 = " << int1 << " int2 = " << int2 << " string1 = " << string1 << " string2 = " << string2 << endl;

	swapin(int1, int2);
	swapin(string1, string2);

	cout << "After swapinping:" << endl;
	cout << "int1 = " << int1 << " int2 = " << int2 << " string1 = " << string1 << " string2 = " << string2 << endl;
}
