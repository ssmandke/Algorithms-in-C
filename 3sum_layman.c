{-1 , 0, 1 ,2 -1 ,-4}

#define bool char
#define true  1
#define false 0

void MergeSort(char arr[], char left, char right)
{
  if(left < right)
  {
    int pivot = (left + right)/2;
    mergeSort(arr,left,pivot);
    mergeSort(arr,pivot+1,right);
    merge(arr,left,pivot+1,right);
  }
}

void merge(char arr[], char left, char pivot, char right)
{
  char leftIdx = left;
  char rightIdx = pivot;
  char leftEnd = pivot - 1;
  char rightEnd = right;
  char *temp = malloc(sizeof(char)*(right-left+1));
  char i =0; 

  while(leftIdx < rightIdx)
  {
    if(arr[leftIdx] < arr[rightIdx])
    {
      temp[i] = arr[leftIdx]; 
      i++; 
      leftIdx++;
    }
    else if(arr[rightIdx] <= arr[leftIdx])
    {
      temp[i] = arr[rightIdx]; 
      i++; 
      rightIdx++;
    }
  }

  while(leftIdx < leftEnd)
  {
      temp[i] = arr[leftIdx]; 
      i++; 
      leftIdx++;
  }

  while(rightIdx < rightEnd)
  {
      temp[i] = arr[rightIdx]; 
      i++; 
      rightIdx++;
  }

}


bool isSumOfTwoNumbers(char arr[], char sum, char arrLen, char excludeMe)
{
  char left = 0;
  char right = arrLen - 1;
  char len = arrLen;
  char tempSum = 0;
  
  while(left < right)
  {
    tempSum = arr[left] + arr[right]
    
    if (tempSum > sum)
    {
      right--;
    
      if(arr[right] == excludeMe)
      {
         right--;
      }
    }
    else if(tempSum < sum)
    {
      left++;

      if(arr[left] == excludeMe)
      {
         left++;
      }
    }
    else
    {  
      return true;
    }   
  }   
}