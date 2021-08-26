/* GFG 
Given an undirected Connected graph of V vertices and E edges.
A critical connection is an edge that, if removed, will make some nodes unable to reach some other nodes. Find all critical connections in the graph.
Note: There are many possible orders for the answer. You are supposed to print the edges in sorted order, and also an edge should be in sorted order too.
So if there's an edge between node 1 and 2, you should print it like (1,2) and not (2,1).

*/

// Based on Tarjan's Algorithm
typedef pair<int,int> pii;
class Solution {
public:
    void findans(int V,int t,int i,vector<vector<int>> &ans,vector<pii> &disc_low,vector<int> &parent,vector<bool> &visited,vector<int> adj[])
    {
        disc_low[i].first=disc_low[i].second=t++;
        visited[i]=true;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            int v=*it;
            // check if it is parent vertex
            if(v==parent[i])
                continue;
            // check if it is a backedge
            if(visited[v])
            {
                disc_low[i].second=min(disc_low[i].second,disc_low[v].first);
                continue;
            }
            // it is unexplored
            parent[v]=i;
            findans(V,t,v,ans,disc_low,parent,visited,adj);
            disc_low[i].second=min(disc_low[i].second,disc_low[v].second);
            if(disc_low[i].first<disc_low[v].second)
            {
                vector<int> a={min(i,v),max(i,v)};
                ans.push_back(a);
            }
        }
        return;
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    vector<pii> disc_low(V,pii(-1,-1));
	    vector<int> parent(V,-1);
	    vector<bool> visited(V,false);
	    int t=0;
	    findans(V,t,0,ans,disc_low,parent,visited,adj);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};
