#include "copyright.h"
#include "consumer.h"
#include "system.h"
#include "synch.h"

extern Lock *lock;
extern Condition *produce_L;
extern Condition *consume_L;
extern int count;
extern int maxSize;
extern List<int> *table;

Consumer::Consumer(char* debugName)
{
	name = debugName;
	printf("*** Consumer %s created\n",name);
}

Consumer::~Consumer()
{

}

void Consumer::Consume(void* which)
{
	while(true){
		lock->Acquire();
		//int random_int = rand();
		int i,j;
		for(i=0;i<30000;i++){
			for(j=0;j<30000;j++){
			
			}
		}
		//printf("*** Consumer random_int %d , count %d\n", random_int, count);
		
		if(count==0){
			consume_L->Wait(lock);
		}
		
		int taken=table->Remove();
		
		printf("*** Consumer %s consumed item %d\n", (char*)which, taken);
		
		count--;
		if(count==maxSize-1) produce_L->Signal(lock);	

		lock->Release();
		currentThread->Yield();
	}
}
