/*
author: Alex Ryner
date: 12/01/13
description: A test of the linked list adt
*/

#include "linkedList_structNode.h"
#include <iostream>

using namespace::std;

int main() {
	List one, two;

	try{
		for(int i=1; i<10; i++) {
			one.insert(i,i);
		}
	}
	catch(...) {}

	cout << "List one is: " << one << endl;
	cout << "List two is: " << two << endl;

	two = one;

	cout << "After setting two = one, two is: " << two << endl;

	one.reverse();

	cout << "After calling one.reverse(), one is: " << one << endl;

}
