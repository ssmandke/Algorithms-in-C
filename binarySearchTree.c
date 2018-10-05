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

node *newNode(char data)
{
	node *tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}

node* binarySearch(node* ptr, char key)
{
  if((ptr == NULL) || (ptr->data == key))
     return ptr;
 
  if(key < ptr->data)
  {
	  return binarySearch(ptr->left, key);
  }
  else
	  return binarySearch(ptr->right, key);

}

/* A utility function to insert a new node with given key in BST */
node* insert(node* mynode, char key)
{
    /* If the tree is empty, return a new node */
    if (mynode == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < mynode->data)
        mynode->left  = insert(mynode->left, key);
    else if (key > mynode->data)
        mynode->right = insert(mynode->right, key);   
 
    /* return the (unchanged) node pointer */
    return mynode;
}

node* deleteNode(node* root, char key)
{
	if(root == NULL)
		return root;
	if(key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		//Case 1 : Both children are NULL
		if((root->left == NULL) && (root->right =  NULL))
		{
			free(root);
			return NULL;
		}
		else if(root->left == NULL)
		{
			node *temp = root;
			root = root->right;
			free(temp);
			
		}
		else if(root->right == NULL)
		{
			node *temp = root;
			root = root->left;
			free(temp);
			
		}
		else
		{
			node *iterator = root->right;
			
			while(iterator->left)
				iterator = iterator->left;
			
			root->data = iterator->data; // Copy the inorder Successor value to the root/node to be initially removed
			root->right = deleteNode(root->right, root->data); //Delete the inorder Successor in right subtree..			
		}
		return root;
	}		
	
}

void inorderTraversal(node *ptr)
{
	if(ptr == NULL)
		return;
    ///printf("ptr->data  %d \r\n",ptr->data);
	inorderTraversal(ptr->left);
	printf(" %d ",ptr->data);
	inorderTraversal(ptr->right);
}

int main()
{
   node *root = malloc(sizeof(node));
   node *foundNode = NULL;   
   root->left = root->right = NULL;
   root->data = 12;
   insert(root, 9);
   insert(root, 21);
   insert(root, 4);
   insert(root, 10);      
   insert(root, 16);
   insert(root, 35);
#if 0   
/*
   root->left  = malloc(sizeof(node)); root->left->data = 9; 
   root->right = malloc(sizeof(node)); root->right->data = 21;
   
   root->left->left = malloc(sizeof(node)); root->left->left->data = 4; root->left->left->left = root->left->left->right = NULL;
   root->left->right = malloc(sizeof(node)); root->left->right->data = 10; root->left->right->left = root->left->right->right = NULL;
   
   root->right->left = malloc(sizeof(node)); root->right->left->data = 16;  root->right->left->left =  root->right->left->right = NULL;
   root->right->right = malloc(sizeof(node)); root->right->right->data = 35; root->right->right->left = root->right->right->right = NULL;
  */
#endif
   if((foundNode = binarySearch(root, 21)) !=NULL)
	   printf("Found %d\r\n",foundNode->data);
   
   if((foundNode = binarySearch(root, 28)) !=NULL)
	   printf("Found %d\r\n",foundNode->data);
   inorderTraversal(root);
   printf("\r\n");
   deleteNode(root, 21);
   printf("\r\n");
   inorderTraversal(root);
   deleteNode(root, 16);
   printf("\r\n");
   //printf("\r\nAfter deleting 21\r\n");
   inorderTraversal(root);
   return 0;
}