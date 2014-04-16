#ifndef SKIP_LIST
#define SKIP_LIST
#include "SkipListNode.h"

class SkipListNode;

class SkipList{

public:
	SkipList();
	int depth;
	SkipListNode *head;
	void add(int value); //Right now can return if skiplist contains node
	bool remove(int value); //Returns true if node was removed, otherwise false
	bool contains(int value); //Returns true if skip list contains key, otherwise false

private:
	bool coinFlip(); //Returns true if rand() gives us a value 0.5 or greater, false otherwise
	void addTopLayer();
};

#endif