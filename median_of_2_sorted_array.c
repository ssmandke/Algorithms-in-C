#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#define bool char
#define TRUE 1
#define FALSE 0

char ar1[] = {-5, 3, 6, 12, 15};
char ar2[] = {-12, -10, -6, -3, 4, 10};

// Find median by using binary search gives log(N)
int binarySearch(char *ptr, char left, char right, char key)
{	
	if(left==right)
	{
		return left;
	}
	else
	{
		int mid = (left + right)/2;
		
		if(key > ptr[mid])
		{
			return binarySearch(ptr, mid+1, right, key);
		}
		else if (key < ptr[mid])
		{
			return binarySearch(ptr, left, mid-1,  key);
		}	 
        else
            return left;			
	}
	
	return -1; // return some value..
}

int main()
{
	int sizeSet1 = sizeof(ar1);
	int sizeSet2 = sizeof(ar2);
	int totalElem = sizeSet1 + sizeSet2;
	int medianIdx = -1;
	int median1 = -1;
	int median2 = -1;
    int i , j , k;
    i = j = k = 0;
	medianIdx = totalElem/2; //if total is odd...will check for even later..
	
	printf("Total no of elements = %d\r\n", totalElem);
	
	while(k < (medianIdx + 1))
	{
                if(ar1[i] <= ar2[j])
                {
				  printf(" %d ", ar1[i]);               
  
                  if(k+1 == medianIdx)
                  {
                     median1 = ar1[i];
					 printf(" median11 = %d\r\n",median1);
                  }
                  else if(k == medianIdx)
                  {
                     median2 = ar1[i];
					 printf(" median12 = %d\r\n",median2);
                  }                
				  i++;
                }
                else if(ar1[i] > ar2[j])
                {
				  printf(" %d \r\n", ar2[j]); 

                  if(k+1 == medianIdx)
                  {
                    median1 = ar2[j];
					printf(" median21 = %d\r\n",median1);
                  }
                  else if(k == medianIdx)
                  {
                     median2 = ar2[j];
					 printf(" median22 = %d\r\n",median2);
                  }
				  
				  j++;
                }

		k++;
	}	
	
	if((totalElem & 0x01) == 0 )
    {
		printf(" Median = %d\r\n", (median1 + median2)/2);
	}
    else
    {
		printf(" Median = %d\r\n", median2);
	}

	return 0;
}