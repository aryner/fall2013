#include "array.h"
#include <iostream>

using namespace::std;

int main() 
{
	Array<int> intArray(10);

	for(int i=0; i<10; i++)
		intArray.append(i);

	cout << "After appending numbers 0-8 to an int array it contains:" << endl;
	cout << intArray << endl;

	intArray.remove(6);
	cout << "After removing index 6:" << endl;
	cout << intArray << endl;

	Array<char> sArray(5);

	sArray.append('a');
	sArray.append('b');
	sArray.append('c');
	sArray.append('d');


	cout << "the char array is initialized to : " << endl;
	cout << sArray << endl;

	sArray.remove(3);
	cout << "After removing index 3: " << endl;
	cout << sArray << endl;

}
