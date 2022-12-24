#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>>> m;
public:
    Graph(){}

    void addEdge(T u,T v,int dist,bool bidir = true)
    {
        m[u].push_back({v,dist});
        if(bidir) m[v].push_back({u,dist});
    }

    void printAdj()
    {
        for(auto p:m)
        {
            cout<<p.first<<"->";
            for(auto x:p.second)
            {
                cout<<" ("<<x.first<<","<<x.second<<"),";
            }
            cout<<'\n';
        }
    }

    void dijkstraSSSP(T src)
    {
        unordered_map<T,int> dist;

        // set all distances to infinity
        for(auto j:m)
        {
            dist[j.first] = INT_MAX;
        }

        // Make a set to find a node with minimum distance
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert({0,src});

        while(!s.empty())
        {
            // find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int d = p.first;
            s.erase(s.begin());

            //Iterate over the neighbours of the current node 
            for(auto cp : m[node])
            {
                if(d+cp.second<dist[cp.first])
                {
                    // In set updation of a particular node is not possible
                    // So we have to remove the old pair and insert the new pair to simulate updation
                    auto f = s.find({dist[cp.first],cp.first});
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    // Insert the new node
                    dist[cp.first] = d+cp.second;
                    s.insert({dist[cp.first],cp.first});
                }
            }
        }

        for(auto p:dist)
        {
            cout<<p.first<<" "<<p.second<<'\n';
        }
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Delhi","Jaipur",2);
    g.addEdge("Mumbai","Jaipur",8);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Bhopal","Mumbai",3);
    g.addEdge("Agra","Delhi",1);
    // g.printAdj();
    g.dijkstraSSSP("Amritsar");
    return 0;
}