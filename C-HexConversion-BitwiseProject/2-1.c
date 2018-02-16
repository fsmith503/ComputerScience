#include <stdio.h>

int mask(int n){
	unsigned long long holder = 1; // assigning variable to 1
	unsigned long long temp = holder << n; // assigning new variable to holder shifted by input
	unsigned long long result = temp -1; // subtracting one to get desired result
	return result;
}

int main(int argc, char *argv[]){
	printf("0x%X\n", mask(1)); //0x1
	printf("0x%X\n", mask(2)); //0x3
	printf("0x%X\n", mask(3)); //0x7
	printf("0x%X\n", mask(5)); //0x1F
	printf("0x%X\n", mask(8)); //0XFF
	printf("0x%X\n", mask(16));//0XFFFF
	printf("0x%X\n", mask(32));//0XFFFFFFFF
}
