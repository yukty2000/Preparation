/*
GFG

Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

Input: arr[] = {8, 4, 2, 1}
Output: 6

Input: arr[] = {3, 1, 2}
Output: 2
*/

#include <bits/stdc++.h>
#define N 10001
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
//inversion count
int inv=0;
void Merge(int low,int mid,int high,int *arr)
{
    int n=mid-low+1;
    int m=high-mid;
    int *l=new int[n];
    int *r=new int[m];
    int c=0;
    for(int i=low;i<=mid;i++)
        l[c++]=arr[i];
    c=0;
    for(int i=mid+1;i<=high;i++)
        r[c++]=arr[i];
    c=low;
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(l[i]<=r[j])
        {
            arr[c++]=l[i++];
        }
        else
        {
            arr[c++]=r[j++];
            inv+=(n-i);
        }
    }
    while(i<n)
    {
       arr[c++]=l[i++];
    }
    while(j<m)
    {
        arr[c++]=r[j++];
    }
    delete[] l;
    delete[] r;
}
void MergeSort(int low,int high,int *arr)
{
    if(low<high)
    {
        int mid=(low+high-1)/2;
        MergeSort(low,mid,arr);
        MergeSort(mid+1,high,arr);
        Merge(low,mid,high,arr);
        //printf("Low- %d , Mid- %d , High- %d , Inv- %d\n",low,mid,high,inv);
    }
}

int main()
{
    int n;
    cin>>n;
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    MergeSort(0,n-1,arr);
    cout<<inv<<endl;
    return 0;
}
/*
8
1 20 6 7 5 8 11 3
*/
