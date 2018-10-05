
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)


typedef struct node_t
{
  struct node_t *next;
  char data;
}node;

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

node *headPtr = NULL;

void reverse(node **head)
{
  node *curr = *head;
  node *next = NULL; 
  node *prev = NULL;

  while(curr)
  {
	 next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
  }

   *head = prev;  
}

int main()
{
  node *ptr = newNode(1);
  headPtr = ptr;
  ptr->next = newNode(2);
  ptr->next->next = newNode(3);
  ptr->next->next->next = newNode(4);
  ptr->next->next->next->next = newNode(5);
  
  node *tmp = ptr;
  
  while(tmp)
  {
	  printf(" %d ",tmp->data);
	  tmp = tmp->next;
  }
  printf("\r\n");
  
  reverse(&headPtr);
  
  tmp = headPtr;
  
  while(tmp)
  {
	  printf(" %d ",tmp->data);
	  tmp = tmp->next;
  }
  printf("\r\n");
  
  return 0;
}