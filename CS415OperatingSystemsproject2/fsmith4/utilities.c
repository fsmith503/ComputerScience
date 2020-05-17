#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilities.h"

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/

struct FileLines *MakeEmptyLines(char *name,int length)
{
        struct FileLines *lines = (struct FileLines*)malloc(sizeof(struct FileLines));
        lines->FileName = strdup(name);
        lines->LineCount = length;
        lines->Lines = (char **) malloc(sizeof(char *)*(lines->LineCount+1));
        for(int i =0; i< lines->LineCount +1; i++)
        {
                lines->Lines[i] = NULL;
        }
        return lines;
}

int CompareFileLines(struct FileLines *f0, struct FileLines *f1)
{
        if(f0->LineCount != f1->LineCount)
                return -1;
        if(strcmp(f0->FileName,f1->FileName)!=0)
                return -1;
        for(int i=0; i< f0->LineCount; i++)
        {
                if(f0->Lines[i] == NULL && f1->Lines[i] != NULL)
                {
                       return -1;
                }
                if(f0->Lines[i] != NULL && f1->Lines[i] == NULL)
                {
                        return -1;
                }
                if(f0->Lines[i] != NULL && f1->Lines[i] != NULL)
                {
                        if(strcmp(f0->Lines[i],f1->Lines[i])!=0)
                        {
                            return -1;
                        }
                }
        }
        return 0;
}

int GetLineCount(char *filename)
{
	FILE *file = fopen(filename,"r");
	if(file == NULL)
        {
        	return -1;
        }
	char buffer[1024];
	int returnValue = 0;
	while( fgets(buffer, sizeof(buffer), file) != NULL)
	{
		returnValue += 1;	
	}
	fclose(file);
	return returnValue;
}

struct FileLines *LoadAFile(char *filename)
{
        int count = GetLineCount(filename);
        if(count <1)
        {
                return NULL;
        }
        struct FileLines *lines = (struct FileLines*)malloc(sizeof(struct FileLines));
        lines->FileName = strdup(filename);
        lines->LineCount = count;
        lines->Lines = (char **) malloc(sizeof(char *)*(lines->LineCount+1));
        lines->Lines[lines->LineCount] = NULL;

	FILE *file = fopen(filename,"r");
	char buffer[1024];
        for(int i=0 ;i<lines->LineCount;i++)
        {
        	fgets(buffer,sizeof(buffer),file);
        	
        	int len = strlen(buffer);
        	for(int j=len-1; j>=0; j--)
        	{
        	        char c = buffer[j];
        	        if(c=='\n' || c=='\r')
        	        {
        	                buffer[j] = 0;
        	        }
        	        else
        	        {
        	                break;
        	        }
        	}
        	lines->Lines[i] = strdup(buffer);
        }
	fclose(file);
	return lines;
}

void ZeroCharString(char *str)
{
        ZeroByteBuffer(str,strlen(str));
}

void ZeroByteBuffer(char *buf,int len)
{
        for(int i=0; i<len; i++)
        {
                buf[i] = 0;
        }
}

void ZeroFreeString(char *str)
{
        ZeroCharString(str);   // Now strings are always zeroed then freed.
        free(str);
}

void FreeFile(struct FileLines *file)
{
        // Give the address of our pointer to a string to be freed.
        ZeroFreeString(file->FileName);               
        for(int i=0; i < file->LineCount; i++)
        {
                if((file->Lines[i])!=NULL)
                {
                        ZeroFreeString(file->Lines[i]); // find the line number, and pass the address of that pointer.
                }
        }    
        free(file->Lines); // free the array of pointers.
        free(file);         
}
