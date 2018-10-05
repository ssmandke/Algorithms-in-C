#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// maxPathSum?

#define MAX(a,b) (a>b?a:b)

char treeArray[] = {10, 2, 10, 20, 1, 0, -25, 0, 0,3, 4};//{-10,9,20,0,0,15,7};
char globalMax = -10;

int maxPathSum(char treeArr[], int idx, char sizeOfTreeArray)
{
   int left  = (2*idx)+1;
   int right  = (2*idx)+2;

   if(left > sizeOfTreeArray)
   {
      return 0;
   }

   if(right > sizeOfTreeArray)
   {
      return 0;
   }
   printf("\r\nidx = %d parent = %d left = %d right = %d\r\n", idx, treeArr[idx], treeArr[left], treeArr[right]);
   int leftSum  = maxPathSum(treeArr,  left, sizeOfTreeArray);
   int rightSum = maxPathSum(treeArr, right,sizeOfTreeArray);

   int temp1 = leftSum + rightSum + treeArr[idx];
   int temp2 = leftSum + treeArr[idx];
   int temp3 = rightSum + treeArr[idx];
   int temp4 = treeArr[idx];

   int pathSumMax1 = MAX(temp2, temp3);
   int pathSumMax2 = MAX(temp4 ,pathSumMax1);
   
   globalMax = MAX(pathSumMax2, temp1);
       
   return pathSumMax2;
}

int main()
{
  char sizeOfTreeArray = sizeof(treeArray)/sizeof(char);
  printf("maxPathSum = %d, globalMax = %d\r\n",maxPathSum(treeArray,0,sizeOfTreeArray), globalMax);
  printf("globalMax = %d\r\n",globalMax);
  printf("globalMax = %d\r\n",globalMax);
  printf("globalMax = %d\r\n",globalMax);
  return 0;
}
