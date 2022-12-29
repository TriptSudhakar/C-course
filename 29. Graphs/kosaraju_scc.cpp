#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void dfs(vector<int>* graph,int i,bool *visited,vector<int>&stack)
{
    visited[i] = true;
    for(auto nbr:graph[i])
    {
        if(!visited[nbr]) dfs(graph,nbr,visited,stack);
    }
    // function call is complete
    stack.push_back(i);
}
void dfs_reverse(vector<int>* rev_graph,int i,bool *visited)
{
    visited[i] = true;
    cout<<i<<" ";
    for(auto nbr:rev_graph[i])
    {
        if(!visited[nbr]) dfs_reverse(rev_graph,nbr,visited);
    }
}
void solve(vector<int> graph[],vector<int> rev_graph[],int n)
{
    bool visited[100];
    memset(visited,0,n);
    
    vector<int> stack;
    
    // Store the vertices according to dfs finish time
    for(int i=0;i<n;i++)
    {
        if(!visited[i]) dfs(graph,i,visited,stack);
    }
    //ordering  = stack
    // reverse the graph

    // DFS based on the ordering given in the stack
    memset(visited,0,n);
    char component_name = 'A';
    for(int i = stack.size()-1;i>=0;i--)
    {
        int node = stack[i];
        if(!visited[node])
        {
            // there is a component starting from this node
            cout<<"Component "<<component_name<<" --> ";
            dfs_reverse(rev_graph,node,visited);
            cout<<'\n';
            component_name++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> graph[10000];
    vector<int>rev_graph[10000];

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    solve(graph,rev_graph,n);
    // Input
    // 7 8
    // 2 1
    // 1 0
    // 0 2
    // 0 3
    // 3 5
    // 5 6
    // 6 3
    // 3 4
    // Output
    // Component A --> 0 1 2 
    // Component B --> 3 6 5 
    // Component C --> 4 
    return 0;
}