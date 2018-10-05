

typedef struct node_t
{
  struct node* left;
  struct node* right;
  char data;
}node;

node* lowestCommonAncestor(node *root, node *ptrA, node *ptrB)
{
  if(root == NULL)
	  return NULL;
  
  if((ptrA == NULL) || (ptrB == NULL))
	  return NULL;
  
  if(root == ptrA)
	  return root;

  if(root == ptrB)
	  return root;
  
  node *left  = lowestCommonAncestor(root->left,  ptrA, ptrB);
  node *right = lowestCommonAncestor(root->right, ptrA, ptrB);
  
  if((left != NULL) && ( right !=NULL))
	  return root;
  
  return (left == NULL? right : left);
	  
}