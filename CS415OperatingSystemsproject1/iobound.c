#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define MBYTE 1024*1024*10

#define SEC_PER_MIN 60
#define SEC_PER_HOUR (SEC_PER_MIN*60)

#define STR_SIZE 256

char *b = NULL;
FILE *fdw = NULL;
FILE *fdr = NULL;
char filename[STR_SIZE];

void DoBufferMemCheck(long long cycles)
{
	int i=0;
	if(b == NULL)
	{
		for(i=0; i<STR_SIZE;i++)
		{
			filename[i] = 0;
		}
		b = malloc(sizeof(char) * MBYTE);
 	  	for(i =0; i< MBYTE; i++)
    		{
			b[i] = rand() %256;
    		}
    		    
    		sprintf(filename,"mbtest_%d",rand());

    		fdw = fopen(filename, "w");
    		fdr = fopen(filename, "r");
	}
	long long cycle = cycles%100;
   	if(cycle%100==0)
    	{
   		for(i =0; i< MBYTE; i++)
    		{
			b[i] = rand() %256;
    		}
    	}	
}

int GetCurrentSecondOfDay()
{
	//https://stackoverflow.com/questions/2242963/get-the-current-time-in-seconds
	time_t now;
	struct tm *tm;
	now = time(0);
	if((tm = localtime(&now)) == NULL)
	{
		fprintf(stderr,"Error extracting time stuff\n");
		exit(-1);
	}
	int hour_seconds = tm->tm_hour*SEC_PER_HOUR;
	int min_seconds = tm->tm_min*SEC_PER_MIN;
	int seconds = tm->tm_sec;
	return hour_seconds + min_seconds + seconds;
}

int HasXSecondsPassed(int X, int start, int end)
{
	int span = end - start;
	if( span > X)
	{
		return 1;
	}
	return 0;
}

void PrintUsage(int argc, char**argv)
{
	fprintf(stderr,"\nInvalid command line entered: \n");
	int i = 0;
	for(i =0; i<argc; i++)
	{
		fprintf(stdout,"Argument %d is: \"%s\"\n",i,argv[i]);
	}

	fprintf(stderr,"\niobound has 2 modes, both requires 2 arguments:\n");
	fprintf(stderr,"Mode 1: Calculate avg cycles per X minute.\n");
	fprintf(stderr,"iobound -minutes X\n");
	fprintf(stderr,"Mode 2: N is avg cycles per minute. X is the number of minutes to run.\n");
	fprintf(stderr,"iobound -cycles N -minutes X\n\n");

	exit(-1);
}


void PrintCycles(int start,int end, long long cycles)
{
	int span = end-start;
	int seconds = span%60;
	int minutes = span/60;

	fprintf(stdout,"Total Minutes:Seconds = %d:%d\n",minutes,seconds);
	fprintf(stdout,"Total Cycles: %lld\n",cycles);
	
	double avg_cyc_per_sec = ((double)cycles)/((double)span);
	fprintf(stdout,"Avg Cycles Per Sec: %f\n",avg_cyc_per_sec);

	double avg_cyc_per_min = ((double)cycles)/((double)minutes);
	fprintf(stdout,"Avg Cycles Per Min: %f\n",avg_cyc_per_min);
}


long long IOWork(long long cycles)
{
    long long cycles_count =0;
    DoBufferMemCheck(cycles);

    fwrite(b, 1, MBYTE, fdw);
    rewind(fdw);
    cycles_count+= 1;
 
    fread(b,1,MBYTE,fdr);
    rewind(fdr);
    cycles_count +=1;
 
    return cycles_count;
}

void DoCyclesPerMinutesCalc(int minutes)
{
	int start = GetCurrentSecondOfDay();
	int end = GetCurrentSecondOfDay();
	int lastend = end;
	long long cycles = 0;
	int done = 0;
	do
	{
		//printf("Cycle %lld in CyclesPerMinutesCalc %d\n",cycles,minutes);
		cycles += IOWork(cycles);
		end = GetCurrentSecondOfDay();
		if(HasXSecondsPassed(minutes*SEC_PER_MIN,start,end)==1)
		{
			done=1;
		}
	//}while(HasXSecondsPassed(minutes*SEC_PER_MIN,start,end)==0);
	}while(done ==0);
	end = GetCurrentSecondOfDay();
	PrintCycles(start,end,cycles);
}

void DoTotalWorkCycles(long long work_cycles)
{
	int start = GetCurrentSecondOfDay();
	int end = GetCurrentSecondOfDay();
	long long cycles = 0;
	fprintf(stdout,"Do IO Work Cycles: %lld\n",work_cycles);
	while(cycles < work_cycles)	
	{
		//printf("Cycle %lld in DoTotalWorkCycles %lld\n",cycles,work_cycles);
		cycles += IOWork(cycles);
		end = GetCurrentSecondOfDay();
	}
	end = GetCurrentSecondOfDay();	
	PrintCycles(start,end,cycles);
}

int main(int argc, char **argv) 
{
    long long i;
    long long cycles = 0;
    long long minutes = 0;
    int use_cycles = 0;

/*
 * process environment variable and command line arguments
 */
    if( ! ((argc ==3)||(argc==5)))
    {
	    PrintUsage(argc,argv);
    }   
    for (i = 1; i + 1< argc; i++) {
        if (strcmp(argv[i], "-minutes") == 0) {
            i++;
            minutes = (long long)atoi(argv[i]);
	    
        } else if (strcmp(argv[i], "-cycles") == 0) 
	{
		if(argc!=5)
		{
			PrintUsage(argc,argv);
		}

            i++;
            cycles = strtoll(argv[i],NULL,10);
	    use_cycles =1;
        } else {
            fprintf(stderr, "Illegal flag: `%s'\n", argv[i]);
            PrintUsage(argc,argv);
        }
    }
        DoBufferMemCheck(0);


    if(use_cycles)
    {
	DoTotalWorkCycles(cycles*minutes);
    }
    else
    {
	DoCyclesPerMinutesCalc(minutes);
    }
    free(b);
    fclose(fdw);
    fclose(fdr);
    remove(filename);

   return 0;
}
