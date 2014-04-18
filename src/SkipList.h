#ifndef SKIP_LIST
#define SKIP_LIST
#include "SkipListNode.h"
#include <pthread.h>

class SkipListNode;

class SkipList{

public:
	SkipList();
	~SkipList();
	int depth;
	SkipListNode *head;
	void add(int value); //Will return if skiplist already contains node
	bool remove(int value); //Returns true if node was removed, otherwise false
	bool contains(int value); //Returns true if skip list contains key, otherwise false

private:
	pthread_mutex_t skipListLock;
	bool coinFlip(); //Returns true if rand() gives us a value 0.5 or greater, false otherwise
	void addTopLayer();
};

#endif