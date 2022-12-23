#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
#define psi pair<string,int>
using namespace std;
class Graph
{
    //Adjacency list
    unordered_map<string,list<psi>> l;
public:
    void addEdge(string x,string y,bool bidir,int wt)
    {
        l[x].push_back({y,wt});
        if(bidir) l[y].push_back({x,wt});
    }

    void printAdjList()
    {
        //Iterate over all the keys in the map
        for(auto p:l)
        {
            auto v = p.first;
            auto nbrs = p.second;

            cout<<"Vertex "<<v<<" : ";
            for(auto nbr:nbrs)
            {
                cout<<nbr.first<<"-"<<nbr.second<<", ";
            }
            cout<<'\n';
        }
    }
};
int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();
    return 0;
}