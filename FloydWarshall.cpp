#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
int main()
{
    cout<<"Enter number of vertices\n";
    int n;
    cin>>n;
    int **arr=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            if(i==j)
                arr[i][j]=0;
            else
                arr[i][j]=N;
        }
    }
    cout<<"Enter number of edges\n";
    int e;
    cin>>e;
    while(e--)
    {
        int u,v,x;
        cin>>u>>v>>x;
        arr[u-1][v-1]=x;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
        //free(arr[i]);
    }
    //free(arr);
    return 0;
}
/*
Edge List-
1 2 3
1 4 7
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2
*/
