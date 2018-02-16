#include <stdio.h>
#include <stdlib.h>
//Franklin Smith 4-2.c 
//pg 239
//swap
//for(int i = 0; i < N; ++i){
//rp = &a[i][j]
//cp &a[j][i]
//	for(int j = 0; j < i; ++j){	
	// swap on cp and rp
/*
4 lines of inner for loop
.L3:
movl (%edx), %esi  t = a[j][i] 
movl (%eax), %ecx	
addl $4, %eax  //adding 4 to row pointer
addl $40, %edx // adding 40 to column pointer
movl %esi, -4(%eax) int t = a[j][i]
movl %ecx, -40(%edx) a[i][j] = a[j][i]
cmpl %ebx, %eax // j < i
jne .L3
*/
#define N 4
typedef int array_t[N][N];
array_t my_array = 
{				
{1,2,3,4},
{5,6,7,8},
{9,10,11,12},
{13,14,15,16}
};	

void swap (int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
};

void transpose(array_t a) { 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			int *item1 = &a[i][j];
			int *item2 = &a[j][i];
			swap(item1, item2);
		};
	};
};

int main(int argc, char *argv[]){
	transpose(my_array);
	for(int k = 0; k < N; k++){
		for(int m = 0; m < N; m++){
			printf("{%d},", my_array[k][m]);
		}
		printf("\n");
	}
};






