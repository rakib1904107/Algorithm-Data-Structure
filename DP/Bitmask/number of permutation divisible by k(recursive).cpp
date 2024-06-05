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
int Set(int n,int pos){
    return (n|(1<<pos));
}
bool check(int n,int pos){
    return (n&(1<<pos));
}
string s;
int b,k,n;
int dp[1<<17][21];
int getdigit(char c){
    if('0'<=c&&c<='9')return int(c-'0');
    else return int(c-'A')+10;
}
int call(int mask,int r){

    if(mask==(1<<n)-1&&r==0)return 1;
    if(dp[mask][r]!=-1)return dp[mask][r];

    dp[mask][r]=0;
    for(int i=0;i<n;i++){
        if(!check(mask,i)){
            int d=getdigit(s[i]);
            dp[mask][r]+=call(Set(mask,i),(r*b+d)%k);
        }
    }
    return dp[mask][r];
}
void solve()
{
    int t,o=1;
    cin>>t;
    while(t--){
        cin>>b>>k;
        cin>>s;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<o++<<": "<<call(0,0)<<endl;
    }
}

int main()
{
    FIO();
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
