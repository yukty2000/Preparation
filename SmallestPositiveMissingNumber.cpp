/* GFG
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^6
-10^6 <= arr[i] <= 10^6
*/

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=0||arr[i]>n)
                continue;
            else
            {
                int t=arr[i]-1;
                while(t>=0)
                {
                    int temp=arr[t];
                    arr[t]=INT_MIN;
                    if(temp<=0||temp>n)
                        break;
                    t=temp-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=INT_MIN)
                return i+1;
        }
        return n+1;
    } 
};
