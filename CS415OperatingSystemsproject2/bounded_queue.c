#include <stdio.h>
#include <stdlib.h>
#include "bounded_queue.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

struct bounded_queue // create a bounded queue of size, null every void* out, initialize values
{
        int size;       // capacity
        void **buffer;  // storage
        long long head; // 
        long long tail; //
};

/*
int RoundIDToBufferIndex(int size, long long id)
{
        long long index = (id % ((long long)size));
        return (int)index;
}*/

int RoundIDToBufferIndex(int size, long long index)
{
        long long value = (index % ((long long)size));
        return (int)value;
}

BoundedQueue *BB_MallocBoundedQueue(long size) //COMPLETE
// This function allocates memory for the bounded queue
{

    // need to malloc one, malloc the size of struct bounded queue
    // after i malloc it, set the size, head to 0, tail to 0
    // before i malloced struct bounded queue, array of void pointers
    // size times the size of a void pointer, then initialize all of those locations to NULL
    // in dequeue im setting it to null also so no way info can leak
        struct bounded_queue *S1 = (struct bounded_queue*)malloc(1 * sizeof(struct bounded_queue));
        S1->size = size;
        S1->head = 0;
        S1->tail = 0; 
        S1->buffer =  (void **)malloc(size * sizeof(void *));
        int i = 0;
        for(; i < size; i++){
            S1->buffer[i] = NULL;
        }
        return S1;
}

long long BB_TryEnqueue(struct bounded_queue *queue, void *item)  //COMPLETE 
// This function tries to enqueue an item into the bounded queue.
// if the queue is not full, it puts the item in the head index
// then returns the head ID, and advances the head ID
{
    //printf("BBTREENEQUEUE CALLED \n");
        long long returnValue = -1;
        int fullValue = BB_IsFull(queue);
        if (fullValue == 0){
            int index = RoundIDToBufferIndex(queue->size, queue->head);
            queue->buffer[index] = item;
            returnValue = queue->head;
            queue->head += 1;  
            printf("enqueue worked\n");  
        }
        return returnValue;
}

int BB_TryDequeue(struct bounded_queue *queue, long long id) // COMPLETE
// This function tries to dequeue an element from the queue
// if the queue is not empty, and if the element is valid,
// and if the id is equal to tail, we null what the tail is looking at,
// the increment the tail to the next id, then we return success.
{
        int returnValue = -1;
        int index = 0;
        if(BB_IsEmpty(queue) != 0){
            printf("Cant Dequeue becasue queue is empty.\n");
        }
        if(BB_IsEmpty(queue) == 0){ 
            //printf("queue isnt empty\n");
           if(BB_IsIdValid(queue,id) == 1 && id == queue->tail){ 
                //printf("bb is valid enabled\n");
                    index = RoundIDToBufferIndex(queue->size, queue->tail);
                    queue->buffer[index] = NULL;
                    queue->tail += 1;
                    returnValue = 1;
           }  
        }
        return returnValue;
}

long long BB_GetFront(struct bounded_queue *queue) // COMPLETE 
// This function gets the front of the bounded queue
// if the queue is not empty, we return the head minus one
// if the queue is empty we return minus one
{
        long long returnValue = 0;
        if(BB_IsEmpty(queue) == 0)
        {
                returnValue = queue->head-1;
        }
        else{
                returnValue = -1;
        }
        return returnValue;
}

long long BB_GetBack(struct bounded_queue *queue)  // COMPLETE 
// This function gets the back of the bounded queue
// if the queue is not empty, then we return the tail
// if the queue is empty, then we return minus one
{       
        long long returnValue = 0;
        if(BB_IsEmpty(queue) == 0){
            returnValue = queue->tail;
        }
        else{
            returnValue = -1; 
        }
        return returnValue;
}

int BB_GetCount(struct bounded_queue *queue)  // COMPLETE  
// This function gets the count of the boundedqueue
// we return the head minus the tail
{
        long long returnValue = 0;
        long long headVal = queue->head;
        long long tailVal = queue->tail;
        returnValue = headVal - tailVal;
        return (int)returnValue;
}

int BB_IsIdValid(struct bounded_queue *queue,long long id)  // COMPLETE 
// This function returns if the bounded queue is valid
// if the tail is less than equal to the id  and id is less than the head
{
        int returnValue = 0;  
        if (queue->tail <= id && id < queue->head){
            returnValue = 1;
        }
        return returnValue;
}

void * BB_GetItem(struct bounded_queue *queue,long long id) // COMPLETE
// This function gets an item from the bounded queue by id
// if valid that that id is in the queue, we convert id to buffer index
// then we return the value queue[index]
{
        void *returnValue = NULL;
        int index = 0;
        if (BB_IsIdValid(queue, id) == 1 ){
           index = RoundIDToBufferIndex(queue->size, id); 
           returnValue = queue->buffer[index]; 
        }
        return returnValue;
}

int BB_IsFull(struct bounded_queue *queue) // COMPLETE 
// This function tells us if the bounded queue is full
// if head-tail == size, the queue is full so return one
// else return 0 because the queue is not full
{
        int headVal = queue->head;
        int tailVal = queue->tail;
        int sizeVal = queue->size;
        int returnValue = 0;
        if (headVal - tailVal == sizeVal){
                returnValue = 1;
        }
        else{
                returnValue = 0;
        }
        return returnValue;
}

int BB_IsEmpty(struct bounded_queue *queue) // COMPLETE 
// this function tells us if the bounded queue is empty
// if head == tail, return 1 because its empty
// else return 0 because the queue is not empty
{
        int headVal = queue->head;
        int tailVal = queue->tail; 
        int returnValue = 0;
        if(headVal == tailVal){
                returnValue = 1; // if empty it returns one
        }     
        else {
                returnValue = 0; // otherwise zero
        }
        return returnValue;
}

void BB_FreeBoundedQueue(struct bounded_queue *queue) // NOT COMPLETE
{
}



// boundedQueue // create a bounded queue of size, null every void* out, initialize values

// bb_tryEnqueue // if not full, put item in head index, return head ID, advance head ID

// BB_getFront // if not empty, head - 1 else -1

// bb_getBack // if not empty tail else -1

// bb_getCount // head - tail

// bb_isValid // tail <= id < head

// bb_ifFull // head - tail == size

// bb_isEmpty // head == tail

// bb_getItem
// // if isValid ()
// //    index = ConvertIDtoIndex()
// //    return Buffer[index]
// // else
// //     null

// // goal is to increment the tail ID
// bb_tryDequeue
// // if not empty
// //   if id is valid
// //     if ID == TAIL
// //        null what the tail is looking at
// //        increment the tail to next ID
// //        return Succes

