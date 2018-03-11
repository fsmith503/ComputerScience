#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	int i;
	float sum0 = 0.0f;
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	/*combine to 4 elements at a time*/
	for (i = 0; i < length; i +=4) {
		sum0 += u[i] * v[i];
		sum1 += u[i+1] * v[i+1];
		sum2 += u[i+2] * v[i+2];
		sum3 += u[i+3] * v[i+3];
	}
	
	float sum = sum0 + sum1 + sum2 + sum3;
	/* Finishes any remaining elements*/
	sum0 = 0.0;
	for (; i < length-4; i++){
		sum0 = u[i] * v[i];
	}
	sum += sum0;
	*dest = sum;
}

int main(int argc, char *argv[]){
clock_t tic = clock();
float my_array1[] = {1.0,2.0,3.0,4.0};
float my_array2[] = {1.0,2.0,3.0,4.0};
float input1 = 0;
inner(my_array1, my_array2, 4, &input1);//declare float f pass in pointer using address operator)
printf("%f\n",input1);
clock_t toc = clock();
printf("Inner Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

clock_t tic1 = clock();
float my_array5[] = {1.0,2.0,3.0,4.0,};
float my_array6[] = {1.0,2.0,3.0,4.0,};
float input3 = 0;
inner2(my_array5, my_array6, 4, &input3);//declare float f pass in pointer using address operator)
printf("%f\n",input3);
clock_t toc1 = clock();
printf("Inner 2 Elapsed: %f seconds\n", (double)(toc1 - tic1) / CLOCKS_PER_SEC);
}












