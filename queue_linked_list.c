// implement an LRU cache..use a queue?
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
  struct node_t *next;
  char data;
  int (*callback)(int, int);
}node;

node *head = NULL;
node *tail = NULL;

int printNode(char x, char y)
{
  printf("x = %d\r\n",x);
  return 0;
}

void printList(node *ptr)
{
	node *tmp = ptr;
	
	while(tmp)
	{
		printf(" %d ",tmp->data);
		tmp = tmp->next;
	}
	
	printf("\r\n");
}

void insert(char data)
{
  node *ptr = malloc(sizeof(node));
  ptr->next = NULL;
  ptr->data = data;
  ptr->callback = &printNode;
  
  printf("Insert = %d\r\n",data);
  
  if(!head)
  {
    head = tail = ptr;
	head->next = tail->next = NULL;
    return;
  }
  
  tail->next = ptr;
  tail = ptr; /// 1->2->3->4->5 where 5 is last element and it is tail..  
}
 
char removeNode()
{
  if(head == NULL)
  {
    return -1;
  }
    
  char retVal = head->data;
  head = head->next;
  return retVal;
 
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);l
	insert(5);
	printList(head);
	printf("remove  %d \r\n",removeNode());
	printf("remove  %d \r\n",removeNode());
	printf("remove  %d \r\n",removeNode());
	return 0;
}