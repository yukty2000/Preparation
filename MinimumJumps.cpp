/* Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.
    You can assume that you can always reach the last index.
    
    Constraints:
    1 <= nums.length <= 3 * 10*4
    0 <= nums[i] <= 10^5
    
    We use the Dynamic Programming approach wherein we use an array dp of size=nums.size() to store the minimum number 
    of jumps required to reach the last index from position i in dp[i]. We also use segment tree approach to find the minimum
    number of jumps from position i+1 to i+nums[i] and add one to this value to find dp[i].
    
    Time complexity - O(nlogn)  ;   Space Complexity=0(n) 
      */
#include <bits/stdc++.h>
#define N 1000000
using namespace std;

void constructTree(int *segTree,int *input,int low,int high,int pos)                       // Function to construct segment Tree for provide input array
    {
        if(low==high)
        {
            segTree[pos]=input[low];
            return;
        }
        
        int mid=(low+high)/2;
        
        constructTree(segTree,input,low,mid,2*pos+1);
        constructTree(segTree,input,mid+1,high,2*pos+2);
        
        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
        
        return;
    }
    int queries(int *segTree,int low,int high,int qlow,int qhigh,int pos)                   // Function to return range minimum queries on the array
    {
        if(low>=qlow&&high<=qhigh)                                                          // total overlap
            return segTree[pos];
        
        if(qhigh<low||qlow>high)                                                            // no overlap
            return N;
        
        int mid=(low+high)/2;                                                               // partial overlap
        int left=queries(segTree,low,mid,qlow,qhigh,2*pos+1);
        int right=queries(segTree,mid+1,high,qlow,qhigh,2*pos+2);
        
        return min(left,right);
    }
    void update(int *segTree,int low,int high,int qlow,int qhigh,int pos,int new_val)
    {
        if(qhigh<low||qlow>high)                                                            // no overlap
            return ;
        
        if(low>=qlow&&high<=qhigh)                                                          // total overlap
        {
            segTree[pos]=new_val;
            return;
        }
                                                                                            // partial overlap
        int mid=(low+high)/2;
        update(segTree,low,mid,qlow,qhigh,2*pos+1,new_val);
        update(segTree,mid+1,high,qlow,qhigh,2*pos+2,new_val);
        
        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
        
        return;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int sitree=(2*pow(2,ceil(log2(n))))-1;                                              // sitree = size of the array that stored the segment tree
        
        int *dp=(int *)malloc(n*sizeof(int));
        
        int *segTree=(int *)malloc(sitree*sizeof(int));
        
        for(int i=0;i<n;i++){
            dp[i]=N;
        }
        
        for(int i=0;i<sitree;i++)
            segTree[i]=N;
        
        dp[n-1]=0;

        constructTree(segTree,dp,0,n-1,0);
        
        for(int i=n-2;i>=0;i--)
        {
            if(i+1<n&&nums[i]>=1)
            {
                dp[i]=1+queries(segTree,0,n-1,i+1,min(i+nums[i],n-1),0);                    
            }
            update(segTree,0,n-1,i,i,0,dp[i]);
        }
        
        int ans=dp[0];
        
        free(dp);
        free(segTree);
        
        return ans;
    }
int main()                                                                                  //Driver Function
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
    cout<<jump(nums)<<endl;
    return 0;
}
