#include<bits/stdc++.h>
using namespace std;
int visit[100],adj[100][100];
int ans[100],indrgee[100];
int n,m,x=0,i,j,k;
void top_sort()
{
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(!indrgee[j]&&!visit[j]){
                visit[j]=1;
                ans[i]=j;
                for(k=1;k<=n;k++){
                    if(!visit[k]&&adj[j][k])indrgee[k]--;
                }
                break;
            }
        }
        if(j==(n+1)){
            x=1;
            break;
        }
    }
}
int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][b]=1;
        indrgee[b]++;
    }
    top_sort();
    if(x)
        cout<<"There is no solution\n";///If a graph contain a cycle.
    else{
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
    }
}
