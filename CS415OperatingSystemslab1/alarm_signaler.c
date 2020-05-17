#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
/* Additional types needed.*/
#include  <signal.h>
#include <unistd.h>
/* Process identifier page(s):		http://man7.org/linux/man-pages/man2/getpid.2.html*/
#include <sys/wait.h>
/* Signal informational Page(s): 	http://www.csl.mtu.edu/cs4411.ck/www/NOTES/signal/kill.html*/

volatile int run = 1;
volatile int alarm_count = 10;
volatile int interval = 1;

void alarm_handler(int sig)
{
	printf("Inside alarm signal handler. \r\n");

	printf("Starting alarm with interval: %d\r\n",interval);
	signal(SIGALRM,alarm_handler);
	alarm(interval);
	printf("Exiting alarm signal handler. \r\n");
	if(alarm_count--==0)
	{
		run = 0;
	}
}

int main_proxy(int argc,char *argv[])
{
	/*Correct way to copy a string*/
	char *interval_buffer = malloc(sizeof(char)*(strlen(argv[1]) +1));
	strcpy(interval_buffer,argv[1]);
	/*A short cut to malloc + strlen + strcpy is to use strdup*/
	
	/*This is a static buffer of 10 characters, and will segfault under the right conditions.*/
	char count_buffer[10];
	strcpy(count_buffer,argv[2]);
	
	/* unsafe string to integer conversion*/
	interval = atoi(interval_buffer);
	alarm_count = atoi(count_buffer);

	printf("My Parent Process ID: %d\r\n",getppid());
	printf("My Process ID: %d\r\n",getpid());
	printf("<interval> in seconds is: %d\r\n",interval);
	printf("<alarm_count> is: %d\r\n",alarm_count);
	printf("Total Seconds: %d\r\n", alarm_count * interval);

	signal(SIGALRM,alarm_handler);
	alarm(interval);
	free(interval_buffer);
}



int main(int argc, char *argv[])
{
	int i =0;
	if(argc!=3)
	{
		printf("Error, wrong argument count: %d\r\n",argc);
		for(i=0; i<argc;i++)
		{
			printf("Argument: %d is %s\r\n",i+1,argv[i]);
		}
		printf("Usage is:  ./<prgm> <interval> <count>\r\n");
		printf("<interval> is number of seconds to delay and between signals.");
		return -1;
	}

	main_proxy(argc,argv);

	while(1 == run)
	{
		pause();
	}

	return 0;
}


