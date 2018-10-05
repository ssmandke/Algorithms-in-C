#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_t
{
  int data;
  struct node_t *prev;
  struct node_t *next;
}node;

node *head = NULL;
node *tail = NULL;

void insert(int value)
{
	if(tail == NULL)
	{
		node *ptr = malloc(sizeof(node));
		ptr->next = ptr->prev = NULL;
		head = tail = ptr;
		ptr->data = value;
	}
	else
	{
		node *ptr = malloc(sizeof(node));
		ptr->data = value;
		tail->next = ptr;
		ptr->prev = tail;
		ptr->next = NULL;
		tail = ptr;
	}
}

int delete()
{
	if(head == NULL)
	{
		return -1;
	}
	else	
	{
		node *tmp = head;
		int data = tmp->data;
		head = head->next;
		free(tmp);
		return data;
	}
}

node* mallocNode(int data)
{
	node *newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

int main()
{
	insert(1);
	printf("head = %d, tail = %d\n", head->data, tail->data);
	insert(2);
	printf("head = %d, tail = %d\n", head->data, tail->data);
	insert(3);
	printf("head = %d, tail = %d\n", head->data, tail->data);
	insert(4);
	printf("head = %d, tail = %d\n", head->data, tail->data);
	printf("Delete -> %d\n", delete());
	printf("Delete -> %d\n", delete());
	printf("Delete -> %d\n", delete());
	return 0;
}