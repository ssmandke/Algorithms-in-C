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


stackNode *headptr1=  NULL;
stackNode *headptr2=  NULL;

void printStack_2()
{
	stackNode *iter= headptr2;
	printf("\r\nPrint Stack 2\r\n");
	while(iter)
	{
		printf(" %c ",iter->nodePtr->data);
		iter = iter->next;
	}
}

void push(node *data, int stack)
{
  stackNode *curr = malloc(sizeof(stackNode));
  curr->next = NULL;
  curr->nodePtr = data;

  if(stack ==1)
  {
	  if(headptr1)
	  {
  	    curr->next = headptr1;
	    headptr1 = curr;
      }
      else
      {
	    headptr1 = curr;
      }
  }

  if(stack ==2)
  {
	  if(headptr2)
	  {
  	    curr->next = headptr2;
	    headptr2 = curr;
      }
      else
      {
	    headptr2 = curr;
      }
  }

  //printStack();
}

node* pop(int stack)
{
   node *data = NULL;
   stackNode *curr = NULL;

   if(stack == 1)
   {
      curr = headptr1;
      data = curr->nodePtr;
      headptr1 = curr->next;
      free(curr);	  
   }
   else
   {
      curr = headptr2;
      data = curr->nodePtr;
      headptr2 = curr->next;
      free(curr);	  	   
   }

   return data;
}

void postOrderTraversal(node *head)
{
  node *ptr = head;
  push(ptr, 1);
  
  while(1)
  {
	  //Insert node in stack 1, pop it and push it in stack 2 but push children in stack 1	   
	  if(headptr1 == NULL)
		  break;
	  
	  ptr = pop(1);
	  
	  if(ptr)
		  push(ptr,2);
	  
	  if(ptr->left)
		  push(ptr->left,1);

	  if(ptr->right)
		  push(ptr->right,1);
  }

  printStack_2();
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


  printf("\r\npostOrder\r\n");
  postOrderTraversal(root);
  return 0;
}