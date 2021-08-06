/*
GFG - 
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Example 1:

Input:
abcd
Output:
3
Explanation:
Here we can append 3 characters in the 
beginning,and the resultant string will 
be a palindrome ("dcbabcd").
Example 2:

Input:
aba
Output:
0
Explanation:
Given string is already a pallindrome hence
no insertions are required.

*/

class Solution{   
public:
    int findMinInsertions(string S){
        // code here 
        int l=S.length();
        // Find longest palindromic subsequennce
        vector<vector<int>> DP(l,vector<int>(l,0));
        for(int i=0;i<l;i++)
            DP[i][i]=1;
        for(int d=1;d<l;d++)
        {
            int i=0,j=i+d;
            for(;i<l&&j<l;i++,j++)
            {
                if(S[i]==S[j])
                {
                    DP[i][j] = 2+DP[i+1][j-1];
                }
                else
                {
                    DP[i][j]=max(DP[i][j-1],DP[i+1][j]);
                }
            }
        }
        return l-DP[0][l-1];
    }
};
