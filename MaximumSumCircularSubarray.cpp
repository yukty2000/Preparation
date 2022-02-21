/* Leetcode

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4

*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        if(ans<=0)
            return ans;
        int n=nums.size();
        vector<int> prefix(n,0);
        int p=0;
        // first traversal - for 0 to n-1
        int sum=0,tsum=0,str=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            p+=nums[i];
            prefix[i]=p;
            if(sum<0)
            {
                sum=0;
                str=i+1;
            }
            tsum=max(tsum,sum);
        }
        // second traversal - check all wrap arounds from position 1
        int prev=prefix[0];// maximum size prefix
        for(int i=1;i<n;i++)
        {
            tsum=max(tsum,prev+prefix[n-1]-prefix[i-1]);
            prev=max(prev,prefix[i]);
        }
        return tsum;
    }
};
