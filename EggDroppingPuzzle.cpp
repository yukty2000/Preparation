/*
GFG
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.

Input:
N = 2, K = 10
Output: 4

Input:
N = 3, K = 5
Output: 3

*/

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{
    int **Dp=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
    {
        Dp[i]=(int *)malloc((k+1)*sizeof(int));
    }
    for(int i=0;i<=n;i++)
        Dp[i][0]=0;
    for(int j=0;j<=k;j++)
        Dp[1][j]=j;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j<i)
                Dp[i][j]=Dp[i-1][j];
            else
            {
                int ans=INT_MAX;
                for(int v=1;v<=j;v++)
                {
                    int temp=1+max(Dp[i][j-v],Dp[i-1][v-1]);
                    if(temp<ans)
                        ans=temp;
                }
                Dp[i][j]=ans;
            }
        }
    }
    int ans=Dp[n][k];
    for(int i=0;i<=n;i++)
        free(Dp[i]);
    free(Dp);
    return ans;
}
