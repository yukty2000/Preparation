/*

GFG -

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

*/

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        // Find all palindromic substrings
        int l=str.length();
        vector<vector<bool>> DP(l,vector<bool>(l,true));
        for(int d=1;d<l;d++)
        {
            int i=0,j=i+d;
            for(;i<l&&j<l;i++,j++)
            {
                if(str[i]==str[j]&&DP[i+1][j-1])
                {
                    DP[i][j]=true;
                }
                else
                {
                    DP[i][j]=false;
                }
            }
        }
        // Calculate for each partition of each substring 
        vector<int> p(l+1,0);
        for(int i=l-1;i>=0;i--)
        {
            int ans=INT_MAX;
            for(int j=i;j<l-1;j++)
            {
                if(DP[i][j]) // if this is a palindrome
                {
                    ans=min(ans,p[j+1]+1);
                }
            }
            if(DP[i][l-1])
            {
                ans=min(ans,p[l]);
            }
            p[i]=ans;
        }
        return p[0];
    }
};
