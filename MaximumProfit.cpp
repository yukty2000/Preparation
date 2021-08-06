/* 
GFG -
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.


Example 1:

Input: K = 2, N = 6
A = {10, 22, 5, 75, 65, 80}
Output: 87
Explaination: 
1st transaction: buy at 10 and sell at 22. 
2nd transaction : buy at 5 and sell at 80.
Example 2:

Input: K = 3, N = 4
A = {20, 580, 420, 900}
Output: 1040
Explaination: The trader can make at most 2 
transactions and giving him a profit of 1040.
Example 3:

Input: K = 1, N = 5
A = {100, 90, 80, 50, 25}
Output: 0
Explaination: Selling price is decreasing 
daily. So seller cannot have profit.
*/

// O(N^2*k) solution 
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        // n^2 * k solution
        int **DP = (int **)calloc(K+1,sizeof(int *));
        for(int i=0;i<=K;i++)
            DP[i]=(int *)calloc(N+1,sizeof(int));
        for(int i=1;i<=K;i++)
        {
            for(int j=2;j<=N;j++)
            {
                int ans=0;    
                for(int k=j-1;k>=1;k--)
                {
                    if(A[k-1]>A[j-1])
                        continue;
                    //cout<<A[j-1]-A[k-1]+DP[i-1][k]<<endl;
                    ans = max(ans,A[j-1]-A[k-1]+DP[i-1][k]);
                }
                ans = max(ans,DP[i-1][j]);
                ans = max(ans,DP[i][j-1]);
                DP[i][j] = ans;
            }
        }
        /*for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=5;j++)
            {
                cout<<DP[i][j]<<"\t";
            }
            cout<<endl;
        }*/
        
        int ans = DP[K][N];
        for(int i=0;i<=K;i++)
            free(DP[i]);
        free(DP);
        return ans;
    }
};


// O(n*k) solution 
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        // n^2 * k solution
        int **DP = (int **)calloc(K+1,sizeof(int *));
        for(int i=0;i<=K;i++)
            DP[i]=(int *)calloc(N+1,sizeof(int));
        for(int i=1;i<=K;i++)
        {
            DP[i-1][1]=-A[0];
            for(int j=2;j<=N;j++)
            {
                DP[i-1][j] = max(DP[i-1][j-1],DP[i-1][j]-A[j-1]);
                DP[i][j] = max(DP[i][j-1],A[j-1] + DP[i-1][j]);
            }
            /*for(int j=0;j<=N;j++)
                cout<<DP[i][j]<<" ";
            cout<<endl;*/
        }
        /*for(int i=0;i<=K;i++)
        {
            for(int j=0;j<=N;j++)
            {
                cout<<DP[i][j]<<"\t";
            }
            cout<<endl;
        }*/
        
        int ans = DP[K][N];
        for(int i=0;i<=K;i++)
            free(DP[i]);
        free(DP);
        return ans;
    }
};
