#include<bits/stdc++.h>
#define N 20000000
using namespace std;
typedef long long ll;
ll m[N];
int main()
{
    ll n;
    cin>>n;
    ll x=sqrt(n);
    m[0]=m[1]=1;
    for(ll i=4;i<=n;i+=2)
        m[i]=1;
    for(ll i=3;i<=x;i+=2){
        if(m[i]==0){
            for(ll j=i*i;j<=n;j+=i+i)
                m[j]=1;
        }
    }
    for(ll i=0;i<=n;i++){
        if(m[i]==0)
            cout<<i<<" ";
    }
}
