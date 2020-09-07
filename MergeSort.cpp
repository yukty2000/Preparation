#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
void mergea(int *a,int l,int mid,int h)
{
    //cout<<"Merging"<<endl;
    int l1=mid-l+1;
    int l2=h-mid;
    int L[l1],H[l2];
    for(int i=0;i<l1;i++)
        L[i]=a[l+i];
    for(int i=0;i<l2;i++)
        H[i]=a[mid+1+i];
    int ptr1=0,ptr2=0,i=l;
    while(ptr1<l1&&ptr2<l2)
    {
        if(L[ptr1]<=H[ptr2])
        {
            a[i]=L[ptr1];
            ptr1++;
        }
        else
        {
            a[i]=H[ptr2];
            ptr2++;
        }
        i++;
    }
    while(ptr1<l1)
    {
        a[i]=L[ptr1];
        ptr1++;
        i++;
    }
    while(ptr2<l2)
    {
        a[i]=H[ptr2];
        ptr2++;
        i++;
    }

}
void mergesort(int *a,int l,int h)
{
    //cout<<l<<" "<<h<<endl;
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        mergea(a,l,mid,h);
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int *a=(int *)malloc(n*sizeof(int));
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //cout<<"elements"<<endl;
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
