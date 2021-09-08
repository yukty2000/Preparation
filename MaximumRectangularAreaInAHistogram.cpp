/* GFG 
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012

*/

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    typedef long long int lli;
    typedef pair<lli,int> pii;
    lli getMaxArea(lli arr[], int n)
    {
        // Your code here
        vector<pii> bound(n,pii(0,0));
        stack<pii> s;
        for(int i=0;i<n;i++)
        {
            // LHS is decided when element is pushed
            if(s.empty()||s.top().first<arr[i])
            {
                if(s.empty())
                    bound[i].first=-1;
                else
                    bound[i].first=s.top().second;
                s.push(pii(arr[i],i));
            }
            else //element is less than or equal to one on top
            {
                // RHS is decided when element is popped
                while(!s.empty()&&s.top().first>arr[i])
                {
                    bound[s.top().second].second=i-1;
                    s.pop();
                }
                if(s.empty())
                {
                    bound[i].first=-1;
                }
                else if(s.top().first==arr[i])
                {
                    bound[i].first=bound[s.top().second].first;
                }
                else
                {
                    bound[i].first=s.top().second;
                }
                s.push(pii(arr[i],i));
            }
        }
        while(!s.empty())
        {
            bound[s.top().second].second=n-1;
            s.pop();
        }
        lli ans=0;
        for(int i=0;i<n;i++)
        {
            lli b=bound[i].second-bound[i].first;
            ans = max(ans,b*arr[i]);
        }
        return ans;
    }
};
