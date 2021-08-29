/* Leetcode 
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4

*/
// can be done in O(n^2) 
// Below is the O(nlogn) solution

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
bool comparator(const pip&a,const pip &b)
{
    if(a.first==b.first)
        return a.second.first<b.second.first;
    return a.first<b.first;
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pip> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(pip(endTime[i],pii(startTime[i],profit[i])));
        }
        vector<int> ans,temp;
        // temp will contain all endtimes in sorted order
        // ans will contain maximum profit upto a given endtime
        sort(v.begin(),v.end(),comparator);
        temp.push_back(v[0].first);
        ans.push_back(v[0].second.second); // push first profit
        for(int i=1;i<n;i++)
        {
            // search for start time upper bound -
            int st=v[i].second.first;
            auto it=upper_bound(temp.begin(),temp.end(),st);
            if(it==temp.begin())
            {
                // dont subtract - no job before this is possible
                int p=v[i].second.second;
                ans.push_back(max(p,ans[i-1]));
                temp.push_back(v[i].first);
            }
            else
            {
                it--;
                int p = ans[it-temp.begin()]+v[i].second.second;
                ans.push_back(max(p,ans[i-1]));
                temp.push_back(v[i].first);
            }
        }
        return ans[n-1];
    }
};
