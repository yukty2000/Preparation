#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
int qpartition(int *a,int low,int high)
{
    int pivot=a[low];
    int i=high+1;
    for(int j=high;j>=low+1;j--)
    {
        if(a[j]>pivot)
        {
            i--;
            swap(a[i],a[j]);
        }
    }
    swap(a[i-1],a[low]);
    return i-1;
}
int partition_r(int *a,int low,int high)
{
    int el=high-low+1;
    int r=rand()%el;
    swap(a[low],a[low+r]);
    return qpartition(a,low,high);
}
void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int pi=partition_r(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
