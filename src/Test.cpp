#include "SkipList.h"
#include "SkipListNode.h"
#include <iostream>
#include <pthread.h>

using namespace std;

#define TEST_AMOUNT 5
#define NUM_THREADS 2

void* add(void*);

SkipList *mySL;

int main(){

	mySL = new SkipList();
	SkipListNode *head = mySL->head;

	pthread_t threads[NUM_THREADS];

	for(int i = 0; i < TEST_AMOUNT; i++){
		cout << "Adding " << i << "\n";
		mySL->add(i);
	}

	for(int i = 0; i < TEST_AMOUNT * 2; i++){
		bool contains;
		contains = mySL->contains(i);
		if(contains)
			cout << "The skip list contains " << i << "\n";
		else
			cout << "The skip list doesn't contain " << i << "\n";
	}

	for(int i = 0; i < TEST_AMOUNT * 2; i++){
		bool deleted;
		cout << "Deleting " << i << "\n";
		deleted = mySL->remove(i);
		if(deleted)
			cout << i << " was deleted... Hopefully\n";
		else
			cout << i << " was not deleted.\n";
	}

	cout << "Deleting skip list\n";
	delete mySL;
	cout << "Finished deleting skip list\n";
	//system("pause"); //Uncomment this for Visual Studio only
	return 0;
}

