#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
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
    }

    void dfs_helper(T src,map<T,bool>&visited,list<T>&ordering)
    {
        visited[src] = true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                dfs_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
    }

    void top_sort()
    {
        map<T,bool> visited;
        list<T> ordering;

        for(auto p:l)
        {
            visited[p.first] = false;
        }

        for(auto p:l)
        {
            auto src = p.first;
            if(!visited[src])
            {
                dfs_helper(src,visited,ordering);
            }
        }

        for(auto node:ordering)
        {
            cout<<node<<" ";
        }
        cout<<'\n';
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Python","DataPreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecognition");
    g.addEdge("Dataset","FaceRecognition");
    g.top_sort();
    return 0;
}