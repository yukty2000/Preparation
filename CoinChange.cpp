/* Coin change Problem-
    You are given coins of different denominations and a total amount of money amount. 
    Write a function to compute the fewest number of coins that you need to make up that amount. 
    If that amount of money cannot be made up by any combination of the coins, return -1.
    You may assume that you have an infinite number of each kind of coin.
    
    eg : Input: coins = [1,2,5], amount = 11
         Output: 3
         
    eg : Input: coins = [2], amount = 3
         Output: -1
         
    Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
    
    */
#include <bits/stdc++.h>
using namespace std;

/* Our solution makes use of the Dynamic Programming Approach - with time complexity O(coins.length*amount)
      */
int coinChange(vector<int>& coins, int amount) {
        int l=coins.size();
        int *dp=(int *)malloc((amount+1)*sizeof(int));
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            dp[i]=INT_MAX-1;
        for(int i=0;i<l;i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        int ans;
        if(dp[amount]==INT_MAX-1)
            ans=-1;
        else
            ans=dp[amount];
        free(dp);
        return ans;
    }
