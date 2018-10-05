#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

typedef struct node_t
{
	struct node_t *next;
	struct node_t *child;
	char data;
}node;

void flattenLinkedList(node *head)
{
	if(head == NULL)
		return;
	
	if(head->next == NULL)
		return;
	
	
	node *iter = head;
	node *curr = head;
	node *next = NULL;
	
	if(head->data == 7)
	{
		printf("head->child->data = %d\r\n",head->child->data);
	}
	while(iter)
	{
		next = iter;
		iter = iter->next;
	}
	//printf("head->data %d next->next->data = %d\r\n ", head->data,head->child->data);
	next->next = head->child;
	head->child = NULL;
	head = head->next;
	flattenLinkedList(head);
	
}

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->next = tmp->child = NULL;
	return tmp;
}

int main()
{
    node *head = newNode(10);
	node *ptr = head;

    head->next = newNode(5);	
	head->next->next = newNode(12);
	head->next->next->next = newNode(7);
	head->next->next->next->next = newNode(11);
		
	head->child = newNode(4);	
	head->child->next = newNode(20);	
	head->child->next->next = newNode(13);	
	
	head->child->next->child = newNode(2);
	head->child->next->next->child = newNode(16);	
	head->child->next->next->child->child = newNode(3);	
	
	head->next->next->next->child = newNode(17);  head->next->next->next->child->next = newNode(6);
    head->next->next->next->child->child = newNode(9); head->next->next->next->child->child->next = newNode(8);
	head->next->next->next->child->child->child = newNode(19); head->next->next->next->child->child->child->next = newNode(15);
		
	while(ptr)
	{
		printf(" %d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\r\n");
	flattenLinkedList(head);
	ptr = head;	
	while(ptr)
	{
		printf(" %d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\r\n");

	return 0;
}
