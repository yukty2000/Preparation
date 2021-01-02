/*

Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Input:
X = abcd, Y = xycd
Output: 6

Input:
X = efgh, Y = jghi
Output: 6

*/

int shortestCommonSupersequence(char* X, char* Y, int n, int m) {
    int **Dp=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
        Dp[i]=(int *)malloc((m+1)*sizeof(int));
    for(int i=0;i<=n;i++)
        Dp[i][0]=0;
    for(int i=0;i<=m;i++)
        Dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                Dp[i][j]=1+Dp[i-1][j-1];
            }
            else
            {
                int ans=max(Dp[i][j-1],Dp[i-1][j-1]);
                ans=max(ans,Dp[i-1][j]);
                Dp[i][j]=ans;
            }
        }
    }
    int ans=Dp[n][m];
    for(int i=0;i<=n;i++)
        free(Dp[i]);
    free(Dp);
    int temp=ans;
    ans+=(n-temp)+(m-temp);
    return ans;
}
