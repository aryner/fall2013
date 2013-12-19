#include <iostream>
#include <list>

using namespace::std;

int main() 
{
	list<int> container;
	for(int i=0; i<10; i++)
		container.push_back(i);

	list<int> container2;
	for(int i=0; i<10; i++)
		container2.push_back(i);

	list<int>::iterator p;

	for(p=container.begin(); p!=container.end(); p++){
		cout << *p;
		cout << " ";
	}
	cout << endl;
/*
	list<int>::iterator q = container.begin();
	container.splice(q, container2);
*/

	container.merge(container2);
	container.unique();

	container.sort(greater<int>());

	for(p=container.begin(); p!=container.end(); p++){
		cout << *p;
		cout << " ";
	}
	cout << endl;

}
