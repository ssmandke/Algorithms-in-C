#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

// This is for same sized lists

// 2 -> 3 > 6 +
//4 + 7 + 3
//7 0 9
void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

typedef struct node_t
{
    int data;
    struct node_t *next;
}node;

node *newNode(int value)
{
   node *ptr = malloc(sizeof(node));
   ptr->data = value;
   ptr->next = NULL;
}

int carry = 0;

node *addListRecursion(node *n1, node *n2)
{
    if(n1== NULL && n2 == NULL)
        return NULL;
    
    node *newNodeAllocated = malloc(sizeof(node));      

    if(n1->next == NULL && n2->next !=NULL)
    {
       printf("n2->data only = %d\r\n",n2->data);
       newNodeAllocated->next =  addListRecursion(n1, n2->next); 
    }
    else if(n2->next == NULL && n1->next !=NULL)
    {
       printf("n1->data only = %d\r\n",n1->data);
       newNodeAllocated->next =  addListRecursion(n1->next, n2);
    }  
    else
	{
       newNodeAllocated->next =  addListRecursion(n1->next, n2->next);
        
       printf("after recursion\r\n\r\n");
       printf("n1 = %d, n2 = %d carry = %d\r\n",n1->data, n2->data, carry);
       int sum = n1->data + n2->data + carry;

       carry = sum/10;
       sum = sum % 10;
       printf("sum = %d, carry = %d\r\n",sum, carry);
       newNodeAllocated->data = sum;
        
        
       return newNodeAllocated;
	}   
}

int main()
{
  node *head1 = newNode(2);
  head1->next = newNode(3);
  head1->next->next = newNode(6);
  //head1->next->next->next = newNode(5);
  //head1->next->next->next->next = newNode(8);

  node *head2 = newNode(4);
  head2->next = newNode(7);
  head2->next->next = newNode(3);
  
  node *result = addListRecursion(head1, head2);
  
  while(result)
  {
      printf(" %d -> ", result->data);
      result = result->next;
  }
  printf("\r\n");
  
  return 0;
}