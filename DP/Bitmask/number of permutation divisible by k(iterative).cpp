#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 200005
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
ll M=(1ll<<32);
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> Os;
ll Set(ll n,ll pos){
    return (n|(1LL<<pos));
}
bool check(ll n,ll pos){
    return (n&(1LL<<pos));
}
ll m[10];
ll dp[(1<<18)][100];
void solve()
{
        ll n,k;
        string s;
        cin>>s>>k;
        n=s.size();
        dp[0][0]=1;
        for(ll mask=0;mask<(1<<n);mask++){
             for(ll i=0;i<n;i++){
                if(!check(mask,i)&&(mask||(s[i]-'0'))){
                    for(ll r=0;r<k;r++){
                        ll x=s[i]-'0';
                        dp[Set(mask,i)][(r*10+x)%k]+=dp[mask][r];
                    }
                }
             }
        }
        ll ans=dp[(1<<n)-1][0];
        for(ll i=0;i<n;i++){
            m[s[i]-'0']++;
        }
        for(ll i=0;i<10;i++){
            ll y=m[i];
            if(y>0){
                ll p=1;
                for(ll i=1;i<=y;i++)p*=i;
                ans/=p;
            }
        }
        cout<<ans<<endl;

}

int main()
{
    FIO();
   // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
