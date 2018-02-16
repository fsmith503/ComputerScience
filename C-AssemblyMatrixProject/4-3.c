#include <stdio.h>
#include <stdlib.h>
//Franklin Smith 4-3.c
//Citation Source got help from claire phillips
/*
int sum(int from, int to) {
int result = 0;
do {
	result += from; // add
	++from; // add1 
	} 
	while (from <= to); compare
	return result; 
}
Implement the do-while loop above in IA32. Use the following as a framework:
*/

int sum(int from, int to) {
int result = 0;
// Ensure that argument *from* is in %ecx,
// argument *to* is in %edx, *result* is in %eax - do not modify.
__asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
__asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));
__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));
// Your IA32 code goes below - comment each instruction...
__asm__ (
	".loop:"
		"addl %ecx, %eax;" //result += from
		"addl $1, %ecx;" //++from;
		"cmpl %edx, %ecx;" //from <= to
		"jle .loop;" //jump the loop
	);

// Ensure that *result* is in %eax for return - do not modify.
__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
return result;
}

int main(int argc, char *argv[]){
	printf("%d\n", sum(1 ,6)); //21  sum(1, 6): 21
	printf("%d\n", sum(3 ,5)); //12  sum(3, 5): 12
	}