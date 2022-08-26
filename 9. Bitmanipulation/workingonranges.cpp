#include<iostream>
using namespace std;
void clearibits(int &n,int i)
{
    int mask = ~0;
    mask = mask<<i;
    n = n & mask;
}
void clearrange(int &n,int j,int i)
{
    int mask1 = ~0;
    mask1<<=j;
    int mask2 = (1<<i)-1;
    int mask = mask1|mask2;
    n = n & mask;
}
int main()
{
    int n = 15;
    int i = 3;
    // clearibits(n,i);
    clearrange(n,4,2);
    cout<<n<<'\n';
    return 0;
}