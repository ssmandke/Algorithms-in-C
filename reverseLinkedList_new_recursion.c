#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
  struct node_t* next;
  char data;
}node;

node *head = NULL;

node* newNode(char x)
{
  node *newPtr = malloc(sizeof(node));
  newPtr->data = x;
  newPtr->next = NULL;
}

void reverse(node *ptr)
{
  if(ptr->next == NULL)
  {
	 head = ptr;
	 return;
  }
  
  reverse(ptr->next);
  
  node *tmp = ptr->next;
  tmp->next = ptr;
  ptr->next = NULL;
  
}

void printList(node *root)
{
	node *tmp= root;
	
	while(tmp)
	{
		printf(" %d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\r\n");
}
int main()
{ 
  head =newNode(1);	  
  head->next =newNode(2);
  head->next->next =newNode(3);
  head->next->next->next =newNode(4);
  head->next->next->next->next =newNode(5);
  
  printList(head);
  reverse(head);
  printList(head);
  return 0;
}