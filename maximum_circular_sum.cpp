#include<iostream>
#include<climits>
using namespace std;
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
  
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
  
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int neg[n]; 
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum += arr[i];
            neg[i] = (-1)*arr[i];
        }
        int psum = maxSubArraySum(arr,n);
        int nsum = maxSubArraySum(neg,n);
        int ans = max(psum,sum+nsum);
        cout<<ans<<'\n';
    }
    return 0;
}