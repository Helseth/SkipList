#ifndef SKIP_LIST
#define SKIP_LIST
#include "SkipListNode.h"

class SkipListNode;

class SkipList{

public:
	SkipList();
	int depth;
	SkipListNode *head;
	void add(int value);
	bool remove(int value);
	bool contains(int value);

private:
	bool coinFlip();
	void addTopLayer();
	SkipListNode findValue(int value);
};

#endif