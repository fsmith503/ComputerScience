#include <stdio.h>


void printBytes(unsigned char *start, int len) {
 		for (int i = 0; i < len; ++i) {
 			printf(" %.2X", start[i]); // prints at least 2 hex digits in the result
		 }
 		printf("\n");
}

void printInt(int x) { // takes specfified data type as parameter
 	printBytes((unsigned char *) &x, sizeof(int)); //sizeof computes size of operand int
}

void printFloat(float x) { // takes specified data type as parameter
 	printBytes((unsigned char *) &x, sizeof(float)); //size of computes size of operand float
}

void printShort(short x){ // takes specified data type as parameter
	printBytes((unsigned char *) &x, sizeof(short)); //size of computes size of operand short 
}

void printLong(long x){ // takes specified data type as parameter
	printBytes((unsigned char *) &x, sizeof(long)); //size of computes size of operand long
}

void printDouble(double x){ // takes specified data type as parameter
	printBytes((unsigned char *) &x, sizeof(double)); //size of computes size of operand double
}

int main(int argc, char *argv[]){
/*
Something i noticed that was unexpected regarding the output
of my test functions was that the formatting of the output was
very different and I dont understand it still.
*/

	int x = 4;
	printInt(x); 
	printFloat(x);
	printShort(x);
	printLong(x);
	printDouble(x);
}
