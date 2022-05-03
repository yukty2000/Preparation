/* GFG 
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 

Example 2:

Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and returns the number of palindromic subsequence.
 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1<=length of string str <=1000

*/ 

typedef long long int lli;
    lli power(lli n,lli p,int m)
    {
        if(p==0)
            return 1;
        if(p==1)
            return n;
        lli ans=power(n,p/2,m);
        ans = (ans*ans)%m;
        if(p%2!=0)
            ans=(ans*n)%m;
        return ans;
    }
    lli  countPS(string str)
    {
       //Your code here
        int m=1000000007;
        map<int,lli> p;
        int l=str.length();
        vector<vector<lli>> DP(l,vector<lli>(l,0));
        for(int i=0;i<l;i++)
            DP[i][i]=1;
        for(int d=1;d<l;d++)
        {
            int i=0,j=i+d;
            for(;i<l&&j<l;i++,j++)
            {
                DP[i][j] = (DP[i][j-1]+DP[i+1][j])%m;
                DP[i][j] = (DP[i][j]-DP[i+1][j-1]+m)%m;
                if(str[i]==str[j])
                {
                    lli temp=(DP[i+1][j-1]+1)%m;
                    DP[i][j]=(DP[i][j]+temp)%m;
                }
            }
        }
        /*for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
                cout<<DP[i][j]<<" ";
            cout<<endl;
        }*/
        return DP[0][l-1];
       
    }
