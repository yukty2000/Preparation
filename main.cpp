#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
//BFS
class Graph
{
    int V,E;
    list<int> *adj;
public:
    Graph(int v,int e)
    {
        V=v,
        E=e;
        adj=new list<int>[V];
    }
    void addedge(int u,int v)
    {
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    void DFS(int *visited,int i,stack<int> &s)
    {

        visited[i]=1;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            //cout<<*it<<endl;
            if(!visited[*it])
            {
                DFS(visited,*it,s);
            }
        }
        s.push(i);
    }
    void DFS1(int *visited,int i)
    {
        visited[i]=1;
        cout<<i<<" ";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            //cout<<*it<<endl;
            if(!visited[*it])
            {
                DFS1(visited,*it);
            }
        }
    }
    stack<int> DFStraversal()
    {
        int *visited=(int *)calloc(V,sizeof(int));
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
               DFS(visited,i,s);
            }
        }
        free(visited);
        return s;
    }
    Graph transpose()
    {
        Graph Gt(this->V,this->E);
        for(int i=0;i<this->V;i++)
        {
            for(auto it=this->adj[i].begin();it!=this->adj[i].end();it++)
                Gt.adj[*it].push_back(i);
        }
        return Gt;
    }
    void Kosaraju()
    {
        stack<int> s=DFStraversal();
        Graph g=transpose();
        int *visited=(int *)calloc(V,sizeof(int));
        cout<<"Strongly Connected Components"<<endl;
        while(!s.empty())
        {
            int temp=s.top();
            s.pop();
            if(!visited[temp])
            {
                g.DFS1(visited,temp);
                cout<<endl;
            }
        }
    }
};
int main()
{
    Graph G(9,10);
    G.addedge(0,1);
    G.addedge(1,2);
    G.addedge(2,3);
    G.addedge(3,0);
    G.addedge(2,4);
    G.addedge(4,5);
    G.addedge(5,6);
    G.addedge(6,4);
    G.addedge(7,6);
    G.addedge(7,8);
    G.Kosaraju();
    return 0;
}
