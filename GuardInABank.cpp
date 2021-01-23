/* GFG Tested - DSA Workshop Week 9

Given an M x N character matrix that is filled with the characters ‘O’, ‘G’, and ‘W’ where:

‘O’ represents an open space.
‘G’ represents a guards
‘W’ represents a wall.
You have to replace all of the O’s in the matrix with their shortest distance from a guard without being able to go through any walls. 
Also, replace the guards with 0 and walls with -1 in the resultant matrix. If no path exists replace 'O' with -1.

*/

// BFS Approach

// left,right,up,down
int r[]={0,0,-1,1};
int c[]={-1,1,0,0};
typedef pair<int,int> pii;
vector<vector<int>> findDistance(vector<vector<char>> &matrix, int M, int N)
{
    vector<vector<int>> ans(M,vector<int>(N,-2));   // -2 is for unvisited rows
    vector<vector<int>> visited(M,vector<int>(N,0));
    queue<pii> q;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(matrix[i][j]=='G')
            {
                q.push(make_pair(i,j));
                visited[i][j]=1;
                ans[i][j]=0;
            }
        }
    }
    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        int i=p.first,j=p.second;
        for(int k=0;k<4;k++)
        {
            int i_temp=i+r[k];
            int j_temp=j+c[k];
            if(i_temp>=0&&i_temp<M&&j_temp>=0&&j_temp<N&&visited[i_temp][j_temp]==0)
            {
                visited[i_temp][j_temp]=1;
                if(matrix[i_temp][j_temp]=='W')
                    ans[i_temp][j_temp]=-1;
                else
                {
                    ans[i_temp][j_temp]=ans[i][j]+1;
                    q.push(make_pair(i_temp,j_temp));
                }
            }
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(ans[i][j]==-2)
            {
                ans[i][j]=-1;
            }
        }
    }
    return ans;
    
}
