/* GFG
Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1. Minimums of windows
of size 1 are {10}, {20}, {30}, {50},
{10}, {70} and {30}. Maximum of these
minimums is 70. 
Second element in output indicates
maximum of minimums of all windows of
size 2. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^6
*/

typedef pair<int,int> pii;
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        // histogram approach
        stack<pii> s;
        vector<pii> bound(n);
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
            else
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
        vector<int> win_size(n);
        for(int i=0;i<n;i++)
            win_size[i]=bound[i].second-bound[i].first;
        vector<int> ans(n,-1);
        int max_idx=-1;
        for(int i=0;i<n;i++)
        {
            int w=win_size[i];
            if(ans[w-1]==-1)
                ans[w-1]=arr[i];
            else
                ans[w-1]=max(ans[w-1],arr[i]);
            max_idx=max(max_idx,w-1);
        }
        for(int i=max_idx-1;i>=0;i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
        }
        for(int i=max_idx+1;i<n;i++)
        {
            ans[i]=max(ans[i],ans[i-1]);
        }
        return ans;
    }
    
};
