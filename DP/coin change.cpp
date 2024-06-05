#include<bits/stdc++.h>
#define MX 1005
using namespace std;
int a[MX],dp[MX][MX];
int coin_cng(int i,int s){
    if(s==0)return 1;
    if(i<1||s<0)return 0;
    if(dp[i][s]!=-1)return dp[i][s];
    dp[i][s]=coin_cng(i,s-a[i])+coin_cng(i-1,s);
    return dp[i][s];
}
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<coin_cng(n,s)<<endl;
}
