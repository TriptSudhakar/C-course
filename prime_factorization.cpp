#include<iostream>
using namespace std;
void printFactors(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n /= i;
                cout<<i<<" ";
            }
        }
    }

    if(n!=1)
    {
        // whatever is left is prime
        cout<<n<<'\n';
    }
}
int main()
{
    int n;
    cin>>n;
    printFactors(n);
    return 0;
}