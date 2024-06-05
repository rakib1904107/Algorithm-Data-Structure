#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>prime,lis;
map<ll,ll>m;
void summation(ll n)
{
    ll sum=1,cnt=1;
    for(ll i=0;i<prime.size();i++){
        while(n%prime[i]==0){
            n/=prime[i];
            cnt++;
        }
        sum*=(pow(prime[i],cnt)-1)/(prime[i]-1);
        cnt=1;
    }
    if(n>1){
        cnt++;
        sum*=(pow(n,cnt)-1)/(n-1);
    }
    cout<<sum;
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
    summation(n);
}
int main()
{
    ll n;
    cin>>n;
    sieve(n);
}


