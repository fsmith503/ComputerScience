#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include "headerProject1.h"
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 1
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, other people in class....
*/


int StartRun =0;
struct cmd_struct *Malloc_cmd_struct(int Commands){
	struct cmd_struct *S1 = (struct cmd_struct*)malloc(Commands * sizeof(struct cmd_struct)); 
	S1->pid = -1;
	return S1;
	}

char** mallocWordStruct(int numberOfWords){
	char **temp;
	temp = (char **)malloc((numberOfWords+1) * sizeof(char*));
	temp[numberOfWords] = NULL;
	return temp;
} 

void freeStruct(struct cmd_struct* inputFreeStruct, int value){
	int a = 0;
	for(; a < value; a++){
		free(inputFreeStruct[a].cmd);
		int freeCount = 0;
		for(; freeCount < inputFreeStruct[a].argCount; freeCount++){
			free(inputFreeStruct[a].args[freeCount]);
		}
		free(inputFreeStruct[a].args);
	}

}

int AllProgramsExited(struct cmd_struct *inputStruct, int programCount){
   	int intVariable = 0;
   	int exitedCountVar = 0;
   	for(; intVariable < programCount; intVariable++){
   		int status = 0;
    	if(waitpid(inputStruct[intVariable].pid, &status, WNOHANG))
    	{
    		if (WIFEXITED(status)){
    			//This macro returns a nonzero value if the child process terminated normally with exit or _exit.
    			// intVariable++
    			exitedCountVar++;
    		}
    	}
	}
	if(exitedCountVar == programCount){
		return 1;
	}
	return 0;
}


void SIGUSR1Handler(int signal){
     StartRun = 1;
}

void launchWorkload(struct cmd_struct* inputStruct, int numPrograms){
	int i = 0;
	for(; i < numPrograms; i++){
		inputStruct[i].pid = fork();
		if(inputStruct[i].pid < 0){
			//handle the error appropriately
			//error exit the system
			printf("There is an error in the system, the PID is less than 0 which means that it didnt create. Exiting the program now\n");
			exit(1);
		}
		if(inputStruct[i].pid == 0){
			// wait until i get signal from parent
			// signal at the beginning so it knows about the singal
			while(StartRun == 0){
				//microsleep
				usleep(1000);
			}

			printf("bye message about to start");
			execvp(inputStruct[i].cmd, inputStruct[i].args);
			//log error starting program failed.
			//free stuff here if exec vp fails
			freeStruct(inputStruct, numPrograms);
			free(inputStruct);
			// this is why the valgrind is messing up
			printf("There is an error in the system, the program went past executing. Exiting the program now\n");
			//exit so duplicate copy of MCP doesnt run/fork bomb.
			//your the child
			exit(-1);
		}
		if(inputStruct[i].pid > 0){
			//you are the parent
		}
 	}
}


int getCount(int argc, char* argv[]){
	int numOfCommands = 0;
	char c;
	if(argc == 1){
    	//stdin stdout case
	}
	if(argc == 2){
		FILE* inputFile = fopen(argv[1], "r");
		if(inputFile == NULL){
			//printf("The program has received an empty file, the programm will now terminate.\n");
			exit(1);
		}	
		//read character by character and check for new line	
		while((c=fgetc(inputFile))!=EOF)
		{
			if(c=='\n')
				numOfCommands++;
		}
		//close the file
		fclose(inputFile);
		
	} // end of if argc == 2
	return numOfCommands;
}


int main(int argc, char* argv[]){
    //printf("the number of lines in the file is: %d\n",count);
	int var = argc;
	int count = getCount(var, argv);
    // the count goes above here
    struct cmd_struct *realStruct = Malloc_cmd_struct(count);
    //struct cmd_struct* array[count];
	FILE* inputFile2 = fopen(argv[1], "r");
	if(inputFile2 == NULL){
		printf("The program has received an empty file, the programm will now terminate.\n");
		exit(1);
	}
   	char line [ 1024 ];
   	int counter = 0;
      while ( fgets ( line, sizeof line, inputFile2 ) != NULL ) /* read a line */
      {
      	char *firstlinecopy = strdup(line); // free when done
      	char *secondlinecopy = strdup(line); // free when done
      	int wordSize = 0;
      	char *looptemp;
      	looptemp = strtok(firstlinecopy, " ");
	    while( looptemp != NULL ) {
	        looptemp = strtok(NULL, " ");
	        wordSize = wordSize + 1;
	    }
	    realStruct[counter].args = mallocWordStruct(wordSize);
	    realStruct[counter].argCount = wordSize;
      	char *temp;
      	char *tempcmd;
		    	temp = strtok(secondlinecopy, " \n");
		    	tempcmd = temp;
		    	realStruct[counter].cmd = strdup(tempcmd); // free when done
		 int struct_count = 0;
	    while( temp != NULL ) {
	       		realStruct[counter].args[struct_count] = strdup(temp); // free when done
	       		struct_count = struct_count + 1;
	        	temp = strtok(NULL, " \n");
	    } 
	    counter = counter + 1;
	    free(firstlinecopy);
	    //free(tempcmd); //VALGRIND TESTING
	    free(secondlinecopy); // VALGRIND TESTING
      }
      fclose (inputFile2); 
    signal(SIGUSR1, SIGUSR1Handler);
    launchWorkload(realStruct, count);
    int val = 0;
    for(; val < count; val++){
    	//printf("sent out sigusr1\n");
    	kill(realStruct[val].pid, SIGUSR1);
    }
    int val1 = 0;
    for(; val1 < count; val1++){
    	//printf("sent out sig stop\n");
    	kill(realStruct[val1].pid, SIGSTOP);
    }
    int val2 = 0;
    for(; val2 < count; val2++){
    	kill(realStruct[val2].pid, SIGCONT);
    	//printf("sent out sigcont\n");
    }
    //Again, once all of the processes are back up and running, for each program, the MCP waits for it toterminate. 
    //After all programs have terminated, the MCP will exit.
    while(AllProgramsExited(realStruct, count) == 0){ // this runs indefinetly when i change to != 0
    	//printf("loop all programs exited HAPPENING\n");
    }
    freeStruct(realStruct, count);
    free(realStruct);// VALGRIND TEST
	return 0;
}


























