#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x;
    cin>>x;
    string s;
    cin>>s;
    ll mod=0,p=0;
    for(ll i=0;i<s.size();i++){
        mod=(mod*10)+(s[i]-'0');
        if(mod<x&&p==0)continue;
        p=1;
        cout<<mod/x;
        mod%=x;
    }
    cout<<" "<<mod;
}

