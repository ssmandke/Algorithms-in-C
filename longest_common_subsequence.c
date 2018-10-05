#define MAX(a,b) (a>b? a:b)

int numDistinct(char* s, char* t) {
    
    int i = 0;
    int j = 0;
    
    int M = strlen(s);
    int N = strlen(t);
    
    int **dp = malloc(sizeof(int *) * (M+1));
    
    for(i=0; i<N+1 ; i++)
    {
        dp[i] = malloc(sizeof(int) * (M+1));
    }
    
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            dp[i][j] = 0;
        }
    }
    
    for(i=0; i< (M+1); i++) // the M+1 is to allow first element to do i-1 j-1..so we fill first row and first col with zeroes..
    {
        for(j=0; j<(N+1); j++)
        {
            if(s[i] == s[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = MAX(dp[i-1][j], d[i][j-1]);
            }
            
        }
    }
    
}