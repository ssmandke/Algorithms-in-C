
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node_t
{ 
   int val; 
   struct node_t* left; 
   struct node_t* right; 
}node; 
  
static char path[100];
char pathIdx = 0;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int pathCount = 0;

void helper(node* root, int sum)
{
    if(root == NULL)
        return;

	path[pathIdx] = root->val;
	pathIdx++;
	
    if(root->val == sum)
    {
     // printf(" %d \r\n", root->val);
        pathCount++;		
        // return;
		int j = 0;

		for(; j < pathIdx; j++)
		{
			printf("%d ", path[j]);
		}
		printf("\r\n");
    }
        
    helper(root->left, sum - root->val);
    helper(root->right, sum - root->val);    
	
	pathIdx--;
}

void getPathSum(node* root, int sum) 
{
    
    if(root == NULL)
        return;

    helper(root, sum);
    getPathSum(root->left, sum);
    getPathSum(root->right, sum);
}

int pathSum(node* root, int sum) 
{
    pathCount = 0;
    getPathSum(root, sum);    
    return pathCount;  
}


node *newNode(int val)
{
	node *ptr = malloc(sizeof(node));
	ptr->val = val;
	ptr->left = NULL;
	ptr->right = NULL;
}

// Driver code 
int main() 
{ 
    node *root = newNode(1); 
    root->left = newNode(3); 
    root->left->left = newNode(2); 
    root->left->right = newNode(1); 
    root->left->right->left = newNode(1); 
    root->right = newNode(-1); 
    root->right->left = newNode(4); 
    root->right->left->left = newNode(1); 
    root->right->left->right = newNode(2); 
    root->right->right = newNode(5); 
    root->right->right->right = newNode(2); 
    memset(path, 100, 0);
    int k = 5; 
    getPathSum(root, k); 
  
    return 0; 
} 


