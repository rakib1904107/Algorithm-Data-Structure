
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 200005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
ll M=(1ll<<32);
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> Os;
#define pi acos(-1)
ll bigmod(ll a,ll b){
    if(b==0)return 1;
    ll x=bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b&1)x=(x*a)%MOD;
    return x;
}
vector<ll>p;
ll x=sqrt(MX);
vector<ll>m(x+5,0);
void prime(){
    for(ll i=4;i<=x;i+=2)m[i]=1;
    for(ll i=3;i*i<=x;i+=2){
        if(!m[i]){
            for(ll j=i*i;j<=x;j+=2*i)m[j]=1;
        }
    }
    for(ll i=2;i<=x;i++){
        if(!m[i])p.push_back(i);
    }
}
ll GCD(ll a,ll b){
    if(b==0)return a;
    else return GCD(b,a%b);
}
void solve()
{
    int t;
    cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        int i,j;
        for( i=n,j=1;i>j;i--,j++)
            cout<<i<<" "<<j<<" ";
        if(i==j)cout<<i<<endl;
        else cout<<endl;
    }
}

int main()
{
    FIO();
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
