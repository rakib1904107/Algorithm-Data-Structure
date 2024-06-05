#include<bits/stdc++.h>
#define Mx 10000
using namespace std;
vector<int>adj[Mx],d(Mx),low(Mx);
vector<bool>vs(Mx),ans(Mx);
int n,m,timer;
void articulationPoints(int u,int par){
    vs[u]=true;
    d[u]=low[u]=timer++;
    int no_of_children=0;
    for(int v:adj[u]){
        if(v==par)continue;
        if(vs[v])///This is backedge
            low[u]=min(low[u],d[v]);
        else{
            articulationPoints(v,u);///This is a tree edge
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v]&&par!=-1)
                ans[u]=true;
            no_of_children++;
        }
    }
    if(par==-1&&no_of_children>1)
        ans[u]=true;
}
int main(){
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vs.assign(n+5,false);
    ans.assign(n+5,false);
    timer=0;
    for(int i=1;i<=n;i++){
        if(!vs[i])
            articulationPoints(i,-1);
    }
    cout<<"Articulation Points are : \n";
    for(int i=1;i<=n;i++){
        if(ans[i])cout<<i<<" ";
    }
}
