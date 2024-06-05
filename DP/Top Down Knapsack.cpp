#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int w[100000],val[100000];
vector<int>dp[10000];
int knap_sack(int sz,int itm)
{
    if(sz<0)
        return -val[itm-1];
    if(sz==0||itm>n)
        return 0;
    if(dp[sz][itm]!=-1)
        return dp[sz][itm];
    dp[sz][itm]=ans=max(val[itm]+knap_sack(sz-w[itm],itm+1),knap_sack(sz,itm+1));
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
        cin>>val[i];

    for(int i=1;i<=m;i++)
        dp[i].assign(n+5,-1);

    cout<<knap_sack(m,1);
}
