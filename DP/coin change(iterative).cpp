#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n+2];
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans[n+2][s+2];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i==0&&j!=0)ans[i][j]=0;
            else if(j==0)ans[i][j]=1;
            else if(j<a[i])ans[i][j]=ans[i-1][j];
            else ans[i][j]=ans[i-1][j]+ans[i][j-a[i]];
        }
    }
    cout<<ans[n][s]<<endl;
}
