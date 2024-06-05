#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
vector<int>w[15];
int n,m;
int dp[15][1<<15];
int Set(int n,int pos){
    return (n|(1<<pos));
}
bool check(int n,int pos){
    return (n&(1<<pos));
}
int call(int i, int mask)
{
    if(mask==(1<<n)-1)return w[i][0];

    if(dp[i][mask]!=-1)return dp[i][mask];

    int ans=INF;
    for(int j=0;j<n;j++){
        if(w[i][j]==INF)continue;

        if(check(mask,j)==0){
            int ret=w[i][j]+call(j,Set(mask,j));
            ans=min(ans,ret);
        }
    }
    dp[i][mask]=ans;
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        w[i].assign(n+1,INF);
    int u,v,cost;
    for(int i=0;i<m;i++){
        cin>>u>>v>>cost;
        w[u][v]=cost;
    }
    memset(dp,-1,sizeof(dp));
    cout<<call(0,1)<<endl;
}
