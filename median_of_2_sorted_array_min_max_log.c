#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#define bool char
#define TRUE 1
#define FALSE 0

int a[] = {1,3,5,6,7,8,9};
int b[] = {1,4,6,8,12,14,15};

int c[] = {4 , 8 , 9, 12, 13, 15};
int d[] = {3 , 7 , 8, 10, 11};

double medianOfTwoSortedArrays(int A[], int M, int B[], int N);

double findMedianOfTwoSortedArrays(int ar1[], int ar1_size, int ar2[], int ar2_size)
{
	if(ar1_size > ar2_size)
	{
		return medianOfTwoSortedArrays(ar1, ar1_size, ar2, ar2_size);
	}
	
	return medianOfTwoSortedArrays(ar2, ar2_size, ar1, ar1_size);
	
}

double medianOfTwoSortedArrays(int A[], int M, int B[], int N)
{
	int imin = 0;
	int imax = 0;
	int half_len = 0;
	int i = 0;
	int j = 0;
	int isOdd = (M+N) & 0x01;
	int max_of_left = 0;
	int min_of_right = 0;
	
    imax = M; // we ensure M > N when we call this function..

	half_len = (M + N + 1)/2 - i;
	
	// start with imin = 0... imax = M and set half_len//
	while(imin <= imax)
	{
		i = (imin + imax)/2; //starts from M/2
		j = half_len - i;
		
		if((i < M) && (B[j-1] > A[i]))
		{
			imin = i + 1; // this means left index is less...i is too small and it needs to be increased
		}
		else if((i > 0) && (A[i-1] >B[j]))
		{
			imax = i - 1; //i is too big ..decrease it..
		}
		else
		{
	        // i is in the right spot but we need more corner case checks..
			
            if(i==0)
			{
				max_of_left = B[j-1];
			}
			else if(j==0)
			{
				max_of_left = A[i-1];
			}
			else
			{
				max_of_left = MAX(A[i-1], B[j-1]);
			}

			if(isOdd)//((M+N)%2 == 1)
			{
				printf("%d %d\n", max_of_left, min_of_right);
				return max_of_left;
			}
				
			
			if(i==M)
			{
				min_of_right = B[j];
			}
			else if(j==N)
			{
				min_of_right = A[i];
			}
			else
			{
				min_of_right = MIN(A[i], B[j]);
			}

			printf("%d %d\n", max_of_left, min_of_right);
			
            return (max_of_left + min_of_right) / 2.0;
		}
	}
	return 0;
}

int main()
{
	printf("Median of 2 sorted arrays is %f\r\n\n",findMedianOfTwoSortedArrays(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int)));
    printf("Median of 2 sorted arrays is %f\r\n\n",findMedianOfTwoSortedArrays(c, sizeof(c)/sizeof(int), c, sizeof(d)/sizeof(int)));

	return 0;
}