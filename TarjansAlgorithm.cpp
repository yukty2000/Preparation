/* GFG 
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph. - Using Tarjans' Algorithm
*/

// Checked against multiedges, self loops, cross edges, etc.

typedef pair<int,int> pii;
class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void tarjansimp(int V,int &t,int i,vector<int> adj[],vector<vector<int>> &ans,vector<bool> &instack,stack<int> &s,vector<pii> &dis_low)
    {
        dis_low[i].first=dis_low[i].second=t++;
        instack[i]=true;
        s.push(i);
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            int v=*it;
            if(dis_low[v].first==-1) // not in stack and not visited - explore further
            {
                tarjansimp(V,t,v,adj,ans,instack,s,dis_low);
                dis_low[i].second=min(dis_low[i].second,dis_low[v].second);
            }
            else if(instack[v]) // if it is already in stack - back edge(don't explore again)
            {
                dis_low[i].second=min(dis_low[i].second,dis_low[v].first);
            }
        }
        if(dis_low[i].first==dis_low[i].second) // head of SCC subtree- pop till encountered
        {
            vector<int> temp;
            while(s.top()!=i)
            {
                temp.push_back(s.top());
                instack[s.top()]=false;
                s.pop();
            }
            temp.push_back(s.top());
            instack[s.top()]=false;
            s.pop();
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ;
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>> ans;
        vector<bool> instack(V,false);
        stack<int> s;
        vector<pii> dis_low(V,pii(-1,-1));
        int t=0;
        for(int i=0;i<V;i++)
        {
            if(dis_low[i].first==-1)
            {
                tarjansimp(V,t,i,adj,ans,instack,s,dis_low);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
