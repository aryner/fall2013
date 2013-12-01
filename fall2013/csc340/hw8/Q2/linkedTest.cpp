/*
author: Alex Ryner
date: 12/01/13
description: a test of the linked list adt
*/

#include "linkedList_structNode.h"
#include <iostream>

using namespace::std;

int main() {
	List one;

	cout << "List one is: " << one << endl;

	one.insert(10);
	one.insert(9);
	one.insert(3);
	one.insert(7);
	one.insert(1);
	one.insert(6);

	cout << "After inserting 10,9,3,7,1,6 in that order one is: " << one << endl;

	int three = 3;

	cout << "one.retrieve(3) returns: " << one.retrieve(three) << endl;

	one.remove(3);
	one.remove(9);

	cout << "After removing 3 and 9: " << one << endl;

	cout << "Now one.retrieve(3) returns: " << one.retrieve(three) << endl;

	
}
