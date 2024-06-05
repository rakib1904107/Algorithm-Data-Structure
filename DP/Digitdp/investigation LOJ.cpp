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
ll Set(ll n,ll pos){
    return (n|(1<<pos));
}
bool check(ll n,ll pos){
    return (n&(1<<pos));
}
int dp[15][82][82][2];
vector<int>ar;
int a,b,k,len;
int cal(int pos,int f,int r,int rd){
    if(pos==len)return !(r+rd);
    if(dp[pos][r][rd][f]!=-1)return dp[pos][r][rd][f];
    int n;
    if(f)n=9;
    else n=ar[pos];

    int res=0;
    for(int i=0;i<n;i++){
        res+=cal(pos+1,1,(r*10+i)%k,(rd+i)%k);
    }
    if(f)res+=cal(pos+1,1,(r*10+n)%k,(rd+n)%k);
    else res+=cal(pos+1,0,(r*10+n)%k,(rd+n)%k);

    dp[pos][r][rd][f]=res;
    return res;
}
void solve()
{
    int t,o=1;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        if(a>b)swap(a,b);
        if(k==1)cout<<"Case "<<o++<<": "<<b-a+1<<endl;
        else if(k>81)cout<<"Case "<<o++<<": "<<0<<endl;
        else{
            memset(dp,-1,sizeof(dp));
            a--;
           // cout<<a<<" "<<b<<endl;
            while(a){
                ar.push_back(a%10);
                a/=10;
            }
            reverse(ar.begin(),ar.end());
            len=ar.size();
            int x=cal(0,0,0,0);
            //cout<<x<<endl;
            ar.clear();
            memset(dp,-1,sizeof(dp));
            while(b){
                ar.push_back(b%10);
                b/=10;
            }
            len=ar.size();
            reverse(ar.begin(),ar.end());
            int y=cal(0,0,0,0);
            //cout<<y<<endl;
            cout<<"Case "<<o++<<": "<<y-x<<endl;
        }
        ar.clear();
    }
}
int main()
{
    FIO();
   // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
