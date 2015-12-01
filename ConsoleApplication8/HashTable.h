//*********************************************************************
//USE THE FOLLOWING AS A BASE CLASS FOR ALL HASH TABLE CLASSES:
#pragma once
template <class Object>
class HashTable
{
protected:
	int(*Hash)(const Object&obj);
	int(*Compare)(const Object&left, const Object&right);
	int collisionCount;
	int longestCollisionRun;

public:
	HashTable(int(*hashFcn)(const Object &obj),
		int(*comp)(const Object&left, const Object&right)) {
		Hash = hashFcn; Compare = comp; collisionCount = longestCollisionRun = 0;
	}
	virtual ~HashTable() {}
	virtual bool contains(const Object & x) const = 0;
	virtual void makeEmpty() = 0;
	virtual bool insert(const Object & x) = 0;
	virtual bool remove(const Object & x) = 0;
	virtual int size() const = 0;
	virtual bool getEntry(const Object & target, Object & returnedItem) const = 0;
	virtual void displayStatistics() const = 0;
	virtual void traverseTable(void visit(Object &item)) = 0;
};


//*********************************************************************
