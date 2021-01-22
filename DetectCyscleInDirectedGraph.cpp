/* GFG Tested

Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not.

*/

//topological sort
class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
	   	int *indegree=(int *)calloc(V,sizeof(int));
	   	queue<int> q;
	   	for(int i=0;i<V;i++)
	   	{
	   	    for(auto it=adj[i].begin();it!=adj[i].end();it++)
	   	    {
	   	        indegree[*it]++;
	   	    }
	   	}
	   	/*for(int i=0;i<V;i++)
	   	    cout<<indegree[i]<<endl;*/
	   	int visited=0;
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(indegree[i]==0)
	   	    {
	   	        visited++;
	   	        q.push(i);
	   	    }
	   	}
	   	while(!q.empty())
	   	{
	   	    int temp=q.front();
	   	    q.pop();
	   	    for(auto it=adj[temp].begin();it!=adj[temp].end();it++)
	   	    {
	   	        indegree[*it]--;
	   	        if(indegree[*it]==0)
	   	        {
	   	            visited++;
	   	            q.push(*it);
	   	        }
	   	    }
	   	}
	   	if(visited==V)
	   	    return false;
	   	return true;
	}
};
