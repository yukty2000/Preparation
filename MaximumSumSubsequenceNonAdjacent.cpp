/*  Given a list of non-negative integers arr, find out the maximum sum subsequence consisting of non-adjacent elements.
    We are required to return the sum.
    
    We use dynamic programming to solve the given problem.
    We use two variables - max_val1 and max_val2 such that 
      arr[i]+max_val1 is the  maximum sum subsequence consisting of non-adjacent elements starting at position i.
      And , max_val2 is the  maximum sum subsequence consisting of non-adjacent elements starting at position i+1 or greater.
      
      Time complexity  = O(n)  ;   Space Complexity = O(1)
      
      Input: nums = [1,2,3,1]
      Output: 4
      
      Input: nums = [2,7,9,3,1]
      Output: 12
      
      */
      
#include <bits/stdc++.h>
using namespace std;

int MaxSumSeqNonAdjacent(vector<int>& nums) {
        int n=nums.size();  
        
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
            
        int max_value1=nums[n-1],max_value2=nums[n-2];
        
        for(int i=n-3;i>=0;i--)
        {
            int curr=nums[i]+max_value1;                              // curr is the maximum sum of the non-adjacent subsequence staring at position i;
            max_value1=max(max_value1,max_value2);                    // max_value1 is updated accordingly
            max_value2=curr;                                          // max_value2 is updated accordingly
        }
        
        max_value1=max(max_value1,max_value2);                        //final answer is the maximum of max_value1 and max_value2
        
        return max_value1;
    }
    
int main()                                                    // Driver function
{
      int n;                                                  // Taking input
      cin>>n;
      vector<int> nums;
      
      for(int i=0;i<n;i++)
      {
        int x;
        cin>>x;
        nums.push_back(x);
      }
      
      cout<<MaxSumSeqNonAdjacent(nums)<<endl;
      return 0;
}
