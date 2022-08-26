#include<iostream>
#include<set>
using namespace std;
class person_compare
{
public:
    bool operator()(pair<string,int> p1, pair<string,int> p2)
    {
        return p2.second>p1.second;
    }
};
int main()
{
    pair<string,int> p1,p2,p3,p4;
    p1 = make_pair("B",100);
    p2 = make_pair("A",40);
    p3 = make_pair("C",120);
    p4 = make_pair("D",10);

    multiset<pair<string,int>,person_compare> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto p:m)
    {
        cout<<p.first<<" "<<p.second<<'\n';
    }
    return 0;
}