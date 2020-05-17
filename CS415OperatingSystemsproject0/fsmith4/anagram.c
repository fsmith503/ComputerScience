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
were provided to us by the professors.
Quick sort implementation is used from geeks
for geeks. URL: https://www.geeksforgeeks.org/quick-sort/
*/



/*L i s t   o f   anagrams   s t r u c t u r e*/
struct AnagramList
{
	struct StringList *Words;
	struct AnagramList *Next;
	char *Anagram;
};

/*L i s t   o f   s t r i n g s   s t r u c t u r e*/
struct StringList
{
	struct	StringList* Next;
	char *Word;
};


void swap(char* a, char* b) 
{ 
    char t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (char arr[], int low, int high) 
{ 
    char pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  	int j = low;
    for (; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 


/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(char arr[], int low, int high) 
{ 
	//printf("string val before quicksort %s\n", arr);
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


/*C r e a t e   a  new   s t r i n g   l i s t   node*/
struct StringList *MallocSList(char *word){
	//printf("MallocSList called\n");
	 struct StringList *S1 = (struct StringList*)malloc(sizeof(struct StringList));
	 S1->Word = (char *)malloc((strlen(word) +1) * sizeof(char));
	 S1->Next = NULL;
	 S1->Word[strlen(word)] = '\0'; // fixed null terminator above
	 strcpy(S1->Word, word);
	 return S1;
};

/*C r e a t e   a  new  anagram   node ,   i n c l u d i n g   t h e   s t r i n g   l i s t   node   w i t h   t h e   word .*/
struct AnagramList* MallocAList(char *word){
	//printf("MallocAList called\n");
	struct AnagramList *AL = (struct AnagramList*)malloc(sizeof(struct AnagramList));
	AL->Words = MallocSList(word);
	AL->Next = NULL;
	AL->Anagram = malloc((strlen(word)+1) * sizeof(char));
	AL->Anagram[strlen(word)] = '\0'; // fixed null terminator above
	strcpy(AL->Anagram, word); 
	int i = 0;
	for(; i < strlen(AL->Anagram); i++){
		AL->Anagram[i] = tolower(AL->Anagram[i]); 
	}
  	quickSort(AL->Anagram, 0, strlen(AL->Anagram)-1);
	return AL;
}

/*Append  a   s t r i n g   l i s t   node   t o   t h e   end / t a i l   o f   a   s t r i n g   l i s t*/
void AppendSList(struct StringList **head, struct StringList *node){
	//printf("AppendSList called\n");
	struct StringList* current = *head;
	while(current->Next != NULL){
		current = current->Next;
	}
	current->Next = node;
}


/*Add  a  new  word   t o   t h e   anagram   l i s t*/
void AddWordAList(struct AnagramList **node, char *word){
	//printf("AddWordAList called\n");
	struct AnagramList *current = NULL;
	struct AnagramList *a = NULL;
	if(*node == NULL){
		*node = MallocAList(word);
		return;
	}
	if(*node != NULL){
		current = *node;
		a = current->Next;
	}
	char* wordcpy = strdup(word);
	int size = strlen(wordcpy);
	int k = 0;
	for(; k < size; k++){
			wordcpy[k] = tolower(wordcpy[k]);
	}
	char* sortedWord = strdup(wordcpy);
	free(wordcpy); // valgrind memory test
	quickSort(sortedWord, 0, strlen(sortedWord)-1);
	while(a){
		int result = strcmp(current->Anagram,sortedWord);
		if(result == 0){
			struct StringList* word2add = MallocSList(word);
			AppendSList(&current->Words,word2add); 
			free(sortedWord);
			return;
		}
		current = a;
		a = current->Next;
	}
	char* sortedAnagram = strdup(current->Anagram);
	quickSort(sortedAnagram, 0, strlen(sortedAnagram)-1);
	int result = strcmp(sortedAnagram,sortedWord);
	free(sortedWord);
	free(sortedAnagram);
		if(result == 0){
			struct StringList* word2add = MallocSList(word);
			AppendSList(&current->Words,word2add); 
			return;
		}
	struct AnagramList *newAddition = MallocAList(word); 
	current->Next = newAddition;
}

/*F r e e   a   s t r i n g   l i s t  ,   i n c l u d i n g   a l l   c h i l d r e n*/
void FreeSList(struct StringList **node){
	//printf("FreeSList called\n");
	struct StringList* current = NULL;
	struct StringList* a = NULL;
	if(*node == NULL){
		return;
	}
	if(*node != NULL){
		current = *node;
		struct StringList *temp = current->Next;
		if(temp == NULL){
			free(current->Word);
			free(current);
			return;
		}
		if(temp != NULL){
			a = temp;
				while(current){
					a = current->Next;
					free(current->Word);
					free(current);
					current = a;
				}
		}
	}
}

/*F r e e   an   anagram   l i s t  ,   i n c l u d i n g   anagram   c h i l d r e n   and   s t r i n g   l i s t   words .*/
void FreeAList(struct AnagramList **node){
	//printf("FreeAList called\n");
	struct AnagramList *AnagramListToFree = NULL;
	struct AnagramList *NextALPtr = NULL;
	if(*node == NULL){
	}
	if(*node != NULL){
		AnagramListToFree = *node;
		if(AnagramListToFree->Words == NULL){

		}
		if(AnagramListToFree->Words != NULL){
			while(AnagramListToFree){
				NextALPtr = AnagramListToFree->Next;
				FreeSList(&AnagramListToFree->Words); 
				free(AnagramListToFree->Anagram);
				free(AnagramListToFree);
				AnagramListToFree = NextALPtr; 
			}
		}
	}
}

/*Return   t h e   number   o f   s t r i n g s   i n   t h e   s t r i n g   l i s t .*/
int SListCount(struct StringList *node){
	//printf("SListCount called\n");
	int result = 0;
	struct StringList* var = node;
	while(var){
		result = result + 1;
		var = var->Next;
	}
	return result;
}

/*Format   o u t p u t   t o   a   f i l e   a c c o r d i n g   t o   s p e c i f i c a t i o n .*/ 
void PrintSList(FILE *file, struct StringList *node){
	//printf("PrintSList called\n");
	struct StringList* Input = NULL;
	if(node == NULL){
		return;
	}
	if(node != NULL){
	Input = node;
	}
	while(Input){
		//printf("printing in print s list");
		fprintf(file,"\t%s\n", Input->Word);
		Input = Input->Next;
	}
}

/*Format   o u t p u t   t o   a   f i l e  ,   p r i n t   anagram   l i s t   w i t h   words ,   a c c o r d i n g   t o   s p e c*/
void PrintAList(FILE *file,struct AnagramList *node){
	//printf("PrintAList called\n");
	struct AnagramList *listToPrint = NULL;
	if(node == NULL){
	}
	if(node != NULL){
	listToPrint = node;
	}
	while(listToPrint){
		if (SListCount(listToPrint->Words) < 2){
			listToPrint = listToPrint->Next;
		}
		else /*(SListCount(listToPrint->Words) > 1)*/{
			fprintf(file,"%s:%d\n", listToPrint->Anagram, SListCount(listToPrint->Words));
			PrintSList(file, listToPrint->Words);
			listToPrint = listToPrint->Next;
		}
	}
}

