#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char array[] = "()(()))))";

typedef struct node_t
{
	struct node_t *next;
	char data;
}node;

node *headTop = NULL;

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
}

void push(char data)
{

	node *ptr = newNode(data);
	ptr->next = headTop;
	headTop = ptr;
}

char pop()
{
	char data = headTop->data;
	node *tmp = headTop;
	headTop = headTop = headTop->next;
	
	free(tmp);
	
	return data;
}

int main()
{
	char sizeOfArray = sizeof(array)/sizeof(char);
	sizeOfArray -=1; //Remove the null..
	
	int i = 0;
	int localCount = 0;
	int overallCount = 0;
	push(-1);
	for(i=0; i<sizeOfArray; i++)
	{
		printf(" %d ",i);
		if(array[i] =='(')
		{
			push(i);
			printf("push %d\r\n", i);
		}					
		else
		{
			char retVal = pop();
			printf("pop %d ", retVal);
			
			if(headTop)
			{
				localCount = i - headTop->data;
				printf("localCount = %d\r\n", localCount);
			}
			else
				push(i);
			
			if(overallCount < localCount)
			{
				overallCount = localCount;
			}
		}		
	}
	printf("\r\noverallCount = %d\r\n", overallCount);
	
	return 0;
}