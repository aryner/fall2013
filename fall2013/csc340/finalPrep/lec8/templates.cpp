#include <iostream>
#include <string>
#include <list>

using namespace::std;

template <class T>
void swap(T & x, T & y) 
{
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
void display(T param)
{
	cout << param;
}

template <class T, class S>
S & getFirst(T container, S & value)
{
	value = *container.begin();
	return value;
}

int main() 
{

	display(10);
	cout << endl;
	display("hello");
	cout << endl;

	string one("one");
	string two = "two";

	swap(one,two);
	display(one);
	cout << endl;

	list<int> myList;
	myList.push_front(42);
	int x;
	cout << getFirst(myList, x) << endl;
}
