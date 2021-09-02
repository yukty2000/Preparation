/* GFG 
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
Example 2:

Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= A[] <= 1

*/

typedef pair<int,int> pii;
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        // look at both sides
        vector<pii> v;
        map<pii,int> m;
        int zeros=0,ones=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==0)
                zeros++;
            else
                ones++;
            pii temp;
            if(zeros<=ones)
            {
                temp=pii(0,ones-zeros);
            }
            else
            {
                temp=pii(zeros-ones,0);
            }
            auto it=m.find(temp);
            if(it==m.end())
            {
                m.insert({temp,i});
            }
            else
            {
                it->second = i;
            }
            v.push_back(pii(zeros,ones));
        }
        /*for(int i=0;i<N;i++)
            cout<<v[i].first<<" "<<v[i].second<<endl;
        */
        int ans=0;
        zeros=0,ones=0;
        for(int i=0;i<N;i++)
        {
            //cout<<zeros<<" "<<ones<<endl;
            auto it=m.find(pii(zeros,ones));
            if(it!=m.end()&&it->second>i)
            {
                ans=max(ans,it->second-i+1);
            }
            zeros=v[i].first,ones=v[i].second;
            if(zeros<=ones)
            {
                ones-=zeros;
                zeros=0;
                
            }
            else
            {
                zeros-=ones;
                ones=0;
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};
