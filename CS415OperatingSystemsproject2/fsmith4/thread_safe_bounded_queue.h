#ifndef THREAD_SAFE_BOUNDED_QUEUE_H
#define THREAD_SAFE_BOUNDED_QUEUE_H
/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/



typedef struct thread_safe_bounded_queue TSBoundedQueue;

TSBoundedQueue *TS_BB_MallocBoundedQueue(long size);

long long TS_BB_TryEnqueue(TSBoundedQueue *queue,void *item); 

int TS_BB_TryDequeue(TSBoundedQueue *queue,long long id);

long long TS_BB_GetFront(TSBoundedQueue *queue);

long long TS_BB_GetBack(TSBoundedQueue *queue);

int TS_BB_GetCount(TSBoundedQueue *queue);

int TS_BB_IsIdValid(TSBoundedQueue *queue,long long id);

void *TS_BB_GetItem(TSBoundedQueue *queue,long long id);

int TS_BB_IsFull(TSBoundedQueue *queue);

int TS_BB_IsEmpty(TSBoundedQueue *queue);

void TS_BB_FreeBoundedQueue(TSBoundedQueue *queue);




#endif
