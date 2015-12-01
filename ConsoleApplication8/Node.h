//*********************************************************************
//Here's the Node.h to use:
// Linkded List Node Class
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType        item;
	Node<ItemType>* next;

public:
	Node() { next = 0; }
	Node(const ItemType& anItem) { item = anItem; next = 0; }
	void setItem(const ItemType& anItem) { item = anItem; }
	void setNext(Node<ItemType>* nextNodePtr) { next = nextNodePtr; }
	ItemType &getItem() { return item; }
	Node<ItemType>* getNext() const { return next; }
};

#endif
//*********************************************************************
Use the following NEW version of LinkedList.h for HashSC, which has a new class used in it(ListIterator).
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

// the following is a Java-style iterator ADDED FOR HW#5
//    see the LinkedList class' contains function for an example of usage
template<class ItemType>
class ListIterator
{
private:
	Node<ItemType> *pcurrNode;
public:
	ListIterator() { pcurrNode = 0; }
	ListIterator(Node<ItemType> *head) { pcurrNode = head; }
	void startIterator(Node<ItemType> *head) { pcurrNode = head; }
	ItemType *next()
	{
		ItemType *currItem = &(pcurrNode->getItem());
		pcurrNode = pcurrNode->getNext();
		return currItem;
	}
	bool hasNext() { return pcurrNode != 0; }
};

template<class ItemType>
class LinkedList
{

protected:
	Node<ItemType>* headPtr; // Pointer to first node in the list
	int itemCount;           // Current count of list items
	ListIterator<ItemType> iterator; // NEW FOR HW#5

public:
	// constructor
	LinkedList() { headPtr = 0; itemCount = 0; }
	// copy constructor
	LinkedList(const LinkedList<ItemType>& aList);
	// destructor
	virtual ~LinkedList() { clear(); }

	// check for empty list
	bool isEmpty() const { return itemCount == 0; }
	// get number of entries in the list
	int size() const { return itemCount; }
	// remove all entries from list
	void clear();
	// display list from front to end
	void display() const;
	// ADDED FOR HW#5: Getting a Java-style iterator:
	ListIterator<ItemType> *getIterator()  // NEW FOR HW#5
	{
		iterator.startIterator(headPtr); return &iterator;
	}
	// abstract insert function
	virtual bool insert(const ItemType& newEntry, int newPosition = 1) = 0;

};

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original list

	if (origChainPtr == 0)
		headPtr = 0;  // Original list is empty
	else
	{
		headPtr = new Node<ItemType>();		// copy first node
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();
		while (origChainPtr != 0)
		{
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}
		newChainPtr->setNext(0);              // Flag end of list
	}
}

template<class ItemType>
void LinkedList<ItemType>::display() const
{
	Node<ItemType>* currPtr = headPtr;		// start at front of list
	while (currPtr != 0)					// walk until end of list
	{
		cout << currPtr->getItem() << " ";	// display data
		currPtr = currPtr->getNext();		// go to next node
	}
	cout << endl << endl;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	Node<ItemType> * deletePtr;
	for (int i = 0; i < itemCount; i++) // walk each node
	{
		deletePtr = headPtr;			// remove each node
		headPtr = headPtr->getNext();
		delete deletePtr;
	}
	itemCount = 0;
}
#endif
