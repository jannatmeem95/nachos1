#include "copyright.h"
#include "producer.h"
#include "synch.h"
#include "system.h"
#include <cstdlib>

extern Lock *lock;
extern Condition *produce_L;
extern Condition *consume_L;
extern int count;
extern int maxSize;
extern List<int> *table;

Producer::Producer(char* debugName)
{
	name = debugName;
	printf("*** Producer %s created\n",name);
}

Producer::~Producer()
{

}

void Producer::Produce(void* which)
{
	//printf("*** Producer khet\n");
	while(true){
		lock->Acquire();
		//int random_int = rand();
		//printf("*** Producer khet okk\n");
		int i,j,p;
		for(i=0;i<20000;i++){
			for(j=0;j<20000;j++){
				
			}
		}

		//printf("*** Producer  count %d\n", count);
		if(count==maxSize){
			produce_L->Wait(lock);
		}
		
		printf("*** Producer %s produced item %d\n", (char*)which, count);
		table->Prepend(count);
		count++;
		if(count==1) consume_L->Signal(lock);	

		lock->Release();
		currentThread->Yield();
	}
}
