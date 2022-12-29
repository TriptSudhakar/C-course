#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

int main()
{
    new_data_set s;
    s.insert(15);
    s.insert(1);
    s.insert(4);
    s.insert(10);
    s.insert(3);
    s.insert(1);
    
    for(int i=0;i<s.size();i++)
    {
        cout<<i<<" "<<*s.find_by_order(i)<<'\n';
    }
    cout<<s.order_of_key(5)<<'\n'; // denotes if 5 was present in the set, no of elements which would be strictly smaller than 5
    return 0;
}