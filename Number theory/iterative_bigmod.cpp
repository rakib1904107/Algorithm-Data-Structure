#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll bigmod(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	while (y > 0)
    {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return (res + p) % p;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<bigmod(n,m,mod);
}
