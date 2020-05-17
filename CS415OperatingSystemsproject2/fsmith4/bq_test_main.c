#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bounded_queue.h"
#include "utilities.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

int EmptyTest(BoundedQueue *queue,int expected)
{
        int count = BB_GetCount(queue);
        int empty = BB_IsEmpty(queue);
        if((empty==1) && (expected==1))
        {
                fprintf(stdout,"Expected Empty Test PASSED count is: %d \n", count);
        }       
        else if((empty!=1) && (expected==1))
        {
                fprintf(stderr,"Expected Empty Test FAILED count is: %d \n", count);
        }       
        else if((empty==0) && (expected==0))
        {
                fprintf(stdout,"Expected NOT Empty Test PASSED count is: %d \n", count);
        }       
        else if((empty!=0) && (expected==0))
        {
                fprintf(stderr,"Expected NOT Empty Test FAILED count is: %d \n", count);
        }       
        return empty;
}

int FullTest(BoundedQueue *queue,int expected)
{
        int count = BB_GetCount(queue);
        int full = BB_IsFull(queue);
        if((full==1) && (expected==1))
        {
                fprintf(stdout,"Expected Full Test PASSED count is: %d \n", count);
        }       
        else if((full!=1) && (expected==1))
        {
                fprintf(stderr,"Expected Full Test FAILED count is: %d \n", count);
        }       
        else if((full==0) && (expected==0))
        {
                fprintf(stdout,"Expected NOT Full Test PASSED count is: %d \n", count);
        }       
        else if((full!=0) && (expected==0))
        {
                fprintf(stderr,"Expected NOT Full Test FAILED count is: %d \n", count);
        }       
        return full;
}


int ValidIDTest(BoundedQueue *queue,long long id,int expected)
{

        long long front = BB_GetFront(queue);
        long long back = BB_GetBack(queue);
        int valid =BB_IsIdValid(queue,id); 
        if((valid==1)&&(expected==1))
        {
                fprintf(stdout,"Expected ID Valid %lld Test PASSED front/back is: %lld / %lld\n",id,front,back);
        }       
        else if((valid!=1)&&(expected==1))
        {
                fprintf(stderr,"Expected ID Valid %lld Test FAILED front/back is: %lld / %lld\n",id,front,back);
        }       

        else if((valid==0)&&(expected==0))
        {
                fprintf(stdout,"Expected ID NOT Valid %lld Test PASSED front/back is: %lld / %lld\n",id,front,back);
        }       
        else if((valid!=0)&&(expected==0))
        {
                fprintf(stderr,"Expected ID NOT Valid %lld Test FAILED front/back is: %lld / %lld\n",id,front,back);
        }      
        return valid; 
}

void *GetItemTest(BoundedQueue *queue,long long id,int expected)
{

        void *returnValue =  BB_GetItem(queue,id);

        if((returnValue !=NULL)&& (expected==1))
        {
                fprintf(stdout,"Expected GetItem ID %lld Test PASSED %p \n",id,returnValue);
        }       
        else if((returnValue ==NULL)&& (expected==1))
        {
                fprintf(stderr,"Expected GetItem ID %lld Test FAILED %p \n",id,returnValue);
        }       
        else if((returnValue ==NULL)&& (expected==0))
        {
                fprintf(stdout,"Expected NOT GetItem ID %lld Test PASSED %p \n",id,returnValue);
        }       
        else if((returnValue ==NULL)&& (expected==0))
        {
                fprintf(stderr,"Expected NOT GetItem ID %lld Test FAILED %p \n",id,returnValue);
        }    
        return returnValue;      
}

long long EnqueTest(BoundedQueue *queue,void *item,int expected)
{
        long long id = BB_TryEnqueue(queue,item); 
        
        if((id>=0) && (expected ==1))
        {
                        fprintf(stdout,"Expected Enqueue %p Test PASSED ID %lld \n",item,id);
        }
        else if((id<0) && (expected ==1))
        {
                        fprintf(stderr,"Expected NOT Enqueue %p Test FAILED ID %lld \n",item,id);
        }
        else if ((id<0) && (expected ==0))
        {
                        fprintf(stdout,"Expected NOT Enqueue %p Test PASSED ID %lld \n",item,id);
        }
        else if((id>=0) && (expected ==0))
        {
                        fprintf(stderr,"Expected NOT Enqueue %p Test FAILED ID %lld \n",item,id);
        }    
        return id;    
}

