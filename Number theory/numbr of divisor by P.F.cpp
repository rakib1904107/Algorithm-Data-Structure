#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>prime,lis;
map<ll,ll>m;
void numbrofdivisor(ll n)
{
    ll divisor=1,cnt=1;
    for(ll i=0;i<prime.size();i++){
        while(n%prime[i]==0){
            n/=prime[i];
            cnt++;
        }
        divisor*=cnt;
        cnt=1;
    }
    if(n>1)
        divisor*=2;
    cout<<divisor;
}
void sieve(ll n)
{
    ll x=sqrt(n);
    for(ll i=3;i*i<=x;i+=2){
        if(m[i]==0){
            for(ll j=i*i;j<=x;j+=i+i)
                m[j]=1;
        }
    }
    prime.push_back(2);
    for(ll i=3;i<=x;i+=2){
        if(m[i]==0)
            prime.push_back(i);
    }
    numbrofdivisor(n);
}
int main()
{
    ll n;
    cin>>n;
    sieve(n);
}

