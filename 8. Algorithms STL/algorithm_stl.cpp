#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[] = {5,4,7,8,10};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    int*ans = find(arr,arr+n,key);
    int index = ans-arr;

    if(index==n)
    {
        cout<<"Key is not found"<<'\n';
    }
    else
    {
        cout<<"Key is present at index "<<index<<'\n';
    }

    int a[] = {1,3,5,7,8,100};
    int x = sizeof(a)/sizeof(int);

    bool present = binary_search(a,a+x,8);
    if(present == true)
    {
        cout<<"Key found"<<'\n';
    }
    else
    {
        cout<<"Key not found"<<'\n';
    }

    int *b = lower_bound(a,a+n,8); //gives the address of the first bucket whose value is >=8
    cout<<"Value : "<<*b<<'\n';
    cout<<"Index : "<<b-a<<'\n';

    int *c = upper_bound(a,a+n,8); //gives the address of the first bucket whose value is >8
    cout<<"Value : "<<*c<<'\n';
    cout<<"Index : "<<c-a<<'\n';
    //last occurence of 8 can be found using upper_bound-a

    cout<<"Number of occurrences of 8 is "<<c-b<<'\n';
    return 0;
}