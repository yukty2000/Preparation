#include <bits/stdc++.h>
#define N 1000000007
#define M 1000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
class Edge
{
public:
    int src,dest;
    int weight;
};
class Graph
{
    int V,E;
    Edge *edge;
public:
    Graph(int v,int e)
    {
        V=v,
        E=e;
        edge=new Edge[E];
    }
    void addedge()
    {
        int temp=0;
        while(temp<E)
        {
            //printf("enter source-destination-weight\n");
            int s,d,w;
            cin>>s>>d>>w;
            edge[temp].src=s;
            edge[temp].dest=d;
            edge[temp].weight=w;
            temp++;
        }
    }
    void printarray(int *parent,int V)
    {
        for(int i=0;i<V;i++)
            printf("%d %d\n",i,parent[i]);
        return ;
    }
    void Bellman_ford()
    {
        int *dist=(int *)calloc(V,sizeof(int));
        for(int i=0;i<V;i++)
            dist[i]=INT_MAX;
        dist[0]=0;
        for(int i=1;i<=V-1;i++)
        {
            for(int j=0;j<E;j++)
            {
                if(dist[edge[j].dest]>dist[edge[j].src]+edge[j].weight)
                {
                    dist[edge[j].dest]=dist[edge[j].src]+edge[j].weight;
                }
            }
        }
        int swapped=0;
        for(int j=0;j<E;j++)
        {
            if(dist[edge[j].src]+edge[j].weight<dist[edge[j].dest])
            {
                dist[edge[j].dest]=dist[edge[j].src]+edge[j].weight;
                swapped++;
                break;
            }
        }
        if(swapped==1)
            cout<<"Graph contains negative weight cycle"<<endl;
        else
        {
            cout<<"Distance from source vertex"<<endl;
            printarray(dist,V);
        }
        free(dist);
    }
};
int main()
{
   Graph G(4,5);
   G.addedge();
   G.Bellman_ford();
    return 0;
}
/*
0 1 6
0 2 5
0 3 5
3 2 -2
2 1 -2
1 4 -1
2 4 1
3 5 -1
5 6 3
4 6 3
*/
/*
0 1 4
0 3 5
1 3 5
2 1 -10
3 2 3
*/
