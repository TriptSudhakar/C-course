#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int v;
    list<int>*l;
public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x,int y)
    {
        // directed graph
        l[x].push_back(y);
    }

    void topological_sort()
    {
        // indegree
        int *indegree = new int[v];
        for(int i=0;i<v;i++)
        {
            indegree[i] = 0;
        }

        // update the indegree by traversing edges x->y
        for(int i=0;i<v;i++)
        {
            for(auto x:l[i])
            {
                indegree[x]++;
            }
        }

        // BFS
        queue<int>q;
        // find nodes with indegree 0
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        // start removing elements from queue
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            // iterate over neighbours of that node and reduce their indegree
            for(auto nbr:l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }

        cout<<'\n';
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.topological_sort();
    return 0;
}