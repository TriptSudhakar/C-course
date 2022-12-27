#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> floyd_warshall(vector<vector<int>>&graph)
{
    vector<vector<int>> dist(graph);
    int v = graph.size();
    // Phases, in the kth phase we include vertices (1,2,.......k) as intermediate vertices
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            if(i==k) continue;
            for(int j=0;j<v;j++)
            {
                if(j==k || j==i) continue;
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> graph = {
        {0,INT_MAX,-2,INT_MAX},
        {4,0,3,INT_MAX},
        {INT_MAX,INT_MAX,0,2},
        {INT_MAX,-1,INT_MAX,0}
    };
    auto result = floyd_warshall(graph);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result.size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}