#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
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

create subscriber and publisher thread, plus a clean-up thread. 

        (1) Create every thread and pass is a unique string argument 

        (1) Have each thread wait for a flag from Main. 

        (2) All threads go, printing their thread_id, and string 

        (3) Threads exit. 

//pthread join on a  thread, tells the paretn process to le thtem finsih executing the sub or pub functions,
// wait untill all of those are done

        pthread_t cThread; 
if(pthread_create(&cThread, NULL, work, param)){ // work is a fucntion, param is our structuture
    perror("ERROR creating thread.");
}


*/
int start = 0;
int exitFlag = 0;

struct pubstruct {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int       thread_num;       /* Application-defined thread # */
    char     *argv_string;      /* From command-line argument */
};

struct substruct {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int       thread_num;       /* Application-defined thread # */
    char     *argv_string;      /* From command-line argument */
};

struct cleanstruct {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int       thread_num;       /* Application-defined thread # */
    char     *argv_string;      /* From command-line argument */
};



void *publisher(void *param){
        while(start == 0){

        }
        struct pubstruct *input = param;
        //printing their thread_id, and string
        printf("%d\n", input->thread_num);
        printf("%s\n", input->argv_string);
        //printf("Publisher function called! \n");
        return NULL;

}

void *subscriber(void *param){
        while(start == 0){

        }
        struct substruct *input = param;
        printf("%d\n", input->thread_num);
        printf("%s\n", input->argv_string);
        //printing their thread_id, and string
        //printf("Subscriber function called! \n");
        return NULL;


}

void *cleanup(void *param){
        while(exitFlag == 0){

        }
        //printf("Cleanup function called! \n");
        return NULL;

}

//int pthread_join(pthread_t thread, void **value_ptr); 


int main(int argc, char* argv[]){
        //start = 0;
        //exit = 0;
        //int max_pub = 2;
        //int max_sub = 2;
        //int i = 0;
        //pub_structs = {};
        //sub_structs = {};
        //for(; i < max_pub; i++){
        //       pubstruct[i] =
                
        //}
        //struct pubstruct p[max_pub];
        //struct substruct s[max_sub];

        struct pubstruct p;
        p.thread_num = 1;
        p.argv_string = "pubslisher unique string arg";
        // give it a value
        pthread_t publisherThread; 
        if(pthread_create(&publisherThread, NULL, &publisher, &p)){ // work is a fucntion, param is our structuture , 
            perror("ERROR creating publibsher thread.");
        }
        struct substruct s;
        s.thread_num = 2;
        s.argv_string = "subscriber unique string arg";
        pthread_t subscriberThread; 
        if(pthread_create(&subscriberThread, NULL, &subscriber, &s)){ // work is a fucntion, param is our structuture , sub id, sub file, array of long longs
            perror("ERROR creating subscriber thread.");
        }
        struct cleanstruct c;
        pthread_t cleanupThread; 
        if(pthread_create(&cleanupThread, NULL, &cleanup, &c)){ // work is a fucntion, param is our structuture , sub id, sub file, array of long longs
            perror("ERROR creating subscriber thread.");
        }
        start = 1;
        pthread_join(publisherThread, NULL);
        pthread_join(subscriberThread, NULL);
        exitFlag = 1;
        pthread_join(cleanupThread, NULL);
        //printf("main executed\n");
	return 0;
}

