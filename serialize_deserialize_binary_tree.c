#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
// Definition for a binary tree node.
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
static char treeTraversal[100];
char count = 0;
char idx = 0;
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) 
{
    if(root == NULL)
    {
      printf(" null ");
      treeTraversal[count] = -1;
      count++;		
      return NULL;
    }
    printf(" %d ",root->val);
    treeTraversal[count] = root->val;
    count++;
    serialize(root->left);
    serialize(root->right);    
    
    return &treeTraversal[0];
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize() 
{
    if((count == 0) || (idx == count))
        return NULL;
    if(treeTraversal[idx] == -1)
	{
		idx++;
        return NULL;
	}
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
	
    printf(" %d ", treeTraversal[idx]);
	root->val =	treeTraversal[idx];
    idx++;
    root->left  = deserialize();
	root->right = deserialize();
	return root;
}

int main()
{
	int i  = 0;
	int cnt = 0;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = 1;
	
	root->left  = malloc(sizeof(struct TreeNode)); root->left->val = 2;	
	root->left->left   = malloc(sizeof(struct TreeNode)); root->left->left->val = 4; 
	root->left->left->left = root->left->left->right = NULL;
	root->left->right  = malloc(sizeof(struct TreeNode)); root->left->right->val = 5;
	root->left->right->left = root->left->right->right = NULL;
	
	root->right = malloc(sizeof(struct TreeNode)); root->right->val = 3;
	root->right->left = malloc(sizeof(struct TreeNode));  root->right->left->val = 6;
	root->right->left->left = root->right->left->right = NULL;
	root->right->right = malloc(sizeof(struct TreeNode)); root->right->right->val = 7;
	root->right->right->left = root->right->right->right = NULL;
	
	serialize(root);
	printf("\r\ntraversal for count = %d\r\n",count);
	while(i<count)
	{
		printf("%d, ", treeTraversal[i]);
		i++;
		
	}
	printf("\r\ndeserialize!!\r\n");
	struct TreeNode *root1 = deserialize();
	count = 0;
	idx = 0;
	memset(treeTraversal,0, 100);
	printf("\r\nSerialize!!\r\n");
	serialize(root1);
	return 0;
}