#pragma once
// Linked List ADT
// This list allows the user to insert and remove data at a specified position
// By CNguyen

#ifndef LIST
#define LIST

#include "LinkedList.h"
#include "Node.h"

template<class ItemType>
class List : public LinkedList<ItemType>  // derived from abstract LinkedList class
{
private:
	// Finds node at a specified position
	Node<ItemType>* getNodeAt(int position) const;

public:
	// Adds node at a specified position
	bool insert(const ItemType& newEntry, int newPosition = 1);
	// Removes node at a specified position
	bool remove(int position);
	// Removes first occurrence of entry and returns it
	ItemType &remove(const ItemType& anEntry); //**********YOU WRITE**************
											   // Passes back node at a specified position
	bool getEntry(int position, ItemType & anEntry) const;
};


template<class ItemType>
bool List<ItemType>::insert(const ItemType& newEntry, int newPosition)
{
	// check valid position
	if (newPosition < 1 || newPosition > itemCount + 1)
		return false;

	// create new node for newEntry
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	if (newPosition == 1)   // insert new node at beginning
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else  // insert new node in middle or end of list
	{
		Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);  // go to position
		newNodePtr->setNext(prevPtr->getNext());
		prevPtr->setNext(newNodePtr);
	}
	itemCount++;
	return true;
}


template<class ItemType>
bool List<ItemType>::remove(int position)
{
	// check for valid position
	if (position < 1 || position > itemCount)
		return false;

	Node<ItemType>* deletePtr = 0;
	if (position == 1)   // remove first node
	{
		deletePtr = headPtr;
		headPtr = headPtr->getNext();
	}
	else   // remove from middle or end of list
	{
		Node<ItemType>* prevPtr = getNodeAt(position - 1); // get to position
		deletePtr = prevPtr->getNext();		// remove from list
		prevPtr->setNext(deletePtr->getNext());
	}
	delete deletePtr;
	itemCount--;
	return true;
}

template<class ItemType>
bool List<ItemType>::getEntry(int position, ItemType & anEntry) const
{
	if (position < 1 || position > itemCount)
		return false;

	Node<ItemType>* copyPtr = getNodeAt(position); // get to position
	anEntry = copyPtr->getItem();
	return true;
}


template<class ItemType>
Node<ItemType>* List<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* curPtr = headPtr;
	for (int i = 1; i < position; i++)
		curPtr = curPtr->getNext();
	return curPtr;
}

#endif