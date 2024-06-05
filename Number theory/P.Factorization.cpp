#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 10000
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
ll M=(1ll<<32);
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> Os;
#define pi acos(-1)
vector<int>prime;
vector<bool>m(MX,true);
void sieve()
{
    ll x=MX;
    for(ll i=3;i*i<=x;i+=2){
        if(m[i]){
            for(ll j=i*i;j<=x;j+=i+i)
                m[j]=false;
        }
    }
    prime.push_back(2);
    for(ll i=3;i<=x;i+=2){
        if(m[i])
            prime.push_back(i);
    }
}
void solve()
{
   // sieve();
    int n;
    cin>>n;
    int i=0,p=6,q=10;
    while(1){
        if(p%30){
            cout<<p<<" ";
            i++;
        }
        if(i==n-1)break;
        if(q%30){
            cout<<q<<" ";
            i++;
        }
        q+=10;
        p+=6;
        if(i==n-1)break;
    }
    cout<<15<<endl;

}
int main()
{
    FIO();
  //  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
