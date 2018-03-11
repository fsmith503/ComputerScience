#include <stdio.h>
#include <stdlib.h>
#define N 4
typedef int array_t[N][N];

int dim() {
	return N;
}

void f(array_t a, int x, int y){
	int temp = dim();
	int xyresult = x * y;
	for (int i = 0; i < temp; ++i) {
		int xyiresult = xyresult * i;
		for (int j = 0; j < temp; ++j) {
			//a[i][j] = i * x * y + j;
			a[i][j] = xyiresult + j;
		}
	}
}
/*
Rewrite the above procedure f to minimize unnecessary function calls and multilications.
*/

int main(int argc, char *argv[]){
array_t my_array = 
		{				
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
		};
	for(int k = 0; k < N; k++){
		for(int m = 0; m < N; m++){
			printf("{%d},", my_array[k][m]);
		}
		printf("\n");
	}	
	printf("\n");
	f(my_array, N, N);
	
	for(int k = 0; k < N; k++){
		for(int m = 0; m < N; m++){
			printf("{%d},", my_array[k][m]);
		}
		printf("\n");
	}
}