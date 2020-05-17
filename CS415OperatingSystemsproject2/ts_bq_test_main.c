#include "thread_safe_bounded_queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

int main(int argc, char *argv[])
{
        int i = 0;
        for(i=0; i< argc; i++)
        {
                fprintf(stdout,"Argument %d:%s\n",i,argv[i]);
        }
        

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
