#include<iostream>
#include<vector>
using namespace std;
int add(int a,int b) // function to add two numbers
{
    return a+b;
}
int main()
{
    //Initialization
    vector<int> a;
    vector<int> b(5,10); //five int with value 10
    vector<int> c(b.begin(),b.end());
    vector<int> d{1,2,3,4,14};

    //How to iterate over a vector
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<",";
    }
    cout<<'\n';

    for(auto it = b.begin();it!=b.end();it++) //vector<int>::iterator
    {
        cout<<(*it)<<",";
    }
    cout<<"\n";

    //For each loop
    for(int x:d)
    {
        cout<<x<<",";
    }
    cout<<'\n';

    // vector<int> v;
    cout<<d.size()<<'\n';
    cout<<d.capacity()<<'\n';
    cout<<d.max_size()<<'\n';
    return 0;
}