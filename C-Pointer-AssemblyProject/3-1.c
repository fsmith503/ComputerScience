#include <stdio.h>
#include <stdlib.h>
#define size 256
//Citation of code Bubble Sort function 
//from https://www.geeksforgeeks.org/bubble-sort/

struct IntArray {
int length;
int *dataPtr;
};

struct IntArray* mallocIntArray(int length){
	struct IntArray* result = (struct IntArray*) malloc (sizeof(struct IntArray)); //allocating space for the array
	result->length = length;   //assigning length value to input value
	result->dataPtr = (int *) malloc (sizeof(int)*length); //allocating space for array length integer
	return result;
}

void freeIntArray(struct IntArray **arrayPtr){
	struct IntArray * array = *arrayPtr;
	free(array->dataPtr);  // freeing previous array memory
	array->dataPtr = NULL; // nulling array instances data pointer
	array->length = 0; // zeros out the length
	free(array); // freeing the array instance
	*arrayPtr = NULL; // nulling the array pointer
}

int readInt(){ // helper function to read int array
	char value[size];  //assinging a char
	char *valptr; // assigning pointer for value
	long result; // initializing long result variable which we will return
	scanf("%s", value); // scanner is taking int the string representation of our length
	result = strtol(value, &valptr, 10); //strtol function puts the string into base 10 long format
	return result; //returning result of the array length
}

void readIntArray(struct IntArray *array){
	//prompts and reads ints from the user to fill the array (i.e., read one 
	//int for each array index). Your program must not crash if the user 
	//enters values that cannot be parsed as ints (we’ll cover this in labs).
	//c check value for positive int, be sure it can be pasrsed as int or ask again
	//str to l
	//string to long
	for(int i= 0; i < array->length; i++){
		printf("Enter Input:\n"); // asking to enter an input from user to fill the array
		long temp = readInt(); // assigning temp to the integer given from readInt function
		array->dataPtr[i] = temp; // assigning array position i to given integer from previous line
	}
}

void swap(int *xp, int *yp){ // function swaps values pointed by xp and yp
	int t0 = *xp;
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
}

void sortIntArray(struct IntArray *array){
/*sorts the input array using Bubble Sort
(Google it) by repeatedly calling your swap function as appropriate.
*/
	int i, j;
	int n = array->length; //setting loop counter to the length of the array
   for(i = 0; i < n-1; i++){ //first for loop     
 
       // Last i elements are already in place   
       for(j = i+1; j < n; j++){ //second for loop
           if(array->dataPtr[i] > array->dataPtr[j]){ //if element in A[i] greater than A[j]
            	swap(&(array->dataPtr[j]), &(array->dataPtr[i])); // swap the elements data pointers
           }
        }    
    }        
} 

void printIntArray(struct IntArray *array){
/* prints the array (e.g., “[ 1, 3, 5, 7 ]”). */
	for(int k = 0; k < array->length; k++){ // loops over each element in the array
		printf("%d", array->dataPtr[k]); // prints element of A[k] or index position k
		
		printf("%s", " , "); // prints some space in between for clairty
	}

}

int main(int argc, char *argv[]){
	printf("Enter Length:\n");
	long length = readInt();
	if(length <= 0){
		while(length <= 0){
			printf("Enter Length:\n");
			length = readInt();
		}
	}
	struct IntArray* input1 = mallocIntArray(length);
	readIntArray(input1);
	//printf("\n");
	//printIntArray(input1);
	//printf("\n");
	sortIntArray(input1);
	//printf("\n");
	printIntArray(input1);
	//printf("\n");
	freeIntArray(&input1);
	//printf("\n");
	//printf("%p\n", input1);
	//printf("%p\n",input1);
	//printf("%p\n", input1->dataPtr);
	//printf("%d\n", input1->length);
	//freeIntArray(&input1);	
	//printf("%p\n", input1);
	//readIntArray(input1);
}