
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  char data;
}node;

node *root = NULL;

node* convertTreeToMirror(node *root)
{
   if(root == NULL)
   {
      return NULL;
   }
   printf("root = %d, left = %d, right = %d\r\n", root->data, root->left, root->right);
   node *right = root->right;
   node *left  = root->left;
   root->left  = convertTreeToMirror(right);
   root->right = convertTreeToMirror(left);
   
   return root;
   
}

node* createNewNode(char data)
{
	node* tmp = malloc(sizeof(node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
}

void inOrderTraversal(node *root)
{
	if(root == NULL)
		return;
	inOrderTraversal(root->left);
	printf("%d ",root->data);
	inOrderTraversal(root->right);
	
}

int main()
{
  node *root = createNewNode(14);
  root->left  = createNewNode(8);
  root->right = createNewNode(17);
	
  root->left->left  = createNewNode(6);
  root->left->right = createNewNode(10);
	
  root->right->left = createNewNode(16);
  root->right->right = createNewNode(21);
  
  inOrderTraversal(root);
  printf("\r\n");
  root = convertTreeToMirror(root);
  printf("\r\n");
  inOrderTraversal(root);
  printf("\r\n");
  return 0;
}