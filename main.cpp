#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
//Sparse Table
int rangeMinQueries(int *a,int **sparse,int n,int low,int high)
{
    int l=high-low+1;
    int k=floor(log2(l));
    int val1,val2;
    val1=val2=INT_MAX;
    val1=sparse[low][k];
    int left=l-(int)pow(2,k);
    if(left==0)
        return a[val1];
    val2=sparse[low+left][k];
    return min(a[val1],a[val2]);
}
void createTree(int *a,int **sparse,int n)
{
    int temp=floor(log2(n))+1;
    for(int i=0;i<n;i++)
        sparse[i][0]=i;
    for(int i=1;i<temp;i++)
    {
        int j=0;
        int temp=(int)pow(2,i-1);
        while(j+temp<n)
        {
            int val;
            if(a[sparse[j][i-1]]<a[sparse[j+temp][i-1]])
            {
                val=sparse[j][i-1];
            }
            else
            {
                val=sparse[j+temp][i-1];
            }
            sparse[j][i]=val;
            j++;
        }
    }
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
    int col=floor(log2(n))+1;
    int **sparse=(int **)calloc(n,sizeof(int *));
    for(int i=0;i<n;i++)
        sparse[i]=(int *)calloc(col,sizeof(int));
    createTree(a,sparse,n);
    cout<<"Spare table"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Queries"<<endl;
    cout<<rangeMinQueries(a,sparse,n,3,5)<<endl;
    cout<<rangeMinQueries(a,sparse,n,0,5)<<endl;
    cout<<rangeMinQueries(a,sparse,n,0,3)<<endl;
    return 0;
}
//4 6 1 5 7 3
