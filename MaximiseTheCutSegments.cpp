/* Problem from GeeksforGeeks 
  Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way
  that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
    After performing all the cut operations, your total number of cut segments must be maximum.
    
    Input:
      N = 4
      x = 2, y = 1, z = 1
      Output: 4   */
//Complete this function
int calcans(int n, int x, int y, int z,int *dp)
{
    if(dp[n]!=-1)
        return dp[n];
    int val1,val2,val3;
    val1=val2=val3=INT_MIN;
    if(n>=x)
        val1=1+calcans(n-x,x,y,z,dp);
    if(n>=y)
        val2=1+calcans(n-y,x,y,z,dp);
    if(n>=z)
        val3=1+calcans(n-z,x,y,z,dp);
    dp[n]=max(max(val1,val2),val3);
    return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    int *dp=(int *)malloc((n+1)*sizeof(int));
    //memset(dp,-1,(sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i]=-1;
    dp[0]=0;
    int ans=calcans(n,x,y,z,dp);
    if(ans<0)
        ans=0;
    free(dp);
    return ans;
}
