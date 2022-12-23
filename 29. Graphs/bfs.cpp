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

    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T,bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    // mark the nbr as visited
                    visited[nbr] = true;
                }
            }
        }
        cout<<'\n';
    }

    void sssp(T src)
    {
        map<T,int> dist;
        queue<T> q;

        // All the other will have INT_MAX
        for(auto node_pair:l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while(!q.empty())
        {
            T node = q.front();
            // cout<<node<<" ";
            q.pop();
            for(auto nbr:l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    // mark the nbr as visited
                    dist[nbr] = dist[node]+1;
                }
            }
        }

        for(auto node_pair:l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<<" Distance from source "<<d<<'\n';
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    g.sssp(0);
    return 0;
}