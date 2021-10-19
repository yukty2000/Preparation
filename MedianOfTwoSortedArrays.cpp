/* Leetcode
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6

*/
class Solution {
public:
    int findAns(vector<int> arr,int low,int high,int el,int num,int k)
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
    int kthElement(vector<int> arr1, vector<int> arr2, int n, int m, int k)
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
    double median(vector<int> nums)
    {
        int n=nums.size();
        if(n%2!=0)
            return nums[n/2];
        else
            return (nums[n/2]+nums[n/2-1])/2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n==0)
            return median(nums2);
        if(m==0)
            return median(nums1);
        int total=(n+m);
        if(total%2!=0)
            return kthElement(nums1,nums2,n,m,total/2+1);
        else
            return (kthElement(nums1,nums2,n,m,total/2)+kthElement(nums1,nums2,n,m,(total/2)+1))/2.0;
    }
};
