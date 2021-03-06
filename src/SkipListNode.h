#ifndef SKIP_LIST_NODE
#define SKIP_LIST_NODE

#ifndef NULL
#define NULL 0
#endif

class SkipListNode{

public:

	SkipListNode(int value);

	SkipListNode* getUp();
	SkipListNode* getDown();
	SkipListNode* getLeft();
	SkipListNode* getRight();
	void setUp(SkipListNode *up);
	void setDown(SkipListNode *down);
	void setLeft(SkipListNode *left);
	void setRight(SkipListNode *right);
	int getValue();
	void setValue(int value);

private:

	SkipListNode *up;
	SkipListNode *down;
	SkipListNode *left;
	SkipListNode *right;
	int value;
};

#endif