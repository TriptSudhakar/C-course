#include<iostream>
using namespace std;
void clearrange(int &n,int j,int i)
{
    int mask1 = ~0;
    mask1<<=j;
    int mask2 = (1<<i)-1;
    int mask = mask1|mask2;
    n = n & mask;
}
void updatebits(int &n, int m,int j, int i)
{
    m = m<<(i-1);
    clearrange(n,j,i-1);
    n = n|m;
}
int main()
{
    int n = 15;
    int m = 2;
    
    int j = 4;
    int i = 2;

    updatebits(n,m,j,i);
    cout<<n<<'\n';
    return 0;
}