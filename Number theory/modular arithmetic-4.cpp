#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modinverse(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    ll x=modinverse(a,b/2,m);
    x=(x*x)%m;
    if(b&1)
        x=(x*a)%m;
    return x;
}
int main()
{
    ll a,m,b;
    cin>>a>>b>>m;
    ll x=modinverse(b,m-2,m);
    ll mod=((a%m)*(x%m))%m;
    cout<<mod;
}

