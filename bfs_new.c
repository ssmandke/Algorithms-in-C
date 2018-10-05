#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  char data;
} node;

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

node *head;

int main()
{
  //create the Binary tree
  //1 , 2 , 3 , 4 , 5,  6 , 7 is the BFS
  unsigned int y = 0x12345678
  enqueue(root);
  
  while(!q->empty())
  {
	  ptr = dequeue();
	  
	  nodeCount++;
	  
	  if(ptr->left)
		  enqueue(ptr->left);
	  if(ptr->right)
		  enqueue(ptr->right);

  }
}