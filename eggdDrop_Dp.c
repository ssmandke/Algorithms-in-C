// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle 
# include <stdio.h> 
# include <limits.h> 
  
// A utility function to get maximum of two integers 
int max(int a, int b) { return (a > b)? a: b; } 
  
/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int k, int n) 
{ 
    /* A 2D table where entery eggFloor[i][j] will represent minimum 
       number of trials needed for i eggs and j floors. */
    int eggFloor[k+1][n+1]; 
    int res; 
    int i, j, x; 
  
    // We need one trial for one floor and0 trials for 0 floors 
    for (i = 1; i <= k; i++) 
    { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
  
    // We always need j trials for one egg and j floors. 
    for (j = 1; j <= n; j++) 
        eggFloor[1][j] = j; 
  
    // Fill rest of the entries in table using optimal substructure 
    // property 
    for (i = 2; i <= k; i++) //Eggs
    { 
        for (j = 2; j <= n; j++) // Floors
        { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) 
            { 
		        // eggFloor[i-1][x-1] is the case in which egg breaks
				// eggFloor[i][j-x]   is the case in which egg does not break
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]); 
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    // eggFloor[k][n] holds the result 
    return eggFloor[k][n]; 
} 
  
/* Driver program to test to pront printDups*/
int main() 
{ 
    int k = 2, n = 36; 
    printf ("nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", k, n, eggDrop(k, n)); 
    return 0; 
}