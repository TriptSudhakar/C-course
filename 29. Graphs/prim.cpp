#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
class Graph
{
    // Adjacency list
    vector<pii>*l;
    int v;

public:
    Graph(int n)
    {
        v = n;
        l = new vector<pii> [n];
    }

    void addEdge(int x,int y,int w)
    {
        l[x].push_back({w,y});
        l[y].push_back({w,x});
    }

    int prim_mst()
    {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        bool *visited = new bool[v]{0};
        int ans = 0;

        pq.push({0,0});
        while(!pq.empty())
        {
            // pick out the edge with minimum weight
            auto best = pq.top();
            pq.pop();

            int to = best.second;
            int weight = best.first;

            if(visited[to]) continue;

            ans += weight;
            visited[to] = true;

            for(auto x:l[to])
            {
                if(!visited[x.second]) pq.push(x);
            }
        }

        return ans;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.prim_mst()<<'\n';
    return 0;
}