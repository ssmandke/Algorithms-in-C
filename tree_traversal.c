#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  char data;
} node;

typedef struct stack_node_t
{
  struct stack_node_t *next;
  node *nodePtr;
} stackNode;

void printStack();

stackNode *headptr=  NULL;

void push(node *data)
{
  stackNode *curr = malloc(sizeof(stackNode));
  curr->next = NULL;
  curr->nodePtr = data;

  if(headptr)
  {
	  curr->next = headptr;
	  headptr = curr;
  }
  else
	  headptr=curr;
  
  //printStack();
}

node* pop()
{
   stackNode *curr = headptr;
   node *data = curr->nodePtr;
   headptr = curr->next;
   free(curr);
   //printf("-X-");
   return data;
}

void printStack()
{
	stackNode *ptr = headptr;

	while(ptr)
	{
		printf("%c ",ptr->nodePtr->data);
		ptr = ptr->next;
	}
	
	printf("\r\n");
}

void inorderTraversal(node *head)
{
  node *ptr = head;
  //printf("\r\n-Z-");
  
  while(1)
  {
	  //printf("\r\n-Y-");
	  if(ptr)
	  {
		  push(ptr);
		  ptr = ptr->left;
	  }
	  else
	  {
		  ptr = pop();
		  printf(" %c ", ptr->data);
		  ptr = ptr->right;
	  }
	  
	  if((headptr == NULL) && (ptr == NULL))
		  return;
  }	  
}

void preorderTraversal(node *head)
{
  node *ptr = head;
  //printf("\r\n-Z-");
  
  while(1)
  {
	  //printf("\r\n-Y-");
	  if(ptr)
	  {
		  printf(" %c ", ptr->data);

		  if(ptr->right)
		  {
    		  push(ptr->right);
		  }
		  
		  if(ptr->left)
		  {
    		  push(ptr->left);		  
		  }
	  }
	  
	  if(headptr == NULL) //Important point to note that don't look for ptr == NULL
		  return;

	  ptr = pop();

  }	  
}



int main()
{
  node *root = malloc(sizeof(node));
  root->data = 'F';
  
  root->left = malloc(sizeof(node));      root->left->data = 'B';
  root->right = malloc(sizeof(node));     root->right->data = 'G';
 
  root->left->left = malloc(sizeof(node));      root->left->left->data  = 'A'; root->left->left->left = NULL; root->left->left->right = NULL;
#if 1   
  root->left->right = malloc(sizeof(node));     root->left->right->data = 'D';
  
  root->left->right->left = malloc(sizeof(node)); root->left->right->left->data = 'C'; root->left->right->left->left = NULL; root->left->right->left->right = NULL;
  root->left->right->right = malloc(sizeof(node)); root->left->right->right->data = 'E'; root->left->right->right->left = NULL; root->left->right->right->right = NULL;
  
  root->right->left = NULL;
  root->right->right = malloc(sizeof(node));       root->right->right->data = 'I'; root->right->right->right = NULL;
  
  root->right->right->left = malloc(sizeof(node)); 
  root->right->right->left->data = 'H'; 
  root->right->right->left->left = NULL; 
  root->right->right->left->right = NULL;
#endif

  printf("\r\ninorder\r\n");
  inorderTraversal(root);  
  
  printf("\r\npreorder\r\n");
  preorderTraversal(root);
  return 0;
}