#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y){
	 unsigned int xval = x >> 24; // assigning new var and shifting 
	 xval = xval << 24; // reassigning the var and shifting
	 unsigned int yval = y << 8; // assigning new var and shifting
	 yval = yval >> 8; // reassigning the var and shifting
	 unsigned int result = xval | yval; // bitwise or operator
	 return result;
}

int main(int argc, char *argv[]){
	unsigned int k = 0x12345678;
	unsigned int j = 0xABCDEF00;
	printf("0x%08X\n",combine(k, j));
	printf("0x%08X\n",combine(0xABCDEF00, 0x12345678));
}