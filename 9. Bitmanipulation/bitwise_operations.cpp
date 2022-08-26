#include<iostream>
using namespace std;
void clearbit(int &n,int i)
{
    int mask = 1<<i;
    mask = ~mask;
    n = (n&mask);
}
void updatebit(int &n,int i,int v)
{
    int mask = 1<<i;
    mask = ~mask;
    n = (n&mask);

    n = n|(v<<i);
}
int main()
{
    int n = 16;
    // clearbit(n,3);
    updatebit(n,3,1);
    cout<<n<<'\n';
}