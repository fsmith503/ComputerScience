#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "bounded_queue.h"
#include "thread_safe_bounded_queue.h"
#include "topicQueue.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/
/*
copy boundedqueue.c boundedqueue.h
and make the topic queue, which is really a bounded queue, 
topic queue takes topic entries
*/

//get entry dont return one return the id


//long long enqueue(struct topicqueue* inputStruct, void *item){
long long enqueue(TOPICQUEUE* inputStruct, void *item){
        //printf("topic queue enqueue called\n");
        long long returnValue = -1;
        pthread_mutex_lock(&(inputStruct->lock));
        //returnValue = BB_TryEnqueue(inputStruct->tsbq,item);
        returnValue = TS_BB_TryEnqueue(inputStruct->TSBQ, item); //removed &
         pthread_mutex_unlock(&(inputStruct->lock)); 
         if(returnValue < 0){
            printf("Cant enqueue because queue is full.\n");
         }
        return returnValue;
}

long long getEntry(TOPICQUEUE* tqpointer, long long id, struct topicentry* TEpointer){
        //int theInteger
        // the interger = gtEntry(qUEUE, ID, *ptr)
                // if id is valid
        // *ptr = *(topicentry*)getitem(id) 
        //if(BB_IsIdValid(struct bounded_queue *queue,long long id)) // for the is valid are we using the function from getEntry

        //Case 1: topic queue is empty –getentry()will return 0. 
        //my_long_long = (long long) my_int 
        long long returnValue = (long long) TS_BB_IsEmpty(tqpointer->TSBQ);  //removed &
        if (returnValue == 1){
                printf("queue is empty");
                return returnValue;
        }     
        // Case 2:lastentry+1entry is in the queue –getentry()
        // getentry()will scan the queue entries
        //,starting with the oldest entry in the queue,
        // until it finds thelastentry+1entry, then it copiesthe entry into the
        // topicentrystructure pointed to by thestruct topicentry *t argumentand return 1.

        // if id less than tail then return tail
        // if  tail <= id <= head, return id
        // if id > head, return 0
        long long tailID = TS_BB_GetBack(tqpointer->TSBQ); //removed &
        long long headID = TS_BB_GetFront(tqpointer->TSBQ); //removed &
        if(id < tailID){
           return tailID;
        }
        if (tailID <= id && id < headID){
           TEpointer = (struct topicentry*) TS_BB_GetItem(tqpointer->TSBQ, id); //removed &
           return id;
        }
        if (id >= headID){
           //return -1;
            return headID;
        }
        return returnValue;

        // Case 3: topic queue is not empty andlastentry+1entry is not the queue 

}

int dequeue(TOPICQUEUE* inputStruct, long long id){
        int returnValue = 0;
        pthread_mutex_lock(&(inputStruct->lock)); 
        returnValue = TS_BB_TryDequeue(inputStruct->TSBQ, id); //removed &
        pthread_mutex_unlock(&(inputStruct->lock));
        if(returnValue < 0){
            //printf("tried to dequeue item that wasnt there\n");
        } 
        return returnValue;

}

struct topicentry *mallocTopicEntry(){
    struct topicentry *S1 = (struct topicentry*)malloc(1 * sizeof(struct topicentry)); 
    //struct cmd_struct *S1 = (struct cmd_struct*)malloc(Commands * sizeof(struct cmd_struct)); 
    //S1->pid = -1;
    return S1;
}



TOPICQUEUE *mallocTopicQueue(int size)
{
        //inside this, gonna malloc a struct topic queueue, fill out all fields with what i need,
        // last line on return, cast to a toipicqueue pointer

        struct topicqueue *returnValue = NULL;
        returnValue = (struct topicqueue*)malloc(sizeof(struct topicqueue));
        pthread_mutex_init(&(returnValue->lock), NULL); // MATT TOLD ME TO INIT MY PTHREAD LOCKS
        returnValue->TSBQ = TS_BB_MallocBoundedQueue(size);
        return returnValue;//(TOPICQUEUE *)returnValue; 
}

/*
TSBoundedQueue *TS_BB_MallocBoundedQueue(long size)
{
        struct thread_safe_bounded_queue *returnValue = NULL;
        returnValue = (struct thread_safe_bounded_queue*)malloc(sizeof(struct thread_safe_bounded_queue));
        pthread_mutex_init(&(returnValue->lock), NULL);
        returnValue->queue = BB_MallocBoundedQueue(size);
        return (TSBoundedQueue *)returnValue; 
}
*/

void freeTopicQueue(TOPICQUEUE* inputStruct){
        TS_BB_FreeBoundedQueue(inputStruct->TSBQ); // removed &
        //inputStruct->TSBQ = NULL;
        pthread_mutex_destroy(&(inputStruct->lock));
        free(inputStruct);
}

/*
void TS_BB_FreeBoundedQueue(struct thread_safe_bounded_queue *queue)
{
        BB_FreeBoundedQueue(queue->queue);
        queue->queue = NULL;
        pthread_mutex_destroy(&(queue->lock));
        free(queue);
}
*/




