#include <iostream>
using namespace std;
void print_lexiographicall(int n, int a = 0)
{
    // cout << 0 << " ";
    if(a > n)
        return;
    cout << a << " ";
    int i =0;
    if (a==0)
        i = 1;
    for(; i<=9; i++)
        print_lexiographicall(n, a*10 + i);
}
int main()
{
    int n;
    cin>>n;
    print_lexiographicall(n);
    return 0;
}