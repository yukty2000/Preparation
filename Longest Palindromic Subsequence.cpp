/*
    Given a String S, find the length of the longest palindromic subsequence.
    Input: S = "abbaab"
    Output: 4
    
    */
    
 
class Solution
{
public:
    int lps(string S)
    {
        int l=S.length();
        int **Dp=(int **)calloc(l,sizeof(int *));
        for(int i=0;i<l;i++)
        {
            Dp[i]=(int *)calloc(l,sizeof(int));
        }
        for(int j=0;j<l;j++)
        {
            Dp[j][j]=1;
        }
        for(int i=1;i<l;i++)
        {
            int j=0,k=i;
            while(k<l&&j<l)
            {
                Dp[j][k]=max(Dp[j][k-1],Dp[j+1][k]);
                if(S[j]==S[k])
                {
                    Dp[j][k]=max(Dp[j][k],2+Dp[j+1][k-1]);
                }
                k++;
                j++;
            }
        }
        int ans=Dp[0][l-1];
        for(int i=0;i<l;i++)
        {
            free(Dp[i]);
        }
        free(Dp);
        return ans;
    }
};
