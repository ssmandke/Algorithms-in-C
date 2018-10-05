#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

char arr[4][4] = {{ 1, 2 ,3 ,4}, { 5, 6 ,7 ,8}, { 9, 10, 11, 12}, {13, 14, 15, 16}};

void swap(char *a, char *b)
{
   char temp = *a;
   *a = *b;
   *b = temp;
}
void printMatrix()
{
    int j = 0;
	int i = 0;
	
	for(i= 0 ; i < N; i++)
	{
		for(j= 0 ; j< N; j++)
		{
			printf(" %d ", arr[i][j]);
		}
		printf("\r\n");
	}
	
	printf("\r\n");printf("\r\n");

}
void rotateMatrixClockWiseInPlace()
{
	int layer = 0;
	int j = 0;
	int i = 0;
	
	printMatrix();
	
	for(layer = 0; layer < N/2; layer++)
	{
		i = layer;
		
		int lastLayer = (N - layer - 1);

		for(j = layer; j < lastLayer; j++)
		{
			// Store first top
			int temp = arr[i][j];
			
			// left to top
			arr[i][j] = arr[N-j-1][i];
			
			// bottom to left
			arr[N-j-1][i] = arr[N-i-1][N-j-1];
			
			// right to bottom
			arr[N-i-1][N-j-1] = arr[j][N-i-1];
			
			// top to right
			arr[j][N-i-1] = temp;
		}
	}
	
	printMatrix();	
}

int main()
{
	rotateMatrixClockWiseInPlace();
	return 0;
}