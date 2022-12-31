#include<iostream>
#include<vector>
using namespace std;
vector<int> sieve_prime(int *p,int n)
{
    // first mark all the odd numbers as prime
    for(int i=3;i<10000;i+=2)
    {
        p[i] = 1;
    }

    // eliminate multiples of primes
    for(int i=3;i<10000;i+=2)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<10000;j+=2*i)
            {
                p[j] = 0;
            }
        }
    }

    // special case
    p[2] = 1;

    vector<int>primes;
    for(int i=2;i<=n;i++)
    {
        if(p[i]) primes.push_back(i);
    }
    return primes;
}
// useful approach if there are many queries , each query takes log(n) time, precomputation of primes takes nlog(log(n))
vector<int> factorize(vector<int>&arr,int n)
{  
    vector<int> ans;
    for(int i=0;i<arr.size() && arr[i]*arr[i]<=n;i++)
    {
        if(n%arr[i]==0)
        {
            while(n%arr[i]==0)
            {
                n/=arr[i];
                ans.push_back(arr[i]);
            }
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int p[10000] = {0};
    auto arr = sieve_prime(p,n);
    auto factors = factorize(arr,n);
    for(auto x:factors) cout<<x<<" ";
    cout<<endl;
    return 0;
}