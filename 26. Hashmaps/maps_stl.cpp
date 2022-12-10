#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> m;

    // 1. Insert
    m.insert(make_pair("Mango",100));

    pair<string,int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["Banana"] = 120;

    //2. Search
    string fruit;
    cin>>fruit;
    auto it = m.find(fruit);
    if(it!=m.end())
    {
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<'\n';
    }
    else
    {
        cout<<"Fruit is not present\n";
    }

    //3. Erase
    m.erase(fruit);

    //another way to find a particular key
    //it stores unique keys only once
    if(m.count(fruit))
    {
        cout<<"Price is "<<m[fruit]<<'\n';
    }
    else
    {
        cout<<"Couldn't find this fruit\n";
    }

    m["Litchi"] = 60;
    m["Pineapple"] = 80;


    // Iterate over all the key value pairs
    for(auto it = m.begin();it!=m.end();it++)
    {
        cout<<it->first<<":"<<it->second<<'\n';
    }

    //for each loop
    for(auto p:m)
    {
        cout<<p.first<<":"<<p.second<<'\n';
    }
    return 0;
}