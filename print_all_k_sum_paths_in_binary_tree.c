#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node_t
{ 
   int data; 
   struct node_t* left; 
   struct node_t* right; 
}node; 
  
static char path[100];
char pathIdx = 0;

void printK_sum_path(node * root, int k) ///preorder + store path + print + pop node..
{
	if(root == NULL)
		return;
	
	path[pathIdx] = root->data;
	pathIdx++;
	
	printK_sum_path(root->left, k ); // check if left has path
	printK_sum_path(root->right,k);  // check if right has path
	
	int sum = 0;
	int i = 0;
	
	for(i=pathIdx-1; i>0; i--)		
	{
		sum+= path[i];
		printf(" i= %d val=%d ",i, path[i]);
		printf("\r\n");
		if(sum == k)
		{
			int j = i;
			printf("for i = %d\r\n",i);
			while(j<=pathIdx-1)
			{
				printf("%d ",path[j]);
				j++;
			}
			printf("\r\n");
		}
	}
	
	//path[pathIdx]=0;
	pathIdx--;
	
}

node *newNode(int val)
{
	node *ptr = malloc(sizeof(node));
	ptr->data = val;
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
    printK_sum_path(root, k); 
  
    return 0; 
} 
