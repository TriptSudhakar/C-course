#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

	//left limit
	stack <int> s;
	ll left[n];
    left[0] = -1;
    s.push(0);
	for(ll i=1;i<n;i++){
		ll curr=arr[i];
		while(!s.empty() && arr[s.top()] >= curr){
			s.pop();
		}
		if(s.empty()){
            left[i] = -1;
        }
		else{
            left[i]=s.top();
        }
		s.push(i);
	}

	//right limit
	stack <int> p;
	ll right[n];
    right[n-1] = n;
    p.push(n-1);
	for(ll i=n-2;i>=0;i--){
		ll curr=arr[i];
		while(!p.empty() && arr[p.top()]>=curr){
			p.pop();
		}
		if(p.empty()){
            right[i]=n;
        }
		else{
            right[i]=p.top();
        }
		p.push(i);
	}

	ll mx = 0;
	for(ll i=0;i<n;i++){
		mx=max(mx,(right[i]-left[i]-1)*arr[i]);
	}
	cout<<mx;
	return 0;
}