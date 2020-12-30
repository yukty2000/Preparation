/* Leetcode - Subset Sum Variant
    Given a non-empty array nums containing only positive integers, 
    find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
    
    Input: nums = [1,5,11,5]
    Output: true
    
    Bottom up Dp approach with O(sum) auxillary space.
    */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        sum/=2;
        bool *Dp=(bool *)malloc((sum+1)*sizeof(bool));
        Dp[0]=true;
        for(int i=1;i<=sum;i++)
            Dp[i]=false;
        for(int i=0;i<n;i++)
        {
            for(int j=sum;j>=0&&j>=nums[i];j--)
            {
                Dp[j]=Dp[j] || Dp[j-nums[i]];
                if(j==sum&&Dp[j]==true)
                    break;
            }
        }
        bool ans=Dp[sum];
        free(Dp);
        return ans;
    }
};
    
