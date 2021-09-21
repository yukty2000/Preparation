/* GFG
Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

 

Example 1:

Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'. 
Example 2:

Input:
pattern = "a*ab"
str = "baaabab"
Output: 0
Explanation: Because of'a' at first position,
pattern and str can't be matched. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function wildCard() which takes the two strings 'pattern' and 'str' as input parameters and returns the answer.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)

Constraints:
1 <= length of(str,pat) <= 200
*/

int wildCard(string pattern,string str)
    {
        int str_l=str.length();
        int p_l=pattern.length();
        vector<vector<bool>> DP(str_l+1,vector<bool>(p_l+1,false));
        DP[0][0]=true;
        for(int i=1;i<p_l;i++)
            DP[0][i]=pattern[i-1]=='*'?DP[0][i-1]:false;
        for(int i=1;i<=str_l;i++)
        {
            for(int j=1;j<=p_l;j++)
            {
                if(str[i-1]==pattern[j-1])
                    DP[i][j]=DP[i-1][j-1];
                else if(pattern[j-1]=='?')
                    DP[i][j]=DP[i-1][j-1];
                else if(pattern[j-1]=='*')
                {
                    DP[i][j]=DP[i-1][j-1] || DP[i-1][j] || DP[i][j-1];
                }
            }
        }
        return DP[str_l][p_l];
    }
