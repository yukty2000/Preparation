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
        adj[v].push_back(u);
    }
    bool Bipartite()
    {
        int *visited=(int *)calloc(V,sizeof(int));
        int *colour=(int *)malloc(V*sizeof(int));
        for(int i=0;i<V;i++)
            colour[i]=-1;
        int c=0,sw=0;
        queue<int> q;
        q.push(0);
        colour[0]=0;
        visited[0]=1;
        while(!q.empty())
        {
            int temp=q.front();
            //visited[temp]=1;
            sw=1-colour[temp];
            q.pop();
            for(auto it=adj[temp].begin();it!=adj[temp].end();it++)
            {
                if(!visited[*it])
                {
                    colour[*it]=sw;
                    visited[*it]=1;
                    q.push(*it);
                }
                else
                {
                    if(colour[*it]==colour[temp])
                    {
                        cout<<*it<<" "<<temp<<endl;
                        c=1;
                        break;
                    }
                }
            }
            for(int i=0;i<V;i++)
                cout<<colour[i]<<" ";
            cout<<endl;
            cout<<sw<<endl;
        }
        if(c==1){cout<<"Condn 1"<<endl;
            return false;}
        return true;
    }
};
