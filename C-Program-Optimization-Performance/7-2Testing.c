#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
c. (20) Implement a procedure inner2 that is functionally equivalent to 
inner but uses four-way loop unrolling with four parallel accumulators. 
Also implement a main() function to test your procedure.
Name your source file 7-2.c.
*/


void outer(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}


void inner(float *u, float *v, int length, float *dest) {
	//had to change return type to float to get value back
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
	//printf("%f\n",sum);
	/* Finish any remaining elements*/
	sum0 = 0.0;
	for (; i < length-4; i++){
		sum0 = u[i] * v[i];
	}
	sum += sum0;
	*dest = sum;
}

int main(int argc, char *argv[]){
/*
4
10
50
800
3200
6400
12800
25600
70000
100000
160000
*/
	printf("\n");

//4 array	
	float array4_1[4] = {};
	float array4_2[4] = {};
	for(int i = 0; i < 4; i++){
		array4_1[i] = i + .1; 
		array4_2[i] = i + .1;
	}
//outer4
	clock_t tic4outer = clock();
	float input4outer = 0;
	outer(array4_1, array4_2, 4, &input4outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input4outer);
	clock_t toc4outer = clock();
	printf("Outer Function 4 Elapsed: %f seconds\n", (double)(toc4outer - tic4outer) / CLOCKS_PER_SEC);
//inner4
	clock_t tic4inner = clock();
	float input4inner = 0;
	inner(array4_1, array4_2, 4, &input4inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input4inner);
	clock_t toc4inner = clock();
	printf("Inner Function 4 Elapsed: %f seconds\n", (double)(toc4inner - tic4inner) / CLOCKS_PER_SEC);
	printf("\n");
//4 array end

	


//10 array	
	float array10_1[10] = {};
	float array10_2[10] = {};
	for(int i = 0; i < 10; i++){
		array10_1[i] = i + .1; 
		array10_2[i] = i + .1;
	}
//outer10
	clock_t tic10outer = clock();
	float input10outer = 0;
	outer(array10_1, array10_2, 10, &input10outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input10outer);
	clock_t toc10outer = clock();
	printf("Outer Function 10 Elapsed: %f seconds\n", (double)(toc10outer - tic10outer) / CLOCKS_PER_SEC);
//inner10
	clock_t tic10inner = clock();
	float input10inner = 0;
	inner(array10_1, array10_2, 10, &input10inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input10inner);
	clock_t toc10inner = clock();
	printf("Inner Function 10 Elapsed: %f seconds\n", (double)(toc10inner - tic10inner) / CLOCKS_PER_SEC);
	printf("\n");
//10 array end

	 

//50 array	
	float array50_1[50] = {};
	float array50_2[50] = {};
	for(int i = 0; i < 50; i++){
		array50_1[i] = i + .1; 
		array50_2[i] = i + .1;
	}
//outer50
	clock_t tic50outer = clock();
	float input50outer = 0;
	outer(array50_1, array50_2, 50, &input50outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input50outer);
	clock_t toc50outer = clock();
	printf("Outer Function 50 Elapsed: %f seconds\n", (double)(toc50outer - tic50outer) / CLOCKS_PER_SEC);
//inner50
	clock_t tic50inner = clock();
	float input50inner = 0;
	inner(array50_1, array50_2, 50, &input50inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input50inner);
	clock_t toc50inner = clock();
	printf("Inner Function 50 Elapsed: %f seconds\n", (double)(toc50inner - tic50inner) / CLOCKS_PER_SEC);
	printf("\n");
//50 array end


//800 array	
	float array800_1[800] = {};
	float array800_2[800] = {};
	for(int i = 0; i < 800; i++){
		array800_1[i] = i + .1; 
		array800_2[i] = i + .1;
	}
//outer800
	clock_t tic800outer = clock();
	float input800outer = 0;
	outer(array800_1, array800_2, 800, &input800outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input800outer);
	clock_t toc800outer = clock();
	printf("Outer Function 800 Elapsed: %f seconds\n", (double)(toc800outer - tic800outer) / CLOCKS_PER_SEC);
//inner800
	clock_t tic800inner = clock();
	float input800inner = 0;
	inner(array800_1, array800_2, 800, &input800inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input800inner);
	clock_t toc800inner = clock();
	printf("Inner Function 800 Elapsed: %f seconds\n", (double)(toc800inner - tic800inner) / CLOCKS_PER_SEC);
	printf("\n");
//800 array end


//1000 array	
	float array1[1000] = {};
	float array2[1000] = {};
	for(int i = 0; i < 1000; i++){
		array1[i] = i + .1; 
		array2[i] = i + .1;
	}
//outer1000
	clock_t tic = clock();
	float input1 = 0;
	outer(array1, array2, 1000, &input1);//declare float f pass in pointer using address operator)
	printf("%f\n",input1);
	clock_t toc = clock();
	printf("Outer Function 1000 Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//inner1000
	clock_t tic1 = clock();
	float input3 = 0;
	inner(array1, array2, 1000, &input3);//declare float f pass in pointer using address operator)
	printf("%f\n",input3);
	clock_t toc1 = clock();
	printf("Inner Function 1000 Elapsed: %f seconds\n", (double)(toc1 - tic1) / CLOCKS_PER_SEC);
	printf("\n");
//1000 array end

//3200 array
	//3200 array	
	float array3200_1[3200] = {};
	float array3200_2[3200] = {};
	for(int i = 0; i < 3200; i++){
		array3200_1[i] = i + .1; 
		array3200_2[i] = i + .1;
	}
//outer3200
	clock_t tic3200outer = clock();
	float input3200outer = 0;
	outer(array3200_1, array3200_2, 3200, &input3200outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input3200outer);
	clock_t toc3200outer = clock();
	printf("Outer Function 3200 Elapsed: %f seconds\n", (double)(toc3200outer - tic3200outer) / CLOCKS_PER_SEC);
//inner3200
	clock_t tic3200inner = clock();
	float input3200inner = 0;
	inner(array3200_1, array3200_2, 3200, &input3200inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input3200inner);
	clock_t toc3200inner = clock();
	printf("Inner Function 3200 Elapsed: %f seconds\n", (double)(toc3200inner - tic3200inner) / CLOCKS_PER_SEC);
	printf("\n");
//3200array end	

	//6400 array	
	float array6400_1[6400] = {};
	float array6400_2[6400] = {};
	for(int i = 0; i < 6400; i++){
		array6400_1[i] = i + .1; 
		array6400_2[i] = i + .1;
	}
//outer3200
	clock_t tic6400outer = clock();
	float input6400outer = 0;
	outer(array6400_1, array6400_2, 6400, &input6400outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input6400outer);
	clock_t toc6400outer = clock();
	printf("Outer Function 6400 Elapsed: %f seconds\n", (double)(toc6400outer - tic6400outer) / CLOCKS_PER_SEC);
//inner6400
	clock_t tic6400inner = clock();
	float input6400inner = 0;
	inner(array6400_1, array6400_2, 6400, &input6400inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input6400inner);
	clock_t toc6400inner = clock();
	printf("Inner Function 6400 Elapsed: %f seconds\n", (double)(toc6400inner - tic6400inner) / CLOCKS_PER_SEC);
	printf("\n");
//6400array end	

	//12800 array	
	float array12800_1[12800] = {};
	float array12800_2[12800] = {};
	for(int i = 0; i < 12800; i++){
		array12800_1[i] = i + .1; 
		array12800_2[i] = i + .1;
	}
//outer12800
	clock_t tic12800outer = clock();
	float input12800outer = 0;
	outer(array12800_1, array12800_2, 12800, &input12800outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input12800outer);
	clock_t toc12800outer = clock();
	printf("Outer Function 12800 Elapsed: %f seconds\n", (double)(toc12800outer - tic12800outer) / CLOCKS_PER_SEC);
//inner12800
	clock_t tic12800inner = clock();
	float input12800inner = 0;
	inner(array12800_1, array12800_2, 12800, &input12800inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input12800inner);
	clock_t toc12800inner = clock();
	printf("Inner Function 12800 Elapsed: %f seconds\n", (double)(toc12800inner - tic12800inner) / CLOCKS_PER_SEC);
	printf("\n");
//12800array end

	//25600 array	
	float array25600_1[25600] = {};
	float array25600_2[25600] = {};
	for(int i = 0; i < 25600; i++){
		array25600_1[i] = i + .1; 
		array25600_2[i] = i + .1;
	}
//outer25600
	clock_t tic25600outer = clock();
	float input25600outer = 0;
	outer(array25600_1, array25600_2, 25600, &input25600outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input25600outer);
	clock_t toc25600outer = clock();
	printf("Outer Function 25600 Elapsed: %f seconds\n", (double)(toc25600outer - tic25600outer) / CLOCKS_PER_SEC);
//inner25600
	clock_t tic25600inner = clock();
	float input25600inner = 0;
	inner(array25600_1, array25600_2, 25600, &input25600inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input25600inner);
	clock_t toc25600inner = clock();
	printf("Inner Function 25600 Elapsed: %f seconds\n", (double)(toc25600inner - tic25600inner) / CLOCKS_PER_SEC);
	printf("\n");
//25600array end	

	//70000 array	
	float array70000_1[70000] = {};
	float array70000_2[70000] = {};
	for(int i = 0; i < 70000; i++){
		array70000_1[i] = i + .1; 
		array70000_2[i] = i + .1;
	}
//outer70000
	clock_t tic70000outer = clock();
	float input70000outer = 0;
	outer(array70000_1, array70000_2, 70000, &input70000outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input70000outer);
	clock_t toc70000outer = clock();
	printf("Outer Function 70000 Elapsed: %f seconds\n", (double)(toc70000outer - tic70000outer) / CLOCKS_PER_SEC);
//inner70000
	clock_t tic70000inner = clock();
	float input70000inner = 0;
	inner(array70000_1, array70000_2, 70000, &input70000inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input70000inner);
	clock_t toc70000inner = clock();
	printf("Inner Function 70000 Elapsed: %f seconds\n", (double)(toc70000inner - tic70000inner) / CLOCKS_PER_SEC);
	printf("\n");
//70000array end	

	//100000 array	
	float array100000_1[100000] = {};
	float array100000_2[100000] = {};
	for(int i = 0; i < 100000; i++){
		array100000_1[i] = i + .1; 
		array100000_2[i] = i + .1;
	}
//outer100000
	clock_t tic100000outer = clock();
	float input100000outer = 0;
	outer(array100000_1, array100000_2, 100000, &input100000outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input100000outer);
	clock_t toc100000outer = clock();
	printf("Outer Function 100000 Elapsed: %f seconds\n", (double)(toc100000outer - tic100000outer) / CLOCKS_PER_SEC);
//inner100000
	clock_t tic100000inner = clock();
	float input100000inner = 0;
	inner(array100000_1, array100000_2, 100000, &input100000inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input100000inner);
	clock_t toc100000inner = clock();
	printf("Inner Function 100000 Elapsed: %f seconds\n", (double)(toc100000inner - tic100000inner) / CLOCKS_PER_SEC);
	printf("\n");
//100000array end	

	//160000 array	
	float array160000_1[160000] = {};
	float array160000_2[160000] = {};
	for(int i = 0; i < 160000; i++){
		array160000_1[i] = i + .1; 
		array160000_2[i] = i + .1;
	}
//outer160000
	clock_t tic160000outer = clock();
	float input160000outer = 0;
	outer(array160000_1, array160000_2, 160000, &input160000outer);//declare float f pass in pointer using address operator)
	printf("%f\n",input160000outer);
	clock_t toc160000outer = clock();
	printf("Outer Function 160000 Elapsed: %f seconds\n", (double)(toc160000outer - tic160000outer) / CLOCKS_PER_SEC);
//inner160000
	clock_t tic160000inner = clock();
	float input160000inner = 0;
	inner(array160000_1, array160000_2, 160000, &input160000inner);//declare float f pass in pointer using address operator)
	printf("%f\n",input160000inner);
	clock_t toc160000inner = clock();
	printf("Inner Function 160000 Elapsed: %f seconds\n", (double)(toc160000inner - tic160000inner) / CLOCKS_PER_SEC);
	printf("\n");
//160000array end




	printf("\n");
}











	
