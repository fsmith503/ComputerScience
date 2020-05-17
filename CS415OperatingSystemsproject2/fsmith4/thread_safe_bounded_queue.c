#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "bounded_queue.h"
#include "thread_safe_bounded_queue.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

struct thread_safe_bounded_queue
{
        BoundedQueue *queue;
        pthread_mutex_t lock; 
};


TSBoundedQueue *TS_BB_MallocBoundedQueue(long size)
{
        struct thread_safe_bounded_queue *returnValue = NULL;
        returnValue = (struct thread_safe_bounded_queue*)malloc(sizeof(struct thread_safe_bounded_queue));
        pthread_mutex_init(&(returnValue->lock), NULL);
        returnValue->queue = BB_MallocBoundedQueue(size);
        return (TSBoundedQueue *)returnValue; 
}

long long TS_BB_TryEnqueue(struct thread_safe_bounded_queue *queue,void *item)
{       
        //printf("TS_BB_TryEnqueue called\n");
        long long returnValue = -1;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_TryEnqueue(queue->queue,item);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

int TS_BB_TryDequeue(struct thread_safe_bounded_queue *queue,long long id)
{
        int  returnValue = 0;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_TryDequeue(queue->queue,id);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

long long TS_BB_GetFront(struct thread_safe_bounded_queue *queue)
{
        long long returnValue = -1;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_GetFront(queue->queue);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

long long TS_BB_GetBack(struct thread_safe_bounded_queue *queue)
{
        long long returnValue = -1;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_GetBack(queue->queue);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

int TS_BB_GetCount(struct thread_safe_bounded_queue *queue)
{
        long long returnValue = 0;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_GetCount(queue->queue);
        pthread_mutex_unlock(&(queue->lock)); 
        return (int)returnValue;
}

int TS_BB_IsIdValid(struct thread_safe_bounded_queue *queue,long long id)
{
        int returnValue = 0;  
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_IsIdValid(queue->queue,id);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

void *TS_BB_GetItem(struct thread_safe_bounded_queue *queue,long long id)
{
        void *returnValue = NULL;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_GetItem(queue->queue,id);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

int TS_BB_IsFull(struct thread_safe_bounded_queue *queue)
{
        int returnValue = 0;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_IsFull(queue->queue);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

int TS_BB_IsEmpty(struct thread_safe_bounded_queue *queue)
{
        int returnValue = 0;
        pthread_mutex_lock(&(queue->lock)); 
        returnValue = BB_IsEmpty(queue->queue);
        pthread_mutex_unlock(&(queue->lock)); 
        return returnValue;
}

void TS_BB_FreeBoundedQueue(struct thread_safe_bounded_queue *queue)
{
        BB_FreeBoundedQueue(queue->queue);
        queue->queue = NULL;
        pthread_mutex_destroy(&(queue->lock));
        free(queue);
}

