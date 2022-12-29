#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
int main()
{
    int n;
    cin>>n;
    int arr[1000]; // 1 5 2 3 6 4 10
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // if all numbers in the array are not distinct use pair<int,int>
    new_data_set s;
    int inversion_count = 0;
    for(int i=0;i<n;i++)
    {
        inversion_count += (s.size()-s.order_of_key(arr[i]));
        s.insert(arr[i]);
    }
    cout<<inversion_count<<'\n'; //4
    return 0;
}