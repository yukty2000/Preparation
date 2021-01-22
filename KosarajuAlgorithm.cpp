/* GFG Tested

Given a Directed Graph with V vertices and E edges, Find the number of strongly connected components in the graph.

*/
class Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void DFS(stack<int> &ans,vector<int> adj[],int i,int *visited)
    {
        visited[i]=1;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(!visited[*it])
            {
                DFS(ans,adj,*it,visited);
            }
        }
        ans.push(i);
    }
    void DFSutil(vector<int> adj[],int i,int *visited)
    {
        visited[i]=1;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(!visited[*it])
            {
                DFSutil(adj,*it,visited);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        stack<int> finish;
        int *visited=(int *)calloc(V,sizeof(int));
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(finish,adj,i,visited);
            }
        }
        vector<int> *adj_t=new vector<int>[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto it=adj[i].begin();it!=adj[i].end();it++)
            {
                adj_t[*it].push_back(i);
            }
        }
        int c=0;
        while(!finish.empty())
        {
            int val=finish.top();
            finish.pop();
            if(!visited[val])
            {
                DFSutil(adj_t,val,visited);
                c++;
            }
        }
        free(visited);
        delete[] adj_t;
        return c;
    }
};
