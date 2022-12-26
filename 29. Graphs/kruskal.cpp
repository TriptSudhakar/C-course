#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// DSU data structure
// Path compression + Union by rank
class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        // base case
        if(parent[i]==-1)
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    // Unite (union)
    void unite(int x,int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if(s1!=s2)
        {
            // Union by rank optimization
            if(rank[s1]<rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }

            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
class Graph
{
    vector<vector<int>> edgelist;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
    }

    void addEdge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y});
    }

    int kruskal_mst()
    {
        // Sort all the edges based upon the weight
        sort(edgelist.begin(),edgelist.end());

        // Initialize a DSU
        DSU s(v);

        int ans = 0;
        for(auto edge:edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take that edge in MST if it doesn't form a cycle
            if(s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans += w;
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
    cout<<g.kruskal_mst()<<'\n';
    return 0;
}