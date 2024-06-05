#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 200005
#define MAX 1000000
#define MOD 998244353
#define INF 1000000007
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
vector<ll>P;
ll X=sqrt(MX);
vector<ll>Mp(X+5,0);
void prime(){
    for(ll i=4;i<=X;i+=2)Mp[i]=1;
    for(ll i=3;i*i<=X;i+=2){
        if(!Mp[i]){
            for(ll j=i*i;j<=X;j+=2*i)Mp[j]=1;
        }
    }
    for(ll i=2;i<=X;i++){
        if(!Mp[i])P.push_back(i);
    }
}
ll GCD(ll a,ll b){
    if(b==0)return a;
    else return GCD(b,a%b);
}
vector<int>a(20);
int m,n,dp[20][15][2];
int cal(int pos,int d,int f){
    if(pos==n)return 1;
    if(dp[pos][d][f]!=-1)return dp[pos][d][f];

    int res=0;
    for(int i=0;i<m;i++){
        if(f)res+=cal(pos+1,a[i],0);
        else if(abs(a[i]-d)<=2)
            res+=cal(pos+1,a[i],0);
    }
    dp[pos][d][f]=res;
    return res;
}
void solve()
{
    int t,o=1;
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i=0;i<m;i++)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<o++<<": "<<cal(0,0,1)<<endl;

    }
}
int main()
{
    FIO();
   // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
