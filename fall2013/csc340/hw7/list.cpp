/*
  Name: list.cpp--implementing the member functions
  Copyright: 
  Author: Alex Ryner
  Date: 11/6/13
  Description: Implementing functions for a list using a dynamic array
*/


#include "list.h"  // header file

List::List() 
{
	size = 0;
	maxList = 20;
	try{
		items = new int[maxList];
	} catch (std::bad_alloc& ba) {
		cerr << "bad alloc: " << ba.what() << endl;
	}
}  // end default constructor

List::List(int len)
{
	size = 0;
	maxList = len;
	try{
		items = new int[maxList];
	} catch (std::bad_alloc& ba) {
		cerr << "bad alloc: " << ba.what() << endl;
	}
}

List::List(const List& otherList)
{
	size = 0;
	maxList = otherList.size;
	try{
		items = new int[maxList];
	} catch (std::bad_alloc& ba) {
		cerr << "bad alloc: " << ba.what() << endl;
	}

	for(int i=0;i<maxList;i++){
		items[i] = otherList.items[i];
		size++;
	}

}

List::~List()
{
	delete [] items;
}

void List::shrink()
{
	maxList /= 2;

	int *newItems;
	
	try{
		newItems = new int[maxList];
	} catch (std::bad_alloc& ba) {
		cerr << "bad alloc: " << ba.what() << endl;
	}
	
	for(int i=0;i<maxList;i++)
		newItems[i] = items[i];

	delete [] items;

	items = newItems;
}

void List::grow()
{
	maxList *= 2;

	int *newItems;

	try{
		newItems = new int[maxList];
	} catch (std::bad_alloc& ba) {
		cerr << "bad alloc: " << ba.what() << endl;
	}
	
	for(int i=0;i<maxList;i++)
		newItems[i] = items[i];

	delete [] items;

	items = newItems;
}

bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength

void List::insert(int index, const ListItemType& newItem)
   throw(ListIndexOutOfRangeException)
{
   ListIndexOutOfRangeException outOfRange("ListIndexOutOfRangeException: Bad index on insert");                                    
   if (size >= maxList){
	grow();
   }

   if (index >= 0 && index < size+1)
   {
	int pos = size-1;
	while(pos > index) {
	   items[pos+1] = items[pos];
	   pos--;
	}
	items[index] = newItem;
	size++;
   }
   else  // index out of range
      throw outOfRange;
      //ListIndexOutOfRangeException( "ListIndexOutOfRangeException: Bad index on insert");
}  // end insert


void List::remove(int index) 
     throw(ListIndexOutOfRangeException)
{
   bool success;
   ListIndexOutOfRangeException outOfRange;
   
   success = (index >= 1) && (index <= size);
   
   if (!success) throw outOfRange;
   
   if (success)
   {  // delete item by shifting all items at positions >
      // index toward the beginning of the list
      // (no shift if index == size)
      for (int fromPosition = index + 1;
	   fromPosition <= size;
	   ++fromPosition)
         items[translate(fromPosition - 1)] = items[translate(fromPosition)];
      --size;  // decrease the size of the list by one
   }  // end if

	if(size < maxList/4)
		shrink();

}  // end remove

void List::retrieve(int index, ListItemType& dataItem) const
     throw(ListIndexOutOfRangeException)
{
   bool success;
   ListIndexOutOfRangeException outOfRange;
   
   success = (index >= 1) && (index <= size);
   
   if (!success) throw outOfRange;
   
   if (success)
      dataItem = items[translate(index)];
}  // end retrieve

List List::operator+(List rightSide) const
     throw(ListIndexOutOfRangeException)
{

   ListIndexOutOfRangeException range("The vectors do not have matching lengths");

   if(size != rightSide.getLength())
	throw range;

   List result;
   ListItemType temp;

   for(int i=0; i<size; i++) {
      rightSide.retrieve(i+1,temp);
      temp += items[i];
      result.insert(i,temp);
   }

   return result;
}

List& List::operator++()
{
	for(int i=0; i<size; i++) {
		items[i] = items[i]+1;
	}
	return *this;
}

List List::operator++(int blank) 
{
	List result = *this;
	for(int i=0; i<size; i++) {
		items[i] = items[i]+1;
	}
	return result;
}

List List::operator-(List rightSide) const
     throw(ListIndexOutOfRangeException)
{
   ListIndexOutOfRangeException range("The vectors do not have matching lengths");

   if(size != rightSide.getLength())
	throw range;

   List result;
   ListItemType temp;

   for(int i=0; i<size; i++) {
      rightSide.retrieve(i+1,temp);
      temp = items[i]-temp;
      result.insert(i,temp);
   }

   return result;
}

List List::operator*(ListItemType rightSide) const
{
   List result;
   ListItemType temp;
   
   for(int i=0; i<size; i++) {
      temp = items[i] * rightSide;
      result.insert(i,temp);
   }

   return result;
}

List List::operator/(ListItemType rightSide) const
{
   List result;
   ListItemType temp;
   
   for(int i=0; i<size; i++) {
      temp = items[i] / rightSide;
      result.insert(i,temp);
   }

   return result;
}

void List::operator=(const List& rightSide)
{
	int newSize = rightSide.maxList;

	if(newSize != maxList) {
		delete []items;
		maxList = newSize;
		try{
			items = new int[newSize];
		} catch (std::bad_alloc& ba) {
			cerr << "bad alloc: " << ba.what() << endl;
		}
	}

	for(int i=0;i<newSize;i++){
		items[i] = rightSide.items[i];
	}
	size = rightSide.size;
}

ostream& operator<<(ostream& outputStream, const List& out)
{
   outputStream << "<";
   int leng = out.getLength();
   ListItemType data;
   for(int i=0; i<leng; i++){
      out.retrieve(i+1,data);
      outputStream << out.items[i];
      if (i<leng-1)
         outputStream << ",";
   }
   outputStream << ">" ;
   return outputStream;
}

int List::translate(int index) const
{
    return index-1;
}

