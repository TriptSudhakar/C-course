#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
    return a<=b;
}
int main()
{
    int coins[] = {1,2,5,10,20,50,100};
    int n = sizeof(coins)/sizeof(int);

    int money = 25;
    while(money>0)
    {
        int index = lower_bound(coins,coins+n,money,compare)-coins-1;
        cout<<"We would give exchange of coin "<<coins[index]<<'\n';
        money -=coins[index];
    }
    return 0;
}