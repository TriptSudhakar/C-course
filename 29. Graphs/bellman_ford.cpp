#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> bellman_ford(int v,int src,vector<vector<int>>&edges)
{
    // create a vector
    vector<int> dist(v+1,INT_MAX);
    dist[src] = 0;
    
    // relax all edges v-1 times
    for(int i=0;i<v-1;i++)
    {
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(auto edge:edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
        {
            cout<<"Negative weight cycle found\n";
            exit(0);
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> edges{{1,2,3},{2,3,4},{1,3,-10}};
    vector<int> distances = bellman_ford(3,1,edges);
    for(int i=1;i<=3;i++)
    {
        cout<<"Node "<<i<<" is at a distance of "<<distances[i]<<'\n';
    }
    return 0;
}