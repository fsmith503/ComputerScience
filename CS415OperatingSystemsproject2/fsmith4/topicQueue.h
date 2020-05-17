#ifndef TOPIC_QUEUE_H
#define TOPIC_QUEUE_H
#define SIZE 4
#define QUACKSIZE 8
#define CAPTIONSIZE 8
#define MAXENTRIES 8
#include "thread_safe_bounded_queue.h"
/*
copy boundedqueue.c boundedqueue.h
and make the topic queue, which is really a bounded queue, 
topic queue takes topic entries
*/

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

 // lower case name, does have struct in front of it
// camelcase name, doesnt have struct in front of it




struct topicentry {
        int entrynum;
        //struct timeval timestamp;
        int pubID;
        char photoUrl[QUACKSIZE];        /* URL to photo  */
        char photoCaption[CAPTIONSIZE];  /* photo caption */
}; 

//typedef struct thread_safe_bounded_queue TSBoundedQueue; //method that defines opaqueness , how you make everything private, knows whats inside the c file, on outside, only have name

// make new struct, topic queue, name it opaque name, get rid of the old one topic queue lower case and upper case, lower case goes inside topic queueue.c, 
//outside of it ill have a topic queue pointer.

//typedef struct topicqueue TOPICQUEUE;

typedef struct topicqueue {
	//holds array of topic entries

	//talk to matt about whats going on here
	//BoundedQueue *queue;
	TSBoundedQueue* TSBQ; //so i was actually using this
	//BoundedQueue TSBQ;
	//struct thread_safe_bounded_queue TSBQ;
	pthread_mutex_t lock;
}TOPICQUEUE;

TOPICQUEUE *mallocTopicQueue(int Size);
//inside this, gonna malloc a struct topic queueue, fill out all fields with what i need,
// last line on return, cast to a toipicqueue pointer


struct topicentry *mallocTopicEntry();

//malloc topic struct
//Based on your implementation, yes. And you'll need to free it when you dequeue too.

void freeTopicQueue(TOPICQUEUE *topicqueue); // is this void or does it return the pointer, its probably void....

long long enqueue(TOPICQUEUE* tqpointer, void *item);

long long getEntry(TOPICQUEUE* tqpointer, long long id, struct topicentry* TEpointer); // returns two things
// the interger = gtEntry(qUEUE, ID, *ptr)
// if id is valid
	// *ptr = *(topicentry*)getitem(id) 
int dequeue(TOPICQUEUE* tqpointer, long long id);


// in malloc do need to return TSBoundedqueue pointer, one place i have to acast inside of actual function
// need to cast a struct topicqueue * to a 


#endif
