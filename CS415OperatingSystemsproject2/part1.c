#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
//#include "headerProject1.h"
#include <sys/time.h>
#include <sys/wait.h>
//#include "bounded_queue.c"
#include "bounded_queue.h"
//#include "topicQueue.c"
#include "thread_safe_bounded_queue.h"
#include "topicQueue.h"
#include "utilities.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

/*
Implement tests of your Topic Queue. Show that you can

Fill the Queue.

Read all the entries, and always keeping track of the last entry you read.

Be stopped if you try to add more items then can fit.

Empty the queue.

Fill it again

Delete some things  2/4

Read the "next entry" (continuing to read from where you left off on step 2;
 note that the entry that you want to read at this point is gone. 
 You should read the tail entry in this case, and return its ID unless the queue is empty, 
 OR you have already read everything up to the head.)

Read the "next entry" again. This time you should be accessing a valid entry.

Be alerted when you try to read an entry that you haven't posted yet.
*/


int main(int argc, char* argv[]){
        //struct fileLines* input1 = NULL;
        //struct fileLines* input2 = NULL;

        //int topic_num = 1;
        //int sleep_num = 1;
        //char p1url[128] = "https://i.imgur.com/izzpeRbb.jpg";
        //char p1caption[128] = "Patrick Starmie";
        //input2 = LoadAFile(file2);
        printf("\n");
        printf("We are starting the program in main.\n");
        printf("\n");
        printf("Initialzing topic queue, the size of the topic queue is %d.\n", SIZE);
        struct topicqueue *mainTQ = mallocTopicQueue(SIZE);
        struct topicentry *FirstEntry = mallocTopicEntry();
        //FirstEntry->pubID = 1;
        struct topicentry *SecondEntry = mallocTopicEntry();
        //SecondEntry->pubID = 2;
        struct topicentry *ThirdEntry = mallocTopicEntry();
        //ThirdEntry->pubID = 3;
        struct topicentry *FourthEntry = mallocTopicEntry();
        //FourthEntry->pubID = 4;
        printf("\n");
        printf("We are going to attempt to enqueue 4 items in to the queue.\n");
        printf("\n");
        
        long long firstid = enqueue(mainTQ, FirstEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued first item. \n");
        long long secondid = enqueue(mainTQ, SecondEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued second item. \n");
        long long thirdid = enqueue(mainTQ, ThirdEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued third item. \n");
        long long fourthid = enqueue(mainTQ, FourthEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued fourth item. \n");

        //enqueue a 5th to make sure

        printf("\n");
        printf("Now we are going to read all of the entries.\n");
        printf("\n");
        long long entry1 = getEntry(mainTQ, firstid, FirstEntry);
        long long entry2 = getEntry(mainTQ, secondid, SecondEntry);
        long long entry3 = getEntry(mainTQ, thirdid, ThirdEntry);
        long long entry4 = getEntry(mainTQ, fourthid, FourthEntry);


        printf("The id of the first item is: %lld\n", entry1);
        printf("The id of the second item is: %lld\n", entry2);
        printf("The id of the third item is: %lld\n", entry3);
        printf("The id of the fourth item is: %lld\n", entry4);
        printf("\n");

        printf("Attempting to enqueue another item into the queue. \n");
        //long long fifthid = enqueue(mainTQ, FourthEntry);
        printf("\n");
        printf("Now we are going to empty the queue.\n");
        printf("\n");

        dequeue(mainTQ, firstid);
        printf("Successfully dequeued first item. \n");
        dequeue(mainTQ, secondid);
        printf("Successfully dequeued second item. \n");
        dequeue(mainTQ, thirdid);
        printf("Successfully dequeued third item. \n");
        dequeue(mainTQ, fourthid);
        printf("Successfully dequeued fourth item. \n");

        printf("\n");
        printf("We are now going to fill the queue.\n");
        printf("\n");

        firstid = enqueue(mainTQ, FirstEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued first item. \n");
        secondid = enqueue(mainTQ, SecondEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued second item. \n");
        thirdid = enqueue(mainTQ, ThirdEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued thrid item. \n");
        fourthid = enqueue(mainTQ, FourthEntry);  //im getting a segfault in my enqueue
        printf("Successfully enqueued fourth item. \n");

        printf("\n");
        printf("Now we are going to dequeue 2/4 items from the queue.\n");
        printf("\n");

        dequeue(mainTQ, firstid);
        printf("Successfully dequeued first item. \n");
        dequeue(mainTQ, secondid);
        printf("Successfully dequeued second item. \n");
        printf("\n");

        long long attemptedentry4 = getEntry(mainTQ, firstid, FirstEntry);
        long long attemptedentry5 = getEntry(mainTQ, attemptedentry4+1, FirstEntry);
        //long long attemptedentry6 = getEntry(mainTQ, attemptedentry5+1, FirstEntry);

        printf("Reading the next entry\n");
        //Read the "next entry" 

        printf("first entry id is %lld\n", attemptedentry4);
        //Read the "next entry" again.
        printf("Reading the 'next entry' again.\n");

        printf("second entry id is %lld\n", attemptedentry5);
        //printf("attepmpted 6 entry id is %lld\n", attemptedentry6);

        //printf("main executed\n");
	return 0;
}












