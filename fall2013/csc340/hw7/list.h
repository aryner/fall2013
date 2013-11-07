/*
  Name: list.h--consisting of the interface of List
  Copyright: 
  Author: Alex Ryner
  Date: 11/16/13
  Description: header file for a list using a dynamic array
*/

/** @file ListAexcept.h */
#ifndef _LIST_H
#define _LIST_H

#include "listException.h"
#include <iostream>

using namespace::std;

typedef int ListItemType;

/** @class List
 * ADT list - Array-based implementation with exceptions */
class List
{
public:
   List();

   List(int len);

   List(const List& otherList);

   ~List();

   /** @throw None. */
   bool isEmpty() const;

   /** @throw None. */
   int getLength() const;

   /** @throw ListIndexOutOfRangeException  If index < 1 or index >
    *         getLength() + 1.*/
   void insert(int index, const ListItemType& newItem)
      throw(ListIndexOutOfRangeException);

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

   void operator=(const List& rightSide);

   /** @throw None. */
   friend ostream& operator<<(ostream& outputStream, const List& out);

private:
   /** array of list items */
   ListItemType* items;

   void grow();

   void shrink();

   int maxList;
   /** number of items in list */
   int          size;

   int translate(int index) const;
}; // end List
// End of header file.

#endif

