#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
vector<int>adj[MAX];
int Left[MAX],Right[MAX],vis[MAX];
vector<int>v;
bool kuhn(int u){
    for(int v:adj[u]){
        if(vis[v])continue;
        vis[v]=1;
        if(Right[v]==-1||kuhn(Right[v])){
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}
int bipartitematching(){
    memset(Left,-1,sizeof(Left));
    memset(Right,-1,sizeof(Right));
    int cnt=0;
    for(int i=0;i<v.size();i++){
        memset(vis,0,sizeof(vis));
        if(kuhn(v[i]))cnt++;
    }
    return cnt;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ///first e bfs chaliye nodegula 2 ta set e divide korte hbe
    ///then 2 set divide kore 1 ta set v vector te store kore
    ///then nicher baki kaj krte hbe.
    cout<<bipartitematching()<<endl;
}
