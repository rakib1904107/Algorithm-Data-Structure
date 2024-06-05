#include<bits/stdc++.h>
#define Mx 10000
using namespace std;
vector<int>adj[Mx],d(Mx),low(Mx);
vector<bool>vs(Mx);
vector<pair<int,int>>ans;
int n,m,timer;
void bridges(int u,int par){
    vs[u]=true;
    d[u]=low[u]=timer++;
    for(int v:adj[u]){
        if(v==par)continue;
        if(vs[v])///This is backedge
            low[u]=min(low[u],d[v]);
        else{
            bridges(v,u);///This is a tree edge
            low[u]=min(low[u],low[v]);
            if(d[u]<low[v])
                ans.push_back({u,v});
        }
    }
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
    timer=0;
    for(int i=1;i<=n;i++){
        if(!vs[i])
            bridges(i,-1);
    }
    cout<<"Bridges are : \n";
    for(auto it:ans)cout<<it.first<<" "<<it.second<<endl;
}
