/* GFG 
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 10^6
1 <= x <= 10^6
*/

class Solution  {
  public:
    //Function to insert heap.
    priority_queue<int> min_heap,max_heap;
    int s,mid;
    Solution()
    {
        s=0;
        mid=-1;
    }
    void insertHeap(int &x)
    {
        s++;
        if(mid==-1)
        {
            mid=x;
            return;
        }
        if(x>mid)
        {
            // insert in min heap
            min_heap.push(-x);
        }
        else
        {
            // insert in max heap
            max_heap.push(x);
        }
        balanceHeaps();
        return;
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(s%2!=0)  // odd-then both heaps should have equal number of elements
        {
            if(min_heap.size()==max_heap.size())
                return;
            else if(min_heap.size()<max_heap.size())
            {
                min_heap.push(-mid);
                mid=max_heap.top();
                max_heap.pop();
            }
            else
            {
                max_heap.push(mid);
                mid=-min_heap.top();
                min_heap.pop();
            }
        }
        else    // even-max_heap.size=min_heap.size+1
        {
            if(min_heap.size()+1==max_heap.size())
                return;
            else if(min_heap.size()+1>max_heap.size())
            {
                max_heap.push(mid);
                mid=-min_heap.top();
                min_heap.pop();
            }
            else
            {
                min_heap.push(-mid);
                mid=max_heap.top();
                max_heap.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(s%2!=0)
            return mid;
        else // it is even
        {
            int el1=max_heap.top();
            return (mid+el1)/2.0;
        }
    }
};
