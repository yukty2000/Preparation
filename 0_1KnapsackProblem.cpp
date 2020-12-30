/*
    GFG
    You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
    Note that we have only one quantity of each item.
  In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
  Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights 
  of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
  
  Input:
  N = 3
  W = 4
  values[] = {1,2,3}
  weight[] = {4,5,1}
  Output: 3
  
  */

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int **Dp=(int **)malloc((n+1)*sizeof(int *));
   for(int i=0;i<=n;i++)
   {
       Dp[i]=(int *)malloc((W+1)*sizeof(int));
   }
   for(int i=0;i<=W;i++)
        Dp[0][i]=0;
    for(int j=0;j<=n;j++)
        Dp[j][0]=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=W;j++)
       {
           if(wt[i-1]<=j)
                Dp[i][j]=max(Dp[i-1][j],val[i-1]+Dp[i-1][j-wt[i-1]]);
            else
                Dp[i][j]=Dp[i-1][j];
       }
   }
   int ans=Dp[n][W];
   for(int i=0;i<=n;i++)
        free(Dp[i]);
    free(Dp);
    return ans;
}
