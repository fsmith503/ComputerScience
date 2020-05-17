#ifndef ANAGRAM_H
#define ANAGRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 0
Statement: this is my own work, except that:
The AnagramList and StringList struct 
were provided to us by the professors. In
addition to the methods names and parameters.
*/

struct StringList
{
	struct	StringList* Next;
	char *Word;
};

struct AnagramList
{
	struct StringList *Words;
	struct AnagramList *Next;
	char *Anagram;
};

struct StringList *MallocSList(char *word);

void AppendSList(struct StringList **head, struct StringList *node);

void FreeSList(struct StringList **node);

void PrintSList(FILE *file,struct StringList *node);

int SListCount(struct StringList *node);

struct AnagramList* MallocAList(char *word);

void FreeAList(struct AnagramList **node);

void PrintAList(FILE *file,struct AnagramList *node);

void AddWordAList(struct AnagramList **node, char *word);

#endif
