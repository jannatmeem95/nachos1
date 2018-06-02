// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "synch.h"
#include "list.h"
#include "producer.h"
#include "consumer.h"


//----------------------------------------------------------------------
//global variables
//----------------------------------------------------------------------

Lock *lock;
Condition *produce_L;
Condition *consume_L;
int count;
int maxSize;
List<int> *table;


//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(void* which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", *((int*)which), num);
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");
	Producer* P=new Producer("A");
	Producer* Q=new Producer("B");
	Producer* R=new Producer("C");
	Consumer* C=new Consumer("X");
	Consumer* D=new Consumer("Y");
	Consumer* E=new Consumer("Z");

	lock= new Lock("Lock");
	produce_L=new Condition("Producer_condition");
	consume_L=new Condition("Consumer_condition");

	count=0;
	maxSize=5;

	table=new List<int>;

    Thread *t = new Thread("forked thread");
    t->Fork(P->Produce, P->getName());

	Thread *r = new Thread("forked thread");
    r->Fork(Q->Produce, Q->getName());

	Thread *s = new Thread("forked thread");
    s->Fork(R->Produce, R->getName());

	Thread *y = new Thread("forked thread");
    y->Fork(C->Consume, C->getName());
	
	Thread *z = new Thread("forked thread1");
    z->Fork(D->Consume, D->getName());
 
	Thread *x = new Thread("forked thread");
    x->Fork(E->Consume, E->getName());
}

