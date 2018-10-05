#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t
{
  struct node_t *next;
  char data;
} node;

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

node *head;

void reverse(node *ptr)
{

   if(ptr->next)
	 reverse(ptr->next);
   else
	 head = ptr;
	 return;
	 
   node *tmp = ptr->next;
   tmp->next = ptr;
   ptr->next = NULL;
}

//  1->2->3->4->5->NULL
//  5->4->3->2->1->NULL
int main()
{
  node *tmp = NULL;
  head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);
  tmp = head;
  
  while(tmp)
  {
	  printf(" %d ", tmp->data);
      tmp = tmp->next;
  }
  
  reverse(head);
  
  return 0;
}