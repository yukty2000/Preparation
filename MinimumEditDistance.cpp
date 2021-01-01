/*
Leetcode
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

1) Insert a character
2) Delete a character
3) Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3

Input: word1 = "intention", word2 = "execution"
Output: 5

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int x=word1.length();
        int y=word2.length();
        int **Dp=(int **)malloc((y+1)*sizeof(int *));
        
        for(int i=0;i<=y;i++)
            Dp[i]=(int *)malloc((x+1)*sizeof(int));
        
        for(int i=0;i<=x;i++)
            Dp[0][i]=i;
        for(int i=0;i<=y;i++)
            Dp[i][0]=i;
        
        for(int i=1;i<=y;i++)
        {
            for(int j=1;j<=x;j++)
            {
                if(word2[i-1]==word1[j-1])
                    Dp[i][j]=Dp[i-1][j-1];
                else
                {
                    int temp=min(Dp[i-1][j-1],Dp[i-1][j]);
                    int ans=min(Dp[i][j-1],temp);
                    Dp[i][j]=ans+1;
                }
            }
        }
        int ans=Dp[y][x];
        for(int i=0;i<=y;i++)
            free(Dp[i]);
        free(Dp);
        return ans;
    }
};
