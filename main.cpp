#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
//BIT or Fenwick Tree
int prefixSum(int *BIT,int qlow,int qhigh,int low,int high)
{
    int sum=BIT[qhigh+1];
    int x=qhigh+1;
    int parent=x-(x&(-x));
    while(parent>0)
    {
        sum+=BIT[parent];
        parent=parent-(parent&(-parent));
    }
    return sum;
}
void updateTree(int *a,int *BIT,int delta,int low,int high,int pos)
{
    int diff=delta-a[pos];
    a[pos]=delta;
    int x=pos+1;
    BIT[x]+=diff;
    int next=x+(x&(-x));
    while(next<=high+1)
    {
        BIT[next]+=diff;
        next=next+(next&(-next));
    }
    return;
}
void createTree(int *a,int *BIT,int low,int high)
{
    for(int i=low;i<=high;i++)
    {
        BIT[i+1]+=a[i];
        int x=i+1;
        int next=x+(x&(-x));
        //cout<<next<<endl;
        while(next<=high+1)
        {
            BIT[next]+=a[i];
            next=next+(next&(-next));
        }
    }
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
    int *BIT=new int[n+1];
    createTree(a,BIT,0,n-1);
    cout<<"Tree Created"<<endl;
    for(int i=0;i<=n;i++)
        cout<<BIT[i]<<" ";
    cout<<endl;
    cout<<prefixSum(BIT,0,2,0,10)<<endl;
    updateTree(a,BIT,7,0,10,6);
    for(int i=0;i<=n;i++)
        cout<<BIT[i]<<" ";
    cout<<endl;
    cout<<prefixSum(BIT,0,8,0,10)<<endl;
    return 0;
}
//3 2 -1 6 5 4 -3 3 7 2 3
