#include<iostream>
#include<list>
using namespace std;
// Cycle detection in an undirected graph using DSU
class Graph
{
    int v;
    list<pair<int,int>>l;

public:
    Graph(int v)
    {
        this->v = v;
    }

    int addEdge(int u,int v)
    {
        l.push_back({u,v});
    }

    // find
    int findSet(int i,int parent[])
    {
        // base case
        if(parent[i]==-1)
        {
            return i;
        }
        // return findSet(parent[i],parent);

        // Path compression optimization
        return parent[i] = findSet(parent[i],parent);
    }
    
    // union
    void union_set(int x,int y,int parent[],int rank[])
    {
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);

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

    bool contains_cycle()
    {
        // DSU logic to check if graph contains a cycle or not
        int *parent = new int[v+1];
        int *rank = new int[v+1];
        for(int i=0;i<v+1;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        // Iterate over the edge list
        for(auto  edge:l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i,parent);
            int s2 = findSet(j,parent);

            if(s1!=s2) union_set(s1,s2,parent,rank);
            else return true;
        }
        delete [] parent;
        delete [ ] rank;
        return false;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(1,4);
    g.addEdge(2,4);
    if(g.contains_cycle()) cout<<"Contains a cycle\n";
    else cout<<"No cycle\n";
    return 0;
}