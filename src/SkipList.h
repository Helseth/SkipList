#ifndef SKIP_LIST
#define SKIP_LIST
#include "SkipListNode.h"

class SkipListNode;

class SkipList{

public:
	SkipList();
	SkipListNode *head;
	void add(int value);
	bool remove(int value);
	bool contains(int value);

private:
	SkipListNode getLeftNode(SkipListNode *left);
	SkipListNode findValue(int value);
};

#endif