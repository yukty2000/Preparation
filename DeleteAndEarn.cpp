/* Leetcode 
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            auto it=m.find(nums[i]);
            if(it==m.end())
                m.insert({nums[i],1});
            else
                it->second++;
        }
        int ms=m.size();
        if(ms==1)
            return nums[0]*n;
        auto it=m.rbegin();
        int a=(it->first*it->second);
        int prev=it->first;
        it++;
        int b=(it->first*it->second);
        if(it->first!=prev-1)
            b+=a;
        prev=it->first;
        it++;
        //cout<<a<<" "<<b<<endl;
        while(it!=m.rend())
        {
            //cout<<it->first<<endl;
            int pt=(it->first*it->second);
            if(it->first!=prev-1)
                pt+=max(a,b);
            else
                pt+=a;
            prev=it->first;
            a=max(a,b);
            b=pt;
           // cout<<a<<" "<<b<<endl;
            it++;
        }
        return max(a,b);
        
    }
};
