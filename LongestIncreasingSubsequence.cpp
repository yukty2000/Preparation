/* Given an integer array nums, return the length of the longest strictly increasing subsequence.

  A subsequence is a sequence that can be derived from an array by deleting some or no elements 
  without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
  
  Below, I have provided two solutions to the problem - O(n^2) and O(nlogn) approach.
    */

#include <bits/stdc++.h>
using namespace std;

int LISn2(vector<int>& nums) {                                              // O(n^2) approach
        int n=nums.size();
        int *dp=(int *)malloc(n*sizeof(int));
        
        for(int i=0;i<n;i++)
            dp[i]=1;
            
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])                                         // dp[i] stores the length of the longest increasing subsequence upto and including position i 
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }
        
        int ans=*max_element(dp,dp+n);
        free(dp);
        
        return ans;
    }
    
int LISnlogn(vector<int>& nums)                                             // O(nlogn) approach
{
   int n=nums.size();
   vector<int> dp;
   dp.push_back(nums[0]);
   
   for(int i=1;i<n;i++)
   {
       auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
       
       if(it==dp.end())
            dp.push_back(nums[i]);                                        // dp[i] stores the last element of the longest increasing subsequence with length i+1
        else
        {
            int pos=it-dp.begin();
            if(dp[pos]!=nums[i])
                dp[pos]=nums[i];
        }
   }
   
   return dp.size();
}

int main()                                                              // driver function
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<LISnlogn(nums)<<endl;
    cout<<LISn2(nums)<<endl;
    
    return 0;
}
