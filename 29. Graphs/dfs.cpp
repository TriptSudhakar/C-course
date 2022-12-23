#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<T>> l;
public:
    Graph (){}

    void addEdge(T x,T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool>&visited)
    {
        cout<<src<<" ";
        visited[src] = true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                dfs_helper(nbr,visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;

        for(auto p:l)
        {
            visited[p.first] = false;
        }
        dfs_helper(src,visited);
        cout<<'\n';
    }

    int connected_components()
    {
        map<T,bool> visited;

        for(auto p:l)
        {
            visited[p.first] = false;
        }
        int cc = 0;

        for(auto p:l)
        {
            auto src = p.first;
            if(!visited[src])
            {
                cc++;
                cout<<"Component "<<cc<<" : ";
                dfs_helper(src,visited);
                cout<<'\n';
            }
        }
        return cc;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
    cout<<g.connected_components();
    return 0;
}