#include <stdio.h>

unsigned int even(unsigned int x){
	 unsigned int result = !!(0x55555555 & x); // declaring int var , not operands
	 return result; // returning int result
	 
}

int main(int argc, char *argv[]){
	printf("%d\n", even(0x0));  
	printf("%d\n", even(0x1));
	printf("%d\n", even(0x2));
	printf("%d\n", even(0x3));
	printf("%d\n", even(0xFFFFFFFF));
	printf("%d\n", even(0xAAAAAAAA));
}