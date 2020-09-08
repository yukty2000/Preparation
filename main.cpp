#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
int main()
{
    int n;
    cin>>n;
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int v=a[i];
        int j=i;
        while(j>0&&a[j-1]>v)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
