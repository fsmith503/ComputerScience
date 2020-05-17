#ifndef UTILITIES_H
#define UTILITIES_H
/*
Authorship Statement
name: Franklin Smith
duckid: fsmith4
title: CIS 415 Project 2
Statement: this is my own work
recieved help from jeanie chen, roscoe cascita, bryce, matt, roscoe other people in class....
*/


struct FileLines
{
        char *FileName;
        char **Lines;
        int LineCount;
};

void ZeroCharString(char *str);
void ZeroByteBuffer(char *buf,int len);
void ZeroFreeString(char *str);

int GetLineCount(char *filename);

int CompareFileLines(struct FileLines *f0, struct FileLines *f1);
struct FileLines *MakeEmptyLines(char *name,int length);
struct FileLines *LoadAFile(char *filename);
void FreeFile(struct FileLines *file);


#endif
