#include <stdio.h>
#include <stdlib.h>
//Franklin Smith 4-1.c
/*
loop:
pushl %ebp   			Save old %ebp
movl %esp, %ebp			Set %ebp as frame pointer
pushl %esi				Save old %esi
pushl %ebx				Save old %ebx
movl 8(%ebp), %esi		Set arg1 to %esi //
movl 12(%ebp), %ecx		Set arg2 to %ecx //
movl $2, %edx			Puts value of 2 into mask %edx //
movl $-1, %eax			Puts value of -1 into result %eax //
.L2:
movl %esi, %ebx			Sets %ebx as frame pointer //
andl %edx, %ebx			Bitwise and of the two operands  X and Mask stores result in %ebx 
xorl %ebx, %eax			Bitwise XOR of the two operands Result and ebx stores result in %eax //
sall %cl, %edx			Shifts %edx left by %cl bits, shifts mask left by y bits
cmpl $1, %edx			Compares unsigned, mask > 1Value of one and %edx, stores result in %edx?//
jg .L2
popl %ebx				Popping the stack for pointer %ebx
popl %esi				Popping the stack for pointer %esi
popl %ebp				Popping the stack for pointer %ebp
ret 					Return? Pops last value from stack
*/

int loop(int x, int y) { 
	int result = -1;
	for (int mask = 2; mask > 1; mask <<= y){
	result ^= (x & mask);
	}
	return result;
}
int main(int argc, char *argv[]){
	printf("%d\n", loop(1,5));// -1
	printf("%d\n", loop(2,4));// -3
	printf("%d\n", loop(3,3));// -3
	printf("%d\n", loop(4,2));// -1
	printf("%d\n", loop(5,1));// -5
	}