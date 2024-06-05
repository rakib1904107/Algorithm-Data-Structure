#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x;
    cin>>n>>x;
    ll mod=1;
    for(ll i=1;i<=n;i++){
        mod=mod*i%x;
        mod%=x;
    }
    cout<<mod;
}

