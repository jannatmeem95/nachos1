#ifndef PRODUCER_H
#define PRODUCER_H

#include "copyright.h"
#include "thread.h"
#include "synch.h"
#include "list.h"

extern Lock *lock;
extern Condition *produce_L;
extern Condition *consume_L;
extern int count;
extern int maxSize;
extern List<int> *table;


class Producer{
	public:
		Producer(char* debugName);		
		~Producer();			
		char* getName() 
		{
			//printf("*** producer getname %s \n",name);
			return (name); 
		}
		
		static void Produce(void* which); 

  private:
    char* name;

};



#endif
