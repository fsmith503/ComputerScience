#include <stdio.h>

unsigned int replace(unsigned int x, unsigned int i, unsigned char b){
    unsigned int a = b << (i * 8); // assigning var and shifting by 8 * input specified b = 0xABOOOO
	unsigned int mask = 0xFF << (i * 8); // declaring mask var, mask = 0x00FF0000
	unsigned int temp = x & ~mask; // & bit operand with not mask,  mask = 0x00FF0000
	return a | temp; // bitwise or operand
}


int main(int argc, char *argv[]){
	unsigned int x = 0x12345678;
	unsigned int i = 2;
	unsigned char b = 0xAB;
	unsigned int test = replace(x,i,b);
	printf("0x%X\n", test);
	unsigned int d = 0x12345678;
	unsigned int e = 0;
	unsigned char f = 0xAB;
	unsigned int test1 = replace(d,e,f);
	printf("0x%X\n", test1);


	//replace(0x12345678, 2, 0xAB): 0x12AB5678
	//replace(0x12345678, 0, 0xAB): 0x123456AB
	//printf("0x%08X\n",replace(x, i,b));
	
}
