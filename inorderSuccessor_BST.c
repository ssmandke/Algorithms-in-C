#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

typedef struct bnode_t
{
  struct bnode_t *left;
  struct bnode_t *right;
  char data;
}bnode;

typedef struct node_t
{
  struct node_t *next;
  bnode *ptrBNode;
}node;

node  *head =  NULL;
bnode *root = NULL;

void push(bnode *tmp)
{
  node *ptr = malloc(sizeof(node));
  ptr->ptrBNode = tmp;
  ptr->next = NULL;

  if(head == NULL)
  {
    head = ptr;
	//printf("null head\r\n");
    return;
  }
   
  //printf("NON null head\r\n");

  ptr->next = head;
  head = ptr;  
}

bnode* pop()
{
  if(head == NULL)
  {
    return NULL;
  } 

  bnode *tmp = head->ptrBNode;
  node *ptr  = head;
  head = head->next;
  free(ptr);
  return tmp;
}

void inOrderTraversal(bnode *root)
{
   bnode *ptr = root;
  
   while(1)
   {
     if(ptr)
     {
	   //printf("push %d\r\n",ptr->data);
       push(ptr);
       ptr = ptr->left;
     }
     else
     {
	   //printf("pop!\r\n");
       if(head==NULL)
	   {
		 printf("empty stack\r\n");
         break;
	   }
       ptr = pop();
       printf(" %d ",ptr->data);
       ptr=ptr->right;
     }
   } 
}
bnode* binarySearch(bnode *root, char key)
{
	if(root == NULL)
		return NULL;
	
	if(root->data == key)
		return root;
	
	if(root->data < key)
		return binarySearch(root->right, key);
	
	if(root->data > key)
		return binarySearch(root->left, key);
}

bnode* inOrderSuccessorBST(bnode *root, char key)
{
   bnode *tmp = NULL;
   
   tmp = binarySearch(root, key);
   printf("root = %d, tmp = %d\r\n", root->data, tmp->data);

   // return min node in right subtree.. 
   if(tmp->right)
   {
      bnode *ptr = tmp->right;

      while(ptr)
      {
        tmp = ptr;
        ptr = ptr->left;
      }
      
      return tmp;
   }
   printf("if not right subtree...start from root = %d, current node = %d for key = %d\r\n", root->data, tmp->data, key);
   // or ancestor if right subtree is absent
   bnode *ancestor = root;
   bnode *successor = NULL;
   //printf("Root = %d, root left = %d , root right = %d\r\n", root->data, root->left->data, root->right->data);

   while(ancestor != tmp)
   {   
      if(key < ancestor->data )
      {
         successor = ancestor; //this is the node who is ancestor to the node we are looking for..
         ancestor = ancestor->left;
         //printf("L %d, ",ancestor->data);
      }
      else if( key > ancestor->data)
      {
         ancestor = ancestor->right;
	     //printf("R %d, ",ancestor->data);
      }
   }
   
   return successor;  
}

bnode* createNewBstNode(char data)
{
	bnode *newNode = malloc(sizeof(bnode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

int main()
{
	bnode *root = createNewBstNode(14);
	root->left  = createNewBstNode(8);
	root->right = createNewBstNode(17);
	
	root->left->left  = createNewBstNode(6);
	root->left->right = createNewBstNode(10);
	
	root->right->left = createNewBstNode(16);
	root->right->right = createNewBstNode(21);
	
	inOrderTraversal(root);
	bnode* tmp = inOrderSuccessorBST(root, 21);
	printf("inorder successor of 21 is %d\r\n", (tmp == NULL? -1 : tmp->data));
	return 0;
}