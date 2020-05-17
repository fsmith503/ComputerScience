#ifndef HEADERPROJECT1_H
#define HEADERPROJECT1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 1
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, other people in class....
*/


enum State {NotStarted, Running, Paused, Exited};

 struct sigaction sa;
 struct itimerval timer;
 //source http://www.informit.com/articles/article.aspx?p=23618&seqNum=14

struct cmd_struct
{
	char *cmd;
	char **args;
	int pid;
	int argCount;
	enum State state_enum;
	int HasExited;
};

int CheckIfAllProgramsExitedENUM();
void freeStruct();


#endif

