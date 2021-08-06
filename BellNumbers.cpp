/*
Given a set of n elements, find number of ways of partitioning it.

 

Example 1:

Input:
N = 2
Output: 2
Explanation:
Let the set be 
{1, 2}:
{ {1}, {2} } { {1, 2} }
 

Example 2:

Input:
N = 3
Output: 5

Since the value can be quite large print the value modulo 10^9+7.
*/

class Solution {
public:
    typedef long long int lli;
    lli power(lli a,int p,int N)
    {
        if(p==1)
            return a;
        if(p==0)
            return 1;
        lli ans=power(a,p/2,N);
        ans = (ans*ans)%N;
        return p%2==0?ans:(a*ans)%N;
    }
    int bellNumber(int n)
    {
       // Code Here
       const int N = 1000000007;
       vector<lli> DP(n+1);
       DP[0]=DP[1]=1;
       vector<lli> C;
       vector<lli> I(n+1);
       I[0]=1;
       for(int i=1;i<=n;i++)
       {
           I[i] = power(i,N-2,N);
       }
       C.push_back(1);
       for(lli i=2;i<=n;i++)
       {
           C.push_back(1);
           for(lli j=1;j<i-1;j++)
           {
               lli inv = I[i-1-j];
               C[j] = (C[j]*(i-1))%N;
               C[j] = (C[j]*inv)%N;
           }
           for(lli j=0,k=i-1;j<i&&k>=0;j++,k--)
           {
               lli ans= (C[j]*DP[k])%N;
               DP[i] = (DP[i]+ans)%N;
           }
       }
       /*for(int i=0;i<=n;i++)
       {
           cout<<DP[i]<<" ";
       }
       cout<<endl;
       for(int i=0;i<n;i++)
       {
           cout<<C[i]<<" ";
       }
       cout<<endl;*/
       return DP[n];
    }
};
