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
    void DFS(int *visited,int *explored,int *parent,int i)
    {

        explored[i]=1;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<endl;
            if(!visited[*it]&&!explored[*it])
            {
                cout<<"Tree edge-"<<i<<" "<<*it<<endl;
                parent[*it]=i;
                DFS(visited,explored,parent,*it);
            }
            else if(visited[*it]==1)
            {
                cout<<"Forward Edge-"<<i<<" "<<*it<<endl;
            }
            else if(explored[*it]==1&&*it!=parent[i])
            {
                cout<<"Back edge-"<<i<<" "<<*it<<endl;
            }
        }
        visited[i]=1;
    }
    void EdgeCheck()
    {
        int *visited=(int *)calloc(V,sizeof(int));
        int *explored=(int *)calloc(V,sizeof(int));
        int *parent=(int *)calloc(V,sizeof(int));
        for(int i=0;i<V;i++)
            parent[i]=-1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
                parent[i]=i;
               DFS(visited,explored,parent,i);
            }
        }
        free(visited);
        free(explored);
        free(parent);
        cout<<endl;
    }
};
