/* GFG
Given an input stream of n integers, find the kth largest element each time when an new element is added to the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1,2,3,4,5,6}
Output: -1 -1 -1 1 2 3
Explanation: k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1
{1, 2, 3, 4}
For 5, the 4th largest element is 2
{2, 3, 4 ,5}
For 6, the 4th largest element is 3
{3, 4, 5, 6}

Example 2:

Input:
k = 1, n = 2
arr[] = {3,4}
Output: 3 4 
Your Task:
You are required to complete the method kthLargest() which takes 3 arguments and prints kth largest element -1.

Constraints:
1 <= n <= 10^6
1 <= k <= n
1 <= arr[i] <= 10^5

Expected Time Complexity: O(n*Log(k))
Expected Auxiliary Space: O(k)

*/

class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
    	// your code here
    	priority_queue<int> min_heap,max_heap;
    	for(int i=0;i<k-1;i++)
    	{
    	    min_heap.push(-arr[i]);
    	    cout<<-1<<" ";
    	}
    	int kth;
        if(min_heap.empty())
        {
            kth=arr[k-1];
        }
        else if(-min_heap.top()<arr[k-1])
        {
            kth=-min_heap.top();
            min_heap.pop();
            min_heap.push(-arr[k-1]);
        }
        else
        {
            kth=arr[k-1];
        }
        cout<<kth<<" ";
    	for(int i=k;i<n;i++)
    	{
    	    if(arr[i]<=kth)
    	    {
    	        max_heap.push(arr[i]);
    	    }
    	    else 
    	    {
    	        max_heap.push(kth);
    	        if(min_heap.empty())
    	            kth=arr[i];
    	        else if(-min_heap.top()<arr[i])
    	        {
    	            kth=-min_heap.top();
    	            min_heap.pop();
    	            min_heap.push(-arr[i]);
    	        }
    	        else
    	        {
    	            kth=arr[i];
    	        }
    	        
    	    }
    	    cout<<kth<<" ";
    	}
    	return;
    }
};
