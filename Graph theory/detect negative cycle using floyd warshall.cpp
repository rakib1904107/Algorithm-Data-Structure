#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int dis[100][100],p[100][100];
void floyd_warshall(int n)
{
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        p[i][j]=p[k][j];
                    }
                }
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i!=j)
                dis[i][j]=INF;
            p[i][j]=-1;
        }
    }
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        dis[u][v]=w;
        p[u][v]=u;
    }
    floyd_warshall(n);
    for(int i=0;i<=n;i++){
        //cout<<dis[i][i]<<endl;
        if(dis[i][i]<0)
            cout<<"Find a negative cycle\n";
    }
}

