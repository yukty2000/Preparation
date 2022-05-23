/* Leetcode

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

*/

typedef pair<int,int> pii;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        int rows=(m+1)*(n+1);
        vector<vector<int>> DP(rows,vector<int>(s+1,0));
        vector<pii> v;
        for(int i=0;i<strs.size();i++)
        {
            int l=strs[i].length();
            int z=0,o=0;
            for(int j=0;j<l;j++)
            {
                if(strs[i][j]=='0')
                    z++;
                else
                    o++;
            }
            v.push_back(pii(z,o));
        }
        // start from 1st row, 1st column
        int z=0,o=1;
        int ch=0;
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<=s;j++)
            {
                //cout<<z<<" "<<o<<endl;
                //without taking jth element
                DP[i][j]=DP[i][j-1];
                if(o!=0)
                    DP[i][j]=max(DP[i][j],DP[i-1][j]);
                // taking jth element
                if(v[j-1].first>z||v[j-1].second>o)
                    continue;
                int ones=o-v[j-1].second;
                int zeroes=z-v[j-1].first;
                int rownum=(zeroes*(n+1))+ones;
                DP[i][j]=max(DP[i][j],1+DP[rownum][j-1]);
               /* if(DP[i][j]==2&&ch==0)
                {
                    ch=1;
                    cout<<z<<" "<<o<<endl;
                    cout<<zeroes<<" "<<ones<<endl;
                }*/
            }
            o++;
            if(o>n)
            {
                z++;
                o=0;
            }
        }
        /*int x=1;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<=s;j++)
            {
                cout<<DP[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<rows<<endl;*/
        return DP[rows-1][s];
    }
};
