#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int p[n+1],w[n+1];
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)cin>>p[i];

    int k[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)k[i][j]=0;
            else if(w[i]<=j)
                k[i][j]=max(k[i-1][j],k[i-1][j-w[i]]+p[i]);
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }
    cout<<k[n][m]<<endl;
}
