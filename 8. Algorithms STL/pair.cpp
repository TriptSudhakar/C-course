#include<iostream>
using namespace std;
int main()
{
    // pair<int,int> p(500,200);
    pair<int,int> p;
    p = make_pair(22,42);
    cout<<p.first<<'\n';
    cout<<p.second<<'\n';

    pair<string,pair<float,int> > car;
    car.first = "BMW";
    car.second.first = 10.11;
    car.second.second = 12;
    cout<<car.first<<'\n';
    cout<<car.second.first<<'\n';
    cout<<car.second.second<<'\n';
    return 0;
}