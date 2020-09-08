#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
//stable counting sort with negative elements
int main()
{
    int n;
    cin>>n;
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    int mi=*min_element(a,a+n);
    int ma=*max_element(a,a+n);
    int range=ma-mi+1;
    int *c=(int *)calloc(range,sizeof(int));
    int *output=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        c[a[i]-mi]++;
    for(int i=1;i<range;i++)
        c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[c[a[i]-mi]-1]=a[i];
        c[a[i]-mi]--;
    }
    for(int i=0;i<n;i++)
        a[i]=output[i];
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
