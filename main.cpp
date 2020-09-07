#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
void heapify(int i,int *a,int n)
{
    int maximum=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n&&a[l]>a[maximum])
        maximum=l;
    if(r<n&&a[r]>a[maximum])
        maximum=r;
    if(maximum!=i)
    {
        swap(a[i],a[maximum]);
        heapify(maximum,a,n);
    }
    return ;
}
void buildheap(int *a,int n)
{
    for(int i=n/2+1;i>=0;i--)
        heapify(i,a,n);
}
int main()
{
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int *a=(int *)malloc(n*sizeof(int));
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"The sorted elements are\n";
    for(int i=n-1;i>=0;i--)
    {
        buildheap(a,i+1);
        //cout<<a[0]<<endl;
        swap(a[0],a[i]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    free(a);
    return 0;
}
