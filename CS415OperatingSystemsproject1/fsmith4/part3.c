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

sigset_t sigMaskTest;
int ProgramCount;
struct cmd_struct *PCB = NULL; 
int CurrentProgram = 0;
int StartRun = 0;
int Exit = 0;
/// press enter and the program quits

void setAlarm()
{
  struct itimerval old, new;                      // SHOULD THIS BE CHANGED
  // how much time you want timer to wait before going off each time
  new.it_interval.tv_usec = 1000; // microseconds //10000
  new.it_interval.tv_sec = 0; // seconds
  new.it_value.tv_usec = 1000; // microseconds //10000
  new.it_value.tv_sec = 0;//(long int) seconds;
  setitimer(ITIMER_REAL, &new, &old);   
}


struct cmd_struct *Malloc_cmd_struct(int Commands){
	struct cmd_struct *S1 = (struct cmd_struct*)malloc(Commands * sizeof(struct cmd_struct)); 
	S1->pid = -1;
	return S1;
	};

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
   	for(; intVariable < programCount; intVariable++){
   		int status = 0;
   		if(waitpid(inputStruct[intVariable].pid, &status, WNOHANG|WUNTRACED) > 0){
    		if (WIFEXITED(status) != 0){
    		}
    	} 
	}
	if(intVariable == programCount){
		return 1; // all programs have exited
	}
	return 0; // all programs have not exited
}

void SIGUSR1Handler(int signal){
     StartRun = 1;
}

void SIGUSR2Handler(int signal){
     Exit = 1;
}

void waitOnAllExit(){
	//Create a function to wait on signal using sigwait.  
	// read https://stackoverflow.com/questions/6326290/about-the-ambiguous-description-of-sigwait
	sigset_t mask, oldmask;
		/* Set up the mask of signals to temporarily block. */
		sigemptyset (&mask);
		sigaddset (&mask, SIGUSR1);
		sigaddset (&mask, SIGUSR2);
		sigaddset (&mask, SIGCHLD);
		sigaddset (&mask, SIGALRM);
		/* Wait for a signal to arrive. */
		sigprocmask (SIG_BLOCK, &mask, &oldmask);
		while (Exit==0){
		  	sigsuspend (&oldmask);
		}
		sigprocmask (SIG_UNBLOCK, &mask, NULL);
}

void SIGCHLDHANDLER(int signal_num){
	sigprocmask (SIG_BLOCK, &sigMaskTest, NULL);	
	int numIterator = 0;
   	for(; numIterator < ProgramCount; numIterator++){
   		int status1 = 0;
   		if(waitpid(PCB[numIterator].pid, &status1, WNOHANG|WUNTRACED) > 0){
   			if (WIFEXITED(status1)){
    			PCB[numIterator].HasExited = 1;
    		}  
    	}
   	}
   	sigprocmask (SIG_UNBLOCK, &sigMaskTest, NULL);
}

void SIGALRMHANDLER(int signal_num){
	// in alarm handler, we update the enum state, based on what we see from has exited int
	sigprocmask (SIG_BLOCK, &sigMaskTest, NULL);	
	if(PCB[CurrentProgram].HasExited == 1) {
		PCB[CurrentProgram].state_enum = Exited;
	}
	if(PCB[CurrentProgram].state_enum == Running){
		// send SIGSTOP to pause the child
		PCB[CurrentProgram].state_enum = Paused;
    	kill(PCB[CurrentProgram].pid, SIGSTOP);
	}
	if (CheckIfAllProgramsExitedENUM() == 1/* && CheckIfAllProgramsExitedINT() == 1*/){
		kill(getpid(),SIGUSR2);
		//return;
	}
	// DO WHILE LOOP FIXES THE LOOP BELOW THE LOOP
	int exitCondition = 0;
	do {
		if (exitCondition > ProgramCount){
			break;
		}
	CurrentProgram = (CurrentProgram + 1 ) % ProgramCount;
	exitCondition = exitCondition + 1;
	} while(PCB[CurrentProgram].state_enum == Exited);
	if (PCB[CurrentProgram].state_enum == NotStarted){
		// Send SIGUSR1 to start child.
		kill(PCB[CurrentProgram].pid, SIGUSR1);
		// CHANGE ENUM STATE TO RUNNING ???
		PCB[CurrentProgram].state_enum = Running;
	}
	else {
		//    Send SIGCONT to resume child.
		kill(PCB[CurrentProgram].pid, SIGCONT);
		// CHANGE ENUM STATE TO RUNNING ???
		PCB[CurrentProgram].state_enum = Running;
	}
	sigprocmask (SIG_UNBLOCK, &sigMaskTest, NULL);
}

