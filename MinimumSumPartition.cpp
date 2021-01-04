/*
GFG-Minimum sum partition
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the 
absolute difference between their sums is minimum and find the minimum difference

Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1

Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3

Extension of subset sum problem-
*/

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    sort(arr,arr+n);
	    int sum=0;
	    sum=accumulate(arr,arr+n,sum);
	    int temp=sum;
	    sum=(sum+1)/2;
	    bool **Dp=(bool **)malloc((n+1)*sizeof(bool *));
	    for(int i=0;i<=n;i++)
	        Dp[i]=(bool *)malloc((sum+1)*sizeof(bool));
	   for(int i=0;i<=n;i++)
	        Dp[i][0]=true;
	   for(int i=1;i<=sum;i++)
	        Dp[0][i]=false;
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=sum;j++)
	       {
	           if(j<arr[i-1])
	                Dp[i][j]=Dp[i-1][j];
	           else
	           {
	               Dp[i][j]=Dp[i-1][j]||Dp[i-1][j-arr[i-1]];
	           }
	       }
	   }
	   int ans=0;
	   for(int i=sum;i>=0;i--)
	   {
	       if(Dp[n][i])
	       {
	            ans=i;
	            break;
	       }
	   }
	   for(int i=0;i<=n;i++)
	        free(Dp[i]);
	   free(Dp);
	   return abs(ans-(temp-ans));
	} 
};
