/*
  Name: list.h--consisting of the interface of List
  Copyright: 
  Author: Alex Ryner
  Date: 10/14/13
  Description: header file for a list with overloaded operators
*/

/** @file ListAexcept.h */
#ifndef _LIST_H
#define _LIST_H

#include "listException.h"
#include <iostream>

using namespace::std;

const int MAX_LIST = 20;
typedef int ListItemType;

/** @class List
 * ADT list - Array-based implementation with exceptions */
class List
{
public:
   List();
   // destructor is supplied by compiler

   /** @throw None. */
   bool isEmpty() const;

   /** @throw None. */
   int getLength() const;

   /** @throw ListIndexOutOfRangeException  If index < 1 or index >
    *         getLength() + 1.
    *  @throw ListException  If newItem cannot be placed in the list
    *         because the array is full. */
   void insert(int index, const ListItemType& newItem)
      throw(ListIndexOutOfRangeException, ListException);

   /** @throw ListIndexOutOfRangeException  If index < 1 or index >
    *         getLength(). */
   void remove(int index)
      throw(ListIndexOutOfRangeException);

   /** @throw ListIndexOutOfRangeException  If index < 1 or index >
    *         getLength(). */
   void retrieve(int index, ListItemType& dataItem) const
        throw(ListIndexOutOfRangeException);

   /** @throw ListIndexOutOfRangeException if the vectors do not have matching lengths */
   List operator+(List rightSide) const
      throw(ListIndexOutOfRangeException);

   /** @throw None. */
   List& operator++();

   /** @throw None. */
   List operator++(int blank);

   /** @throw ListIndexOutOfRangeException if the vectors do not have matching lengths */
   List operator-(List rightSide) const
      throw(ListIndexOutOfRangeException);

   /** @throw None. */
   List operator*(ListItemType rightSide) const;

   /** @throw None. */
   List operator/(ListItemType rightSide) const;

   /** @throw None. */
   friend ostream& operator<<(ostream& outputStream, const List& out);

private:
   /** array of list items */
   ListItemType items[MAX_LIST];

   /** number of items in list */
   int          size;

   int translate(int index) const;
}; // end List
// End of header file.

#endif

