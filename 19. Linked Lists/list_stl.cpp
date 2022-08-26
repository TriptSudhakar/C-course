#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;

    // Init
    list<int> l1{1,2,3,10,8,5};
    // Different datatype
    list<string> l2{"apple","guava","mango","banana"};
    l2.push_back("pineapple");

    // sort
    l2.sort();

    // reverse
    l2.reverse();

    //pop_front
    cout<<l2.front()<<endl;
    l2.pop_front();

    // add to the front of the list
    l2.push_front("kiwi");
    cout<<l2.back()<<'\n';
    l2.pop_back();

    // Iterate over the list and print the data
    for(auto s:l2)
    {
        cout<<s<<"->";
    }
    cout<<'\n';

    l2.push_back("orange");
    l2.push_back("lemon");
    l2.push_back("guava");

    for(auto s:l2)
    {
        cout<<s<<"->";
    }
    cout<<'\n';

    //remove a fruit
    string f;
    cin>>f;
    l2.remove(f);

    for(auto s:l2)
    {
        cout<<s<<"->";
    }
    cout<<'\n';

    //erase one or more elements
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);
    for(auto s:l2)
    {
        cout<<s<<"->";
    }
    cout<<'\n';

    //we can insert elements in the list
    it = l2.begin();
    it++;
    l2.insert(it,"melon");
    for(auto s:l2)
    {
        cout<<s<<"->";
    }
    cout<<'\n';
    return 0;
}