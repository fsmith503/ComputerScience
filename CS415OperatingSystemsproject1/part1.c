#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//read how many lines there are, √ make that many structures, and save it, zoey makes a list of them.
//for each line count how many words, using strtok, then strdup,
// allocate an array of pointers to strings + 1, null
// using string tok, each time new word, string dup into new location into array...

// add print struct
//for each line, call string tok, i need to string dup that, into the


// COMMENTED THIS BELOW STRUCT OUT BECAUSE OF ISSUE WITH MY HEADER FLIE

// struct cmd_struct
// {
// 	char *cmd;
// 	char **args;
// 	int pid;
// 	int argCount;
// };


/// press enter and the program quits



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

void launchWorkload(struct cmd_struct* inputStruct, int numPrograms){
	int i = 0;
	for(; i < numPrograms; i++){
		inputStruct[i].pid = fork();
		if(inputStruct[i].pid < 0){
			exit(1);
		}
		if(inputStruct[i].pid == 0){
			execvp(inputStruct[i].cmd, inputStruct[i].args);
			//free stuff here if exec vp fails
			freeStruct(inputStruct, numPrograms);
			free(inputStruct);
			exit(-1);
		}
		if(inputStruct[i].pid == 0){
			//you are the parent
		}
 	}
 	int k = 0;
 	for(; k < numPrograms-1; k++){
 		wait(&inputStruct[k].pid);
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
	int var = argc;
	int count = getCount(var, argv);
    struct cmd_struct *realStruct = Malloc_cmd_struct(count);
	FILE* inputFile2 = fopen(argv[1], "r");
	if(inputFile2 == NULL){
		//printf("The program has received an empty file, the programm will now terminate.\n");
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
	    free(secondlinecopy); // VALGRIND TESTING
      }
      fclose (inputFile2); 
      launchWorkload(realStruct, count);
      freeStruct(realStruct, count);
      free(realStruct);// VALGRIND TEST
	return 0;
}





























