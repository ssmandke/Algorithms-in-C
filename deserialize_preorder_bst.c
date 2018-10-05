#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define bool char

#define true 1
#define false 0

#define N  8
#define INT_MIN -1
#define INT_MAX 99

char preorderBst[N];
char count = 0;
char currIdx = 0;

typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  char data;
} node;

void preorder(node *root)
{
	if(root == NULL)
		return;
	printf(" %d ", root->data);
	preorderBst[count] = root->data;
	count++;

	preorder(root->left);
	preorder(root->right);
}

node *newNode(char data)
{
	node *ptr = malloc(sizeof(node));
	ptr->data = data;
	ptr->left = ptr->right = NULL;
	return ptr;
}

node* deserialize_preorder_bst(char arr[], int min, int max)
{
    if(currIdx > N)
		return NULL;
	
	node *root = NULL;
	printf("\r\n min = %d, max = %d", min, max);
	if(arr[currIdx] > min && arr[currIdx] < max)
	{
		root = newNode(arr[currIdx]);
		currIdx++;
		root->left = deserialize_preorder_bst(arr, min, root->data);
		root->right = deserialize_preorder_bst(arr, root->data, max);
	}
   
	return root;
}

int main()
{
	node *root = newNode(15);
	root->left = newNode(11);
	root->right = newNode(17);
	root->left->left = newNode(9);
	root->left->right = newNode(13);
	root->left->right->left = newNode(12);
	root->right->left= newNode(16);
	root->right->right = newNode(31);
	preorder(root);
	root = deserialize_preorder_bst(preorderBst, INT_MIN, INT_MAX);
	printf("\r\n");
	preorder(root);
	return 0;
}