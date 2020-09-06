#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
int main()
{
    int n=5;
    int p[]={5,4,6,2,7};
    int m[5][5]={0};
    int s[5][5]={0};
    int mi,q,j;
    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;
            mi=N;
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<mi)
                {
                    mi=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=mi;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<m[1][n-1]<<endl;
    return 0;
}
