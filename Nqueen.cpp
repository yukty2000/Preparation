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
bool isSafe(int **board,int row,int column,int n)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][column]==1)
            return false;
    }
    for(int i=row,j=column;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(int i=row,j=column;i<n&&j>=0;i++,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}
bool isNQsolve(int **board,int row,int n)
{
    if(row>=n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,row,i,n))
        {
            board[row][i]=1;
            if(isNQsolve(board,row+1,n))
                return true;
            board[row][i]=0;//backtracking
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
    if(isNQsolve(board,0,n)==false)
        cout<<"No solution exists"<<endl;
    else
        printsolution(board,n);
    return 0;
}
