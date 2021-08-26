/* GFG
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
 
https://practice.geeksforgeeks.org/problems/articulation-point-1/1/?problemType=functional&page=4&sortBy=submissions&category[]=Graph&query=problemTypefunctionalpage4sortBysubmissionscategory[]Graph#

*/

// Using Tarjan's algorithm
typedef pair<int,int> pii;
class Solution {
  public:
    void findans(int V,int i,int t,vector<pii> &disc_low,vector<pii> &parent_child,vector<bool> &visited,set<int> &AP,vector<int> adj[])
    {
        disc_low[i].first=disc_low[i].second=t++;
        visited[i]=true;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            int v=*it;
            // check if it is parent
            if(v==parent_child[i].first)
                continue;
            // check if it is a backedge
            if(visited[v])
            {
                disc_low[i].second=min(disc_low[i].second,disc_low[v].first);
                continue;
            }
            // it is unexplored
            parent_child[v].first=i;
            findans(V,v,t,disc_low,parent_child,visited,AP,adj);
            parent_child[i].second++;
            disc_low[i].second=min(disc_low[i].second,disc_low[v].second);
            if(disc_low[i].first<=disc_low[v].second&&parent_child[i].first!=-1)
                AP.insert(i);
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        // only one root possible - as it is a connected graph
        vector<pii> disc_low(V,pii(-1,-1));
        vector<pii> parent_child(V,pii(-1,0));
        vector<bool> visited(V,false);
        int t=0;
        set<int> AP;
        findans(V,0,0,disc_low,parent_child,visited,AP,adj);
        if(parent_child[0].second>=2)
            AP.insert(0);
        vector<int> ans;
        for(auto it=AP.begin();it!=AP.end();it++)
            ans.push_back(*it);
        if(ans.size()==0)
            ans.push_back(-1);
        return ans;
    }
};
