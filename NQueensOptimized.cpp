#include <bits/stdc++.h>
#define N 1000000009
#define M 1000000
using namespace std;
typedef pair<int,int> pii;
typedef long long int lli;
//N queen problem
void printsolution(int **board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isNQsolve(int **board,int *ld,int *rd,int *ca,int row,int n)
{
    if(row>=n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(ld[row-i+n-1]!=1&&rd[row+i]!=1&&ca[i]!=1)
        {
            board[row][i]=1;
            ld[row-i+n-1]=1;
            rd[row+i]=1;
            ca[i]=1;
            if(isNQsolve(board,ld,rd,ca,row+1,n))
                return true;
            board[row][i]=0;//backtracking
            ld[row-i+n-1]=0;
            rd[row+i]=0;
            ca[i]=0;
        }
    }
    return false;
}
int main()
{
    cout<<"Enter value of N"<<endl;
    int n;
    cin>>n;
    int **board=(int **)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        board[i]=(int *)calloc(n,sizeof(int));
    int *ca=(int *)calloc(n,sizeof(int));
    int *ld=(int *)calloc((2*n)-1,sizeof(int));
    int *rd=(int *)calloc((2*n)-1,sizeof(int));
    if(isNQsolve(board,ld,rd,ca,0,n)==false)
        cout<<"No solution exists"<<endl;
    else
        printsolution(board,n);
    return 0;
}