int DequeueTest(BoundedQueue *queue,long long id,int expected)
{

        int deq = BB_TryDequeue(queue,id);
        
        if((deq==1) && (expected ==1))
        {
                        fprintf(stdout,"Expected Dequeue ID %lld Test PASSED\n",id);
        }
        else if((deq!=1) && (expected ==1))
        {
                        fprintf(stderr,"Expected Dequeue ID %lld Test FAILED\n",id);
         }
        else if ((deq!=1) && (expected ==0))
        {
                        fprintf(stdout,"Expected NOT Dequeue ID %lld Test PASSED\n",id);
        }
        else if((deq==1) && (expected ==0))
        {
                        fprintf(stderr,"Expected NOT Dequeue ID %lld Test FAILED\n",id);
        }        
        return 0;
}


int CountEqualTest(BoundedQueue *queue,int test_count,int expected)
{
        int queue_count = BB_GetCount(queue);

        if((queue_count==test_count) && (expected ==1))
        {
                fprintf(stdout,"Expected Count Equal %d Test PASSED %d\n",test_count,queue_count);
        }
        else if((queue_count!=test_count) && (expected ==1))
        {
                fprintf(stdout,"Expected Count Equal %d Test FAILED %d\n",test_count,queue_count);
        }
        else if ((queue_count!=test_count) && (expected ==0))
        {
                fprintf(stdout,"Expected NOT Count Equal %d Test PASSED %d\n",test_count,queue_count);
        }
        else if((queue_count==test_count) && (expected ==0))
        {
                fprintf(stdout,"Expected NOT Count Equal %d Test FAILED %d\n",test_count,queue_count);
        }        
        return queue_count;
}

/*

EmptyTest(queue,1);

FullTest(queue,1);

ValidIDTest(queue,id,1);

GetItemTest(queue,id,1);

EnqueTest(queue,item,1);

DequeueTest(queue,id,1);

CountEqualTest(queue,test_count,1);
*/

void SimpleOrderTest(struct FileLines* Lines)
{
        //long long id =-1;
        void *item=NULL;
        BoundedQueue * queue = NULL;
        struct FileLines *Destination = MakeEmptyLines(Lines->FileName,Lines->LineCount);
        long long *ids = malloc(sizeof(long long) * Lines->LineCount);
        
        int mid_point = Lines->LineCount/2;
        queue = BB_MallocBoundedQueue(mid_point);

        int index = 0;        
        EmptyTest(queue,1);
        item = GetItemTest(queue,-1,0);
        item = GetItemTest(queue,0,0);
        item = GetItemTest(queue,1,0);
        ValidIDTest(queue,-1,0);
        ValidIDTest(queue,0,0);
        ValidIDTest(queue,1,0);
        
        item = strdup(Lines->Lines[index++]);
        ids[index-1] = EnqueTest(queue,item,1);
        
        EmptyTest(queue,0);
        item = GetItemTest(queue,-1,0);
        item = GetItemTest(queue,0,1);
        item = GetItemTest(queue,1,0);
        ValidIDTest(queue,-1,0);
        ValidIDTest(queue,0,1);
        ValidIDTest(queue,1,0);
        
        item = strdup(Lines->Lines[index++]);
        ids[index-1] = EnqueTest(queue,item,1);

        EmptyTest(queue,0);
        item = GetItemTest(queue,-1,0);
        item = GetItemTest(queue,0,1);
        item = GetItemTest(queue,1,1);
        item = GetItemTest(queue,2,0);
        ValidIDTest(queue,-1,0);
        ValidIDTest(queue,0,1);
        ValidIDTest(queue,1,1);
        ValidIDTest(queue,2,0);
        
        int enqueue_count = CountEqualTest(queue,index,1);
        int remove_index =0;
        
        while(index < Lines->LineCount)
        {
                
                while(enqueue_count +1 < mid_point && index < Lines->LineCount)
                {
                        item = strdup(Lines->Lines[index++]);
                        ids[index-1] = EnqueTest(queue,item,1);
                        enqueue_count = CountEqualTest(queue,enqueue_count+1,1);
                }
                if(enqueue_count == mid_point)//if(enqueue_count +1 == mid_point)
                {
                        FullTest(queue,1);
                }
                else
                {
                        FullTest(queue,0);
                }
                
                while(remove_index < index)
                {
                        item = GetItemTest(queue, ids[remove_index],1);
                        Destination->Lines[remove_index] = item;
                        DequeueTest(queue,ids[remove_index],1);
                        enqueue_count = CountEqualTest(queue,enqueue_count-1,1);
                        remove_index++;
                }
                EmptyTest(queue,1);
        }        
        
        if(CompareFileLines(Lines,Destination)==0)
        {
                fprintf(stdout,"SIMPLE ORDER TEST PASSES!\n");
        }
        else
        {
                fprintf(stderr,"SIMPLE ORDER TEST FAILS!\n");
        }
        FreeFile(Destination);
        
        free(ids);
        BB_FreeBoundedQueue(queue);
}





