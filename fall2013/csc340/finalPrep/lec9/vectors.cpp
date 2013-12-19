#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	vector<int> container;
	for(int i=0; i<10;i++)
		container.push_back(i);

	vector<int>::iterator p;

	for(p = container.begin(); p!=container.end();p++){
		cout << *p;
		cout << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator q;

	for(q = container.rbegin(); q!=container.rend();q++){
		cout << *q;
		cout << " ";
		cout << q[3];
	}
	cout << endl;
/*
	container.erase(container.begin()+=5, container.end()-=2);

	for(p = container.begin(); p!=container.end();p++){
		cout << *p;
		cout << " ";
	}
	cout << endl;
*/
}
