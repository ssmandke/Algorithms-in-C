
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

//char histogram[] = {6, 2, 5, 4, 5, 1, 6};
char histogram[] = {2,3,4,2};

typedef struct node_t
{
  struct node_t *next;
  char data;
}node;

node *head = NULL;

node *newNode(char data)
{
  node *ptr = malloc(sizeof(node));
  ptr->data = data;
  ptr->next = NULL;
  return ptr;
}

void push(char data)
{
  node *tmp = newNode(data);
  printf("push %d\r\n",data);
  
  if(head)
  {
    tmp->next = head;
    head = tmp;
  }   
  else
  {
    head = tmp;
  }
}

char pop()
{
  char x;
  
  if(head)
  {
   node *ptr = head;
   x = head->data; 
   head = head->next;
   free(ptr);
  }
  else
  {  
    return -1;
  }
  if(head == NULL)
  {
	  printf("popped head!!\r\n");
  }
  printf("pop  %d which is value %d\r\n", x, histogram[x]);
  return x; 
}

int maxAreaUnderHistogram(char arr[], char len)
{
  char maxArea = -1;
  char idx = 0;
  char currMax = -1;
  char currArea = -1;
  
  while(idx < len)
  {
    if(( !head) || (arr[head->data] <= arr[idx])) //if stack is empty or top of stack has data <= current value of bar..
    {
	  if(head)
	  {
	    printf(" head->data = %d, arr[%d] = %d\r\n", arr[head->data], idx ,arr[idx]);
	  }
      push(idx); 
	  idx++;
    }
    else //if(head)(head->data < arr[idx+1])
    {          
	  
      currMax = pop();
      
	  printf("pop gives currMax = %d arr[currMax] = %d  idx = %d\r\n",currMax ,arr[currMax],idx);
 
	  if(head)
	  {
		currArea = arr[currMax] * (idx - 1 - head->data);
	  }
	  else
	  {
	    currArea = arr[currMax] * (idx);
	  }
		
	   maxArea = MAX(maxArea, currArea);
       printf("Max Len = %d\r\n\r\n",maxArea);
    }
  }
  
    	  // Now pop the remaining bars to get area..
	  while(head)
	  {
		
        currMax = pop();
		
	    if(head)
	    {
		  currArea = arr[currMax] * (idx - head->data - 1);
	    }
	    else
	    {
	      currArea = arr[currMax] * (idx);
	    }
		
	     maxArea = MAX(maxArea, currArea);
		 printf("\r\nMax Len = %d\r\n",maxArea);
	  }
  
       
}

int main()
{
	int i = 0;
	for(i=0; i < sizeof(histogram)/sizeof(histogram[0]); i++)
	{
		printf("%d ", histogram[i]);
	}
	printf("\r\n");
	maxAreaUnderHistogram(histogram, sizeof(histogram));
	return 0;
}