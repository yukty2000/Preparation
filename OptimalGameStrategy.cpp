/*
  GFG Problem-
  You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

  In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

  You need to determine the maximum possible amount of money you can win if you go first.
  
  Input:
  N = 4
  A[] = {5,3,7,10}
  Output: 15
  
  Dynamic Programming - Top Down + Tabulation
  */

typedef long long int lli;
struct Node
{
    lli p1,p2;
};
void maximumAmt(int arr[], int n,struct Node**Dp,int low,int high,int player)
{
    if(Dp[low][high].p1!=-1)
    {
        return;
    }
    if(low==high)
    {
        Dp[low][high].p1=arr[low];
        Dp[low][high].p2=0;
        return;
    }
    maximumAmt(arr,n,Dp,low+1,high,1-player);
    maximumAmt(arr,n,Dp,low,high-1,1-player);
    if(player==0)
    {
        if(Dp[low+1][high].p1+arr[low]>Dp[low][high-1].p1+arr[high])
        {
            Dp[low][high].p1=Dp[low+1][high].p1+arr[low];
            Dp[low][high].p2=Dp[low+1][high].p2;
        }
        else
        {
            Dp[low][high].p1=Dp[low][high-1].p1+arr[high];
            Dp[low][high].p2=Dp[low][high-1].p2;
        }
    }
    else
    {
        if(Dp[low+1][high].p2+arr[low]>Dp[low][high-1].p2+arr[high])
        {
            Dp[low][high].p2=Dp[low+1][high].p2+arr[low];
            Dp[low][high].p1=Dp[low+1][high].p1;
        }
        else
        {
            Dp[low][high].p2=Dp[low][high-1].p2+arr[high];
            Dp[low][high].p1=Dp[low][high-1].p1;
        }
    }
    return;
}

long long maximumAmount(int arr[], int n) 
{
    struct Node **Dp=(struct Node **)malloc(n*sizeof(struct Node *));
    for(int i=0;i<n;i++)
    {
        Dp[i]=(struct Node *)malloc(n*sizeof(struct Node));
        for(int j=0;j<n;j++)
        {
            Dp[i][j].p1=Dp[i][j].p2=-1;
        }
    }
    maximumAmt(arr,n,Dp,0,n-1,1);
    lli ans=Dp[0][n-1].p2;
    for(int i=0;i<n;i++)
        free(Dp[i]);
    free(Dp);
    return ans;
}
