#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int seconds = 1;
	if(argc >1)
	{
		seconds = atoi(argv[1]);
	}
	if( seconds < 1)
	{
		seconds = 1;
	}
	int i=0;
	for(i=0; i<seconds; i++)
	{
		printf("tester %d: with %d of %d\n",getpid(),i,seconds);
		fflush(stdout);
		sleep(1);
	}
	printf("tester %d: with %d of %d\n",getpid(),seconds,seconds);
	fflush(stdout);
	
}
