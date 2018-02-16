#include <stdio.h>

unsigned int extract(unsigned int x, int i){
	int k = 3 - i; //inverting the value to get achieved output
	unsigned int j = k << 3; // shifting by the magic number to achieve bit position
	int z = x; // assigning variable
	z = z << j; // shifting by magic number to achieve bit position
	z = z >> 24; // Shifting back to desired output position
	return z; // returning output for desired output value
}

int main(int argc, char *argv[]){
	printf("0x%X\n", extract(0xABCDEF00, 2)); //0xFFFFFFCD
	printf("0x%08X\n", extract(0x12345678, 0)); // 0x00000078
}
