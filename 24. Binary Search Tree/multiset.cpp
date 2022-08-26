#include<iostream>
#include<set>
using namespace std;
int main()
{
    // Multiset - that can store multiple elements that have same value
    // stored in a specific order -> sorted according to internal comparison object
    // values once inserted can't be modified
    // associative container -> elements are referred by their value and not by index
    // underlying data structure - BST

    int arr[] = {10,20,30,20,10,10,30,30,30,30};
    int n = sizeof(arr)/sizeof(int);
    multiset<int> m(arr,arr+n);

    //Iterate
    for(auto x:m) cout<<x<<",";
    cout<<'\n';

    //erase
    m.erase(20);

    //insert
    m.insert(80);

    //count
    cout<<m.count(10)<<'\n';

    //find
    auto it = m.find(30);
    cout<<*it<<'\n';

    // Get all elements which are equal to 30
    auto p = m.equal_range(30);
    for(auto it = p.first;it!=p.second;it++)
    {
        cout<<*it<<" - ";
    }
    cout<<'\n';

    //lower and upper bound
    for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++)
    {
        cout<<*it<<"-";
    }
    cout<<'\n';
    return 0;
}