int main(int argc, char *argv[])
{
        for(int i=0; i< argc; i++)
        {
                fprintf(stdout,"Argument %d:%s\n",i,argv[i]);
        }
        
        if(argc !=2 )
        {
                fprintf(stderr,"ERROR: invalid arguments. Usage: ./<prgm> <testfilename>\n");
                return -1;
        }
        
        struct FileLines* Lines = NULL;
        
        Lines = LoadAFile(argv[1]);
        
        BoundedQueue *queue = NULL;
        
        queue = BB_MallocBoundedQueue(Lines->LineCount);
        
        SimpleOrderTest(Lines);
        
        BB_FreeBoundedQueue(queue);

        FreeFile(Lines);
        return 0;
}

/*
int main2(int argc, char *argv[]) {
    char buf[1024];
    char *p, *q;
    BQueue *bq;
    long i, n;
    FILE *fd;
    char **array;
    Iterator *it;

    if (argc != 2) {
        fprintf(stderr, "usage: ./bqtest file\n");
        return -1;
    }
        //test of queue exhaustion
    printf("===== test of exhaustion of small queue\n");
    if ((bq = bq_create(10L)) == NULL) {
        fprintf(stderr, "Error creating bounded queue, size 10, of strings\n");
        return -1;
    }
    for (i = 0; i < 100; i++) {
        sprintf(buf, "Line %ld\n", i);
        if ((p = strdup(buf)) == NULL) {
            fprintf(stderr, "Unable to duplicate string on heap\n");
            return -1;
        }
        if (! bq_add(bq, p)) {
            free(p);
            break;
        }
    }
    printf("bounded queue filled after %ld additions\n", i);
    while (! bq_isEmpty(bq)) {
        (void)bq_remove(bq, (void **)&p);
        printf("%s", p);
        free(p);
    }
//test of bq_destroy(bq, NULL);
    printf("===== test of destroy(NULL)\n");
    bq_destroy(bq, NULL);
    if ((fd = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s to read\n", argv[1]);
        return -1;
    }
    if ((bq = bq_create(10000L)) == NULL) {
        fprintf(stderr, "Error creating bounded queue, size 10000, of strings\n");
        return -1;
    }
 
//test of add()
    printf("===== test of add\n");
    while (fgets(buf, 1024, fd) != NULL) {
        if ((p = strdup(buf)) == NULL) {
            fprintf(stderr, "Error duplicating string\n");
            return -1;
        }
        if (!bq_add(bq, p)) {
            fprintf(stderr, "Error adding string to bounded queue\n");
            return -1;
        }
    }
    fclose(fd);
    n = bq_size(bq);
    //test of remove()
    printf("===== test of peek and remove\n");
    for (i = 0; i < n; i++) {
        if (!bq_peek(bq, (void **)&p)) {
            fprintf(stderr, "Error retrieving %ld'th element\n", i);
            return -1;
        }
        if (!bq_remove(bq, (void **)&q)) {
            fprintf(stderr, "Error retrieving %ld'th element\n", i);
            return -1;
        }
        if (strcmp(p, q) != 0) {
            fprintf(stderr, "Returns from peek and remove are not the same\n");
            return -1;
        }
        printf("%s", p);
    }
    //test of destroy with free userFunction
    printf("===== test of destroy(free)\n");
    bq_destroy(bq, free);
    if ((bq = bq_create(10000L)) == NULL) {
        fprintf(stderr, "Error creating bounded queue of strings\n");
        return -1;
    }
    fd = fopen(argv[1], "r");		
    while (fgets(buf, 1024, fd) != NULL) {
        if ((p = strdup(buf)) == NULL) {
            fprintf(stderr, "Error duplicating string\n");
            return -1;
        }
        if (!bq_add(bq, p)) {
            fprintf(stderr, "Error adding string to bounded queue\n");
            return -1;
        }
    }
    fclose(fd);
    //test of toArray
    printf("===== test of toArray\n");
    if ((array = (char **)bq_toArray(bq, &n)) == NULL) {
        fprintf(stderr, "Error in invoking bq_toArray()\n");
        return -1;
    }
    for (i = 0; i < n; i++) {
        printf("%s", array[i]);
    }
    free(array);
    //test of iterator
    printf("===== test of iterator\n");
    if ((it = bq_it_create(bq)) == NULL) {
        fprintf(stderr, "Error in creating iterator\n");
        return -1;
    }
    while (it_hasNext(it)) {
        char *p;
        (void) it_next(it, (void **)&p);
        printf("%s", p);
    }
    it_destroy(it);
    bq_destroy(bq, free);

    return 0;
}

*/
