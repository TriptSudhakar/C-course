#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> d{1,2,3,4,14};
    // Push back O(1) for most of the time
    d.push_back(16);

    // Pop back Removes the last element O(1)
    d.pop_back();

    // Insert some elements in the middle O(N)
    d.insert(d.begin()+3,4,100);

    // Erase some elements in the middle 
    d.erase(d.begin()+3);
    d.erase(d.begin()+2,d.begin()+5);

    cout<<d.size()<<'\n';
    cout<<d.capacity()<<'\n';

    d.resize(5); //we avoid the shrink
    cout<<d.capacity()<<'\n';

    d.resize(18); //if size is increasing then more memory will be allocated
    cout<<d.capacity()<<'\n';

    d.clear(); //remove all the elements 
    cout<<d.size()<<'\n';

    if(d.empty())
    {
        cout<<"This is an empty vector"<<'\n';
    }

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    d.push_back(13);

    cout<<d.front()<<'\n';
    cout<<d.back()<<'\n';

    vector<int> v;
    v.reserve(1000);
    cout<<v.capacity();
    return 0;
}