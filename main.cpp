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
    int swapped=1;
    for(int i=n-1;i>=0&&swapped;i--)
    {
        swapped=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                swapped=1;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
