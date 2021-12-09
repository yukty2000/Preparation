/* Leetcode
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/

// O(N) solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0)
        {
            if(nums[i]<nums[i+1])
                break;
            i--;
        }
        if(i<0)
        {
            int low=i+1,high=n-1;
            for(int j=low;j<low+(high-low+1)/2;j++)
            {
                swap(nums[j],nums[n-1-(j-low)]);
            }
            return;
        }
        // find second largest and swap
        int j=n-1;
        for(;j>=i+1;j--)
        {
            if(nums[j]>nums[i])
                break;
        }
        swap(nums[i],nums[j]);
        int low=i+1,high=n-1;
        for(j=low;j<low+(high-low+1)/2;j++)
        {
            swap(nums[j],nums[n-1-(j-low)]);
        }
        return;
    }
};
