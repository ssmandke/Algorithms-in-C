int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
  int i = 0;
  int start = 0;
  int j = 0;

  for(i=0; i<gasSize; i++)
  {
    if(gas[i] <= cost[i])
    {
        continue;        
    }
    start = i;    
    int  k = 0;
    int routeCost = 0;
    printf("start = %d\r\n",start);
    for(k=0; k<gasSize;k++)
    {
       routeCost +=gas[i] - cost[i];
        printf("routeCost = %d\r\n",routeCost);      
       if(routeCost < 0)
           break;
       i++;
       i=i%gasSize; 
    
       if(i==start)
       {
          if(routeCost >= 0)
          {
             return i;
          }
          break;
       }     
    }
    
  }

  return -1;
}
