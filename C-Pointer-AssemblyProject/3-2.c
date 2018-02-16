#include <stdio.h>
#include <stdlib.h>
int decode(int x, int y, int z){
/*
Parameters x, y, and z are stored at memory locations 
with offsets 8, 12, and 16, respectively, relative to 
the address in register %ebp. The return value will 
be stored in register %eax.
Your task is to reverse engineer the C code; 
specifically to write a C implementation for the 
decode function that is functionally equivalent to 
the compiled IA32 code above.
When compiled, the resulting IA32 code is:
//movl 12(%ebp), %edx  asssign , copy stack pointer to edx
//subl 16(%ebp), %edx    make space on stack for local data
//movl %edx, %eax       assign , copy stack pointer to eax
//imull 8(%ebp), %edx   multiplication
sall $31, %eax  right shift
sarl $31, %eax  left shift
xorl %edx, %eax   XOR Left?
*/
int t1 = y;  // copying stack pointer to edx
t1 = t1 - z; // subtracting offset 16 from ofset 8
int t2 = t1; // copying stack pointer to eax
t2 = t2 * x; // multiplying offset 8 by edx
t1 = t1<<31; // left shft
t1 = t1>>31; // right shift
t1=t2^t1;    // XOR
return t1;
}

int main(int argc, char *argv[]){
	printf("%d\n",decode(1,2,4));
	printf("%d\n",decode(-4,-8,-12));
	return 0;
	}