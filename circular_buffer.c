#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)


typedef struct buffer_t
{
  int head;
  int tail;
  int array[N];
}buffer;

buffer mybuf;

void printArray()
{
  int i = 0;
  printf("\r\nprint\r\n");
  while(i<N)
  {
	  printf("%d ",mybuf.array[i]);
	  i++;
  }
  printf("\r\n");
}

int getNumEmptySlots()
{
  if(mybuf.head >mybuf.tail)
  {  
    return (mybuf.head - mybuf.tail);
  }
  
  return(N - (mybuf.tail-mybuf.head));
}

int insert(int data)
{
  if(getNumEmptySlots() == 0)
  {
    return -1;
  }
  printf("head = %d ", mybuf.head);
  mybuf.array[mybuf.head] = data;
  mybuf.head++;
  mybuf.head%=N;

  return 0;
}

int removeData()
{
  if(getNumEmptySlots() == N)
  {
    return -1;
  }
 
  int data  = mybuf.array[mybuf.tail];
  printf("tail = %d ", mybuf.tail);
  mybuf.tail++;
  mybuf.tail = mybuf.tail%N;
  return data;
}

int main()
{
   int v = 12;
   int count = 0;

   while(v)
   {
     count++;
     v &=v-1;
   }
   printf("%d is the no of ones\r\n",count);
   
   printf("putting 11\r\n"); insert(11);
   printf("putting 23\r\n"); insert(23);
   printf("putting 15\r\n"); insert(15);
   printf("putting 17\r\n"); insert(17);
   printf("putting 18\r\n"); insert(18);
   printf("putting 19\r\n"); insert(19);
   printArray();
   int data = removeData();
   printArray();
   printf(" removed %d\r\n",data);
   int data1 = removeData();
   printArray();
   printf(" removed %d\r\n",data1);
   return 0;
}