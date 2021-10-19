/* GFG
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.


Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))


Constraints:
1 <= N, M <= 10^6
1 <= arr1i, arr2i < INT_MAX
1 <= K <= N+M
*/

int findAns(int arr[],int low,int high,int el,int num,int k)
    {
        int number=low+num;
        int x=k-number;
        int tlow=low,thigh=high;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==el)
            {
                break;
            } 
            else if(arr[mid]<el)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        int pos=arr[high]>el?(low+high)/2:high+1;
        //cout<<pos<<endl;
        // elements of arr occuring before el - pos-tlow
        if(pos-tlow>=x)
        {
            return arr[tlow+x-1];
        }
        else if(pos-tlow+1==x)
        {
            return el;
        }
        else
        {
            int num_left=x-(pos-tlow+1);
            return arr[pos+num_left-1];
        }
        
        
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low1=0,low2=0,high1=n-1,high2=m-1;
        int tlow1=low1,tlow2=low2;
        while(low1<high1&&low2<high2)
        {
            int mid1=(low1+high1)/2;
            int mid2=(low2+high2)/2;
            int number=(mid1-tlow1+1)+(mid2-tlow2+1); //number of elements present
            if(arr1[mid1]>=arr2[mid2])
            {
                
                if(k<=number)
                {
                    high1=mid1;
                }
                else
                {
                    low2=mid2+1;
                }
            }
            else
            {
                
                if(k<=number)
                {
                    high2=mid2;
                }
                else
                {
                    low1=mid1+1;
                }
            }
        }
       // cout<<low1<<" "<<high1<<" "<<low2<<" "<<high2<<endl;
        if(low1==high1)
        {
            return findAns(arr2,low2,high2,arr1[low1],low1,k);
        }
        return findAns(arr1,low1,high1,arr2[low2],low2,k);
    }





