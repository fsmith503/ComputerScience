#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
// Additional types needed.
#include  <signal.h>
// Signal informational Page(s): 	http://www.csl.mtu.edu/cs4411.ck/www/NOTES/signal/kill.html

#include <unistd.h>
// Process identifier page(s):		http://man7.org/linux/man-pages/man2/getpid.2.html

size_t node_count =0;

size_t savetype = -1;

pid_t my_process = -1;
pid_t parent_process =-1;

volatile int run = 1;
volatile int handled =0;
volatile int interval = 1;

void earth_quake(int sig)
{
	printf("Insider Earthquake signal handler. Signal Number: %d\r\n",sig);
	int magnitude = rand() % 10;
	int me_or_parent = rand() % 2;
	if(0==me_or_parent)
	{
		printf("Sending My Process Signal: %d\r\n",magnitude);
		kill(my_process,magnitude);
	}
	else
	{
		printf("Sending My Parent Process Signal: %d\r\n",magnitude);
		kill(parent_process,magnitude);
	}
	printf("Exiting Earthquake signal handler. Signal Number: %d\r\n",sig);
	printf("Starting alarm with interval: %d\r\n",interval);
	alarm(interval);
}

void simple_function0(int signal)
{
	printf("Trapped User Signal 1: %d\r\n",signal);
}

void simple_function1(int signal)
{
	simple_function0(signal);
}

void sigusr1(int signal)
{
	simple_function1(signal);
}

int main(int argc, char *argv[])
{
	int i =0;
	if(argc!=2)
	{
		printf("Error, wrong argument count: %d\r\n",argc);
		for(i=0; i<argc;i++)
		{
			printf("Argument: %d is %s\r\n",i+1,argv[i]);
		}
		printf("Usage is:  ./earth_quake <interval>\r\n");
		printf("<interval> is number of seconds to delay and between signals.");
		return -1;
	}
	// unsafe string to integer conversion.
	interval = atoi(argv[1]);

	my_process =getpid();
	parent_process = getppid();

	printf("My Process ID: %d\r\n",my_process);
	printf("My Parent Process ID: %d\r\n",parent_process);
	printf("<interval> in seconds is: %d\r\n",interval);

	signal(SIGALRM,earth_quake);
	signal(SIGUSR1,sigusr1);
	alarm(interval);
	while(1 == run)
	{
		pause();
	}
	return 0;
}

