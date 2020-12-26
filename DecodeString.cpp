/* A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Given a non-empty string containing only digits, determine the total number of ways to decode it.

  The answer is guaranteed to fit in a 32-bit integer.
  
  Input: s = "12"
  Output: 2
  */
  
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int len=s.length();
        int *dp=(int *)malloc((len+1)*sizeof(int));
        dp[len]=1;
        dp[len-1]=1;
        if(s[len-1]=='0')
        {
            dp[len-1]=-1;
        }
        for(int i=len-2;i>=0;i--)
        {
            int curr_ch=s[i]-48;
            int next_ch=s[i+1]-48;
            if(next_ch==0&&(curr_ch>2||curr_ch==0))
            {
                free(dp);
                return 0;
            }
            if(curr_ch==0)
            {
                dp[i]=-1;
                continue;
            }
            if(next_ch==0)
            {
                dp[i]=dp[i+2];
            }
            else if(curr_ch==1||(curr_ch==2&&next_ch<=6))
            {
                if(dp[i+2]!=-1)
                    dp[i]=dp[i+1]+dp[i+2];
                else
                    dp[i]=dp[i+1];
            }
            else
            {
                dp[i]=dp[i+1];
            }
        }
        int ans=dp[0];
        free(dp);
        return ans;
    }
};
