#include <stdio.h>
///#include <malloc.h>
#include <stdlib.h>

typedef struct _Matrix{
 int columns;
 int rows;
 double *array;
} Matrix;


Matrix *malloc_Matrix(int cols, int rows)
{
	Matrix *returnValue = (Matrix*)malloc(sizeof(Matrix*));
	returnValue->columns = cols;
	returnValue->rows = rows;
	returnValue->array = (double*)malloc(sizeof(double)*cols*rows);
	for(int i =0; i < cols*rows; i++)
	{
		returnValue->array[i] =0.0;
	}
	return returnValue;
}

void free_Matrix(Matrix *ptr)
{
	free(ptr->array);
	free(ptr);
}

void print_Matrix(FILE *file, Matrix *matrix)
{
	for(int r =0; r < matrix->rows; r++)
	{
		int rcount = r * matrix->rows;
		for(int c = 0; c < matrix->columns; c++)
		{
			int rindex = rcount + c;
			fprintf(file,"%f\t",matrix->array[rindex]);
			fflush(file);
		}
		fprintf(file,"\r\n");
		fflush(file);
	}
}

// Optional: Implement matrix randomize:

void matrix_randomize(Matrix *m0)
{

}

// Implement Matrix multiply here:

Matrix *matrix_multiply(Matrix *m0, Matrix *m1)
{

}

typedef struct _Odometer
{
	int Size;
	int *Indexes;
} Odometer;

typedef struct _HyperEdge
{
	int Size;
	void **NodePointers;

} HyperEdge;

typedef struct _HyperGraph
{
	int Size;
	void **NodeVector;
} HyperGraph;

Odometer *malloc_Odometer(int size)
{
	Odometer *returnValue = NULL;
	returnValue = malloc(sizeof(Odometer));
	returnValue -> Size = size;
	returnValue -> Indexes = malloc(sizeof(int) * size);
	for(int i=0; i < size; i++)
	{
		returnValue->Indexes[i] = 0;
	}
	return returnValue;
}

void free_Odometer(Odometer *ptr)
{
	if(NULL != ptr)
	{
		free(ptr);
	}
}

HyperEdge *malloc_HyperEdge(int size)
{
	HyperEdge *returnValue = NULL;
	returnValue = malloc(sizeof(HyperEdge));
	returnValue->Size = size;
	returnValue->NodePointers = malloc(sizeof(void *)*size);
	for(int i=0; i < size;i++)
	{
		returnValue->NodePointers[i] = NULL;
	}	
	return returnValue;
}

void free_HyperEdge(HyperEdge *ptr)
{
	if(NULL != ptr)
	{
		free(ptr);
	}
}

HyperGraph *malloc_HyperGraph(int size)
{
	HyperGraph *returnValue = NULL;
	
	returnValue = malloc(sizeof(HyperGraph));
	returnValue ->Size = size;
	returnValue->NodeVector = malloc(sizeof(void*)*size);
	for(int i =0; i < size ; i++)
	{
		returnValue->NodeVector[i] = NULL;
	}

	return returnValue;
}

void free_HyperGraph(HyperGraph *ptr)
{
	if(NULL != ptr)
	{
		free(ptr);
	}
}

void print_test()
{
	char x;
	int y;
	char z[] = "Hello World!";
	
	printf("x: %c, %d, %X, %s\n", (char)x,(int)x, (char*)x);
	printf("y: %c, %d, %X, %s\n", (char)y,(int)y, (char*)y);
	printf("z: %c, %d, %X, %s\n", (char)z,(int)z, (char*)z);
	
	char *xx = &x;
	int *yy = &y;
	char **zz = &z;


	printf("xx: %c, %d, %X, %s\n", (char)xx,(int)xx, (char*)xx);
	printf("yy: %c, %d, %X, %s\n", (char)yy,(int)yy, (char*)yy);
	printf("zz: %c, %d, %X, %s\n", (char)zz,(int)zz, (char*)zz);

} 

void StackExpander_GDBTesting()
{
	print_test();
}

void Matrix_Test()
{
	int x = 10;
	int y = 10;
	printf("Creating a matrix of size: %d , %d\n",x,y);
	Matrix *m0 = malloc_Matrix(x,y);
	Matrix *m1 = malloc_Matrix(x,y);

	matrix_randomize(m0);
	matrix_randomize(m1);
	
    Matrix *m2;
    
MAtri:matrix_multiply(m0,m1);

	print_Matrix(stdout,m0);
	print_Matrix(stdout,m1);
	print_Matrix(stdout,m2);
}

void StackExpander_ValGrindTesting()
{
	Odometer *odometer = malloc_Odometer(10);
	HyperEdge *hyper_edge = malloc_HyperEdge(10);
	HyperGraph *hyper_graph = malloc_HyperGraph(10);


}

int main(int argc, char **argv)
{
	StackExpander_GDBTesting();
	
	Matrix_Test();
	
	StackExpander_ValGrindTesting();

	return 0;
}
