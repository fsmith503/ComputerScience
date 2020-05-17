#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagram.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 0
Statement: this is my own work
*/

int main(int argc, char* argv[]){
	if(argc == 1){
		struct AnagramList *AL = NULL;
		char *buffer = (char *)malloc(sizeof(char) * 1024);
    	while(!feof(stdin)){
    		scanf("%s", buffer);
    		if(!feof(stdin)){
    			char *input = strdup(buffer);
    			AddWordAList(&AL,input);
    			free(input);
    		}
    	}
    	PrintAList(stdout, AL);
		FreeAList(&AL);
		free(buffer);
	}

	if(argc == 2){
		FILE* inputFile = fopen(argv[1], "r");
		if(inputFile == NULL){
			printf("The program has received an empty file, the programm will now terminate.\n");
			exit(1);
		}
		struct AnagramList *AL = NULL;
		char *buffer = (char *)malloc(sizeof(char) * 1024);
    	while(!feof(inputFile)){
    		fscanf(inputFile, "%s", buffer);
    		if(!feof(inputFile)){
    			char *input = strdup(buffer);
    			AddWordAList(&AL,input);
    			free(input);
    		}
    	}
	    PrintAList(stdout, AL);
	    FreeAList(&AL);
	   	fclose(inputFile); 
	    free(buffer);
	}

	if(argc == 3){
			FILE* inputFile = fopen(argv[1], "r");
			FILE* outputFile = fopen(argv[2], "w");
		if(inputFile == NULL){
			printf("The program has received an empty file, the programm will now terminate.\n");
			exit(1);
		}
		struct AnagramList *AL = NULL;
		char *buffer = (char *)malloc(sizeof(char) * 1024);
		    	while(!feof(inputFile)){
    		fscanf(inputFile, "%s", buffer);
    		if(!feof(inputFile)){
    			char *input = strdup(buffer);
    			AddWordAList(&AL,input);
    			free(input);
    		}
    	}
    PrintAList(outputFile, AL);
    FreeAList(&AL);
   	fclose(inputFile); 
   	fclose(outputFile);
    //free(AL);
    free(buffer);
	}
	return 0;
}

















