/*
GFG Question
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2

*/

// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    int **Dp=(int **)malloc((x+1)*sizeof(int *));
    for(int i=0;i<=x;i++)
        Dp[i]=(int *)malloc((y+1)*sizeof(int));
    for(int i=0;i<=x;i++)
        Dp[i][0]=0;
    for(int i=0;i<=y;i++)
        Dp[0][i]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(s1[i-1]==s2[j-1])
                Dp[i][j]=1+Dp[i-1][j-1];
            else
                Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        }
    }
    int ans=Dp[x][y];
    for(int i=0;i<=x;i++)
        free(Dp[i]);
    free(Dp);
    return ans;
}
