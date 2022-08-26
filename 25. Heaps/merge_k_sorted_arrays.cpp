#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
typedef list<int>::iterator lii;
typedef pair<lii, int> piit;
class compare
{
public:
    bool operator()(piit a,piit b)
    {
        return *(a.first)>*(b.first);
    }
};
list<int> mergesorted(vector<list<int>> &v,int k)
{ 
    vector<lii> it(k),end(k);
    for(int i=0;i<k;i++)
    {
        it[i] = v[i].begin();
        end[i] = v[i].end();
        // end[i]--;
    }

    list<int> result;
    priority_queue<piit,vector<piit>,compare> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({it[i],i});
        it[i]++;
    }
    while(!pq.empty())
    {
        piit least = pq.top();
        pq.pop();
        lii itl = least.first;
        int x = least.second;
        result.push_back(*itl);
        if(it[x]!=end[x])
        {
            pq.push({it[x],x});
            it[x]++;
        }
    }
    return result;
}
int main() {
    int k,n;
    cin>>k>>n;
    vector<list<int>> v(k);
    for(int i=0;i<k;i++)
    {
        list<int> l;
        int temp;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            l.push_back(temp);
        }
        v[i] = l;
    }
    list<int> output = mergesorted(v,k);
    for(int x:output) cout<<x<<' ';
}