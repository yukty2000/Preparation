/* This program solves the staircase climbing problem-
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    
    We solve this problem using the dynamic programming approach . 
    For i = n-1 ; there is only 1 way to climb;
    For i = n-2 ; there are 2 ways to climb;
    For i = n-3 to 0 ; each value follows f(i) = f(i+1) + f(i+2)
    
    Time Complexity = O(n)  ;  Space Complexity = O(n)
    
    Input: n = 2
    Output: 2
    
    Input: n = 3
    Output: 3
    
    */

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
        if(n<=2)                                                //for n<=2 number of ways the stairs can be climbed = n ; as explained above.
            return n;
            
        int *ways=(int *)malloc(n*sizeof(int));
        arr[n-1]=1,arr[n-2]=2;
        
        for(int i=n-3;i>=0;i--)                                 // looping over i = n-3 to 0 and finding ways[i] = ways[i+1] + ways[i+2]
            ways[i]=ways[i+1]+ways[i+2];
            
        int ans=ways[0];
        
        free(ways);
        
        return ans;
     }
int main()                                                    // Driver function
{
      int n;                                                  // Taking input
      cin>>n;
      cout<<climbStairs(n)<<endl;
      return 0;
}