int CheckIfAllProgramsExitedINT(){
	//Create a helper function to loop over all programs, and return true/1 if all PCB.HasExit is true. *all children exited* DONE
	// THIS FUNction does the above line
	int resultInt = 1;
	int indexInt = 0;
	for(; indexInt < ProgramCount; indexInt++){
		if(PCB[indexInt].HasExited == 1) {
			resultInt = 1;
		}
		else{
			resultInt = 0;
			break;
		}
	}
	return resultInt;
}

int CheckIfAllProgramsExitedENUM(){
	int resultEnum = 1;
	int indexEnum = 0;
	for(; indexEnum < ProgramCount; indexEnum++){
		if(PCB[indexEnum].state_enum == Exited) {
			resultEnum = 1;
		}
		else{
			resultEnum = 0;
			break;
		}	
	}
	return resultEnum;
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
			int execVPFail = 0;
			execVPFail = execvp(inputStruct[i].cmd, inputStruct[i].args);
			//free stuff here if exec vp fails
			freeStruct(inputStruct, numPrograms);
			free(inputStruct);
			// this is why the valgrind is messing up
			if(execVPFail == -1){
			//printf("EXECVP FAILED There is an error in the system, the program went past executing. Exiting the program now\n");
			}
			//free(programs,programcount);// free this becasuse
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

void signalSetup(){
	signal(SIGUSR1, SIGUSR1Handler);
    signal(SIGUSR2, SIGUSR2Handler);
    signal(SIGALRM, SIGALRMHANDLER);
    signal(SIGCHLD, SIGCHLDHANDLER);
	sigemptyset (&sigMaskTest);
	sigaddset (&sigMaskTest, SIGUSR1);
	sigaddset (&sigMaskTest, SIGUSR2);
	sigaddset (&sigMaskTest, SIGCHLD);
	sigaddset (&sigMaskTest, SIGALRM);
}

int main(int argc, char* argv[]){
	int var = argc;
	int count = getCount(var, argv);
	    PCB = Malloc_cmd_struct(count);
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
		    PCB[counter].args = mallocWordStruct(wordSize);
		    PCB[counter].argCount = wordSize;
		    PCB[counter].HasExited = 0;
		    PCB[counter].state_enum = NotStarted;
	      	char *temp;
	      	char *tempcmd;
	    	temp = strtok(secondlinecopy, " \n");
	    	tempcmd = temp;
	    	PCB[counter].cmd = strdup(tempcmd); // free when done
			 int struct_count = 0;
		    while( temp != NULL ) {
		       		PCB[counter].args[struct_count] = strdup(temp); // free when done
		       		struct_count = struct_count + 1;
		        	temp = strtok(NULL, " \n");
		    } 
		    counter = counter + 1;
		    free(firstlinecopy);
	    	free(secondlinecopy); // VALGRIND TESTING
	      }
	      fclose (inputFile2); 
	    ProgramCount = count;
		signalSetup();
	    launchWorkload(PCB, count); 
	    setAlarm();
	    waitOnAllExit();
	    freeStruct(PCB, count);
		free(PCB);
		return 0;
	} // end of main
	


