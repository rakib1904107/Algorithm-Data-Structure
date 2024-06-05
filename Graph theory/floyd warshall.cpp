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
    int s1,s2;
    cin>>s1>>s2;
    cout<<"Distance from "<<s1<<" to "<<s2<<" is : "<<dis[s1][s2]<<endl;
    if(p[s1][s2]==-1)
        cout<<"No path\n";
    else{
        vector<int>path;
        for(int i=s2;i!=s1;i=p[s1][i])
            path.push_back(i);
        path.push_back(s1);
        reverse(path.begin(),path.end());
        for(auto it:path)
            cout<<it<<" ";
    }
}
