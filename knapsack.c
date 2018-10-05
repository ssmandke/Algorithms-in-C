#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define bool char

#define true 1
#define false 0


#define MAX(a,b) (a>b?a:b)

//knapsack problem
char knapsack(char w[], char v[], char wlen, char vlen, char maxWeight)
{
  char arr[wlen+1][maxWeight+1];
  char i = 0;
  char j = 0;
 
  for (i=0; i<vlen+1;i++)
  {
    for(j=0; j <maxWeight+1;j++)
    {
 
		   arr[i][j] = 0;
		   printf(" %d ", arr[i][j]);
	}
	printf("\r\n");
  }
  printf("\r\n");
  //initialize arr to 0..
  for (i=1; i<vlen+1;i++)
  {
    for(j=1; j <maxWeight+1;j++)
    {
       if(i==0 || j ==0)
	   {
		   arr[i][j] = 0;
	   }
     
	   if(j>=w[i-1])       
       {
          arr[i][j] = MAX(arr[i-1][j], arr[i-1][j- w[i-1]] + v[i-1]);
       }
	   else
	   {
		  arr[i][j] = arr[i-1][j];        
	   }
    }
  }

  for (i=0; i<vlen+1;i++)
  {
    for(j=0; j <maxWeight+1;j++)
    {
         printf(" %d ", arr[i][j]);
    }
	printf("\r\n");
  }	
  
  return arr[vlen][maxWeight];  
}

int main()
{
  char w[]=  {5,4,6,3};
  char v[]=  {10,40,30,50};
  
  printf("\r\nMax value in knapsack is %d\r\n",knapsack(w,v,sizeof(w),sizeof(v),10));
  return 0;
}