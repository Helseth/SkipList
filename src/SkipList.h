#ifndef SKIP_LIST
#define SKIP_LIST

template <class T>
class SkipList{
public:
	SkipList(); //Constructor
	void add(T);
	bool remove(T);
	bool contains(T);

private:
	SkipListNode getLeftNode(SkipListNode);
	SkipListNode findValue(T);

};

#endif