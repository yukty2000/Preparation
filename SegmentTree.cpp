#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
//segment tree
int rangeMinQueries(int *a,int *segTree,int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow>high||qhigh<low)//no overlap
    {
        return INT_MAX;
    }
    if(low>=qlow&&high<=qhigh)//total overlap
    {
        return segTree[pos];
    }
    int mid=(low+high)/2;
    return min(rangeMinQueries(a,segTree,qlow,qhigh,low,mid,2*pos+1),rangeMinQueries(a,segTree,qlow,qhigh,mid+1,high,2*pos+2));
}
void createTree(int *a,int *segTree,int low,int high,int pos)
{
    if(low==high)//leaf
    {
        segTree[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    createTree(a,segTree,low,mid,2*pos+1);
    createTree(a,segTree,mid+1,high,2*pos+2);
    segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    return;
}
int main()
{
    int n;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    int *a=new int[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int temp;
    if(ceil(log2(n))==floor(log2(n)))
        temp=n;
    else
        temp=pow(2,ceil(log2(n)));
    int *segTree=new int[2*temp-1];
    createTree(a,segTree,0,n-1,0);
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    cout<<rangeMinQueries(a,segTree,0,3,0,n-1,0)<<endl;
    cout<<rangeMinQueries(a,segTree,1,4,0,n-1,0)<<endl;
    return 0;
}
