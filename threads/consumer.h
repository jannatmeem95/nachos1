#ifndef CONSUMER_H
#define CONSUMER_H

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


class Consumer{
	public:
		Consumer(char* debugName);		
		~Consumer();			
		char* getName() 
		{ 	
			//printf("*** consumer getname %s \n",name);
			return (name); 
		}
		
		static void Consume(void* which); 

  private:
    char* name;

};



#endif
