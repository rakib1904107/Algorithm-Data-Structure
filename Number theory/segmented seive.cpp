#include<bits/stdc++.h>
#define Max 70000
using namespace std;
typedef long long ll;
ll a[Max];
vector<ll>v,b;
void seive()
{
    for(ll i=3;i*i<=Max;i+=2){
        if(a[i]==0){
            for(ll j=i*i;j<=Max;j+=2*i)
                a[j]=1;
        }
    }
    v.push_back(2);
    for(ll i=3;i<=Max;i+=2){
        if(a[i]==0)
            v.push_back(i);
    }
}
void segSeive(ll l,ll r)
{
     b.assign(r-l+1,0);
     if(l==1)b[0]=1;
     for(ll i=0;v[i]*v[i]<=r;i++){
        ll base=(l/v[i])*v[i];
        if(base<l)base+=v[i];
        for(ll j=base;j<=r;j+=v[i])
            b[j-l]=1;
        if(base==v[i])b[base-l]=0;
     }
     for(ll i=0;i<r-l+1;i++){
         if(b[i]==0)cout<<i+l<<endl;
     }
}
int main()
{
    seive();
    int l,r;
    cin>>l>>r;
    segSeive(l,r);
}
