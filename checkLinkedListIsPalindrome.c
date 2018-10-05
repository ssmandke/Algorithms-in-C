

//1->2->3->2->1->NULL

int main()
{
  node *ptr1, *ptr2;
  ptr=ptr2=head;
  char isOdd = 0;
  
  while(ptr2)
  {
    if((ptr2->next) && (ptr2->next->next))
    {
      ptr2 = ptr2->next->next;
    }
    else
    {
      if((ptr2->next) == NULL)
      {
         isOdd = 1;
      }       
      ptr2 = NULL;
    }    
    
    ptr1 = ptr1->next;
  }
  
  ptr2 = head;

  //ptr1 is at the center so, get ptr2 to the head and begin traversing and check
  while((ptr1!=NULL) && (ptr2!=NULL))

  return 0;
}