#ifndef BOUNDED_QUEUE_H
#define BOUNDED_QUEUE_H

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

typedef struct bounded_queue BoundedQueue;

BoundedQueue *BB_MallocBoundedQueue(long size);

long long BB_TryEnqueue(BoundedQueue *queue,void *item); 

int BB_TryDequeue(BoundedQueue *queue,long long id);

long long BB_GetFront(BoundedQueue *queue);

long long BB_GetBack(BoundedQueue *queue);

int BB_GetCount(BoundedQueue *queue);

int BB_IsIdValid(BoundedQueue *queue,long long id);

void *BB_GetItem(BoundedQueue *queue,long long id);

int BB_IsFull(BoundedQueue *queue);

int BB_IsEmpty(BoundedQueue *queue);

void BB_FreeBoundedQueue(BoundedQueue *queue);

#endif
