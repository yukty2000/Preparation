/*  GFG Tested

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not

*/

//using dfs
class Solution {
public:
    void DFS(int *visited,vector<int> adj[],int i,int *parent,bool &ans)
    {
        visited[i]=1;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(visited[*it]!=1)
            {
                parent[*it]=i;
                DFS(visited,adj,*it,parent,ans);
            }
            else
            {
                if(parent[i]!=*it)
                {
                    ans=true;
                    return;
                }
            }
        }
    }
	bool isCycle(int V, vector<int>adj[]){
	    int *parent=(int *)malloc(V*sizeof(int));
	    int *visited=(int *)malloc(V*sizeof(int));
	    for(int i=0;i<V;i++)
	    {
	        parent[i]=-1;
	        visited[i]=0;
	    }
	    bool ans=false;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            DFS(visited,adj,i,parent,ans);
	        }
	        if(ans==true)
	            break;
	    }
	    free(visited);
	    free(parent);
	    return ans;
	}
};
