#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1005],adj_rev[1005];
vector<int>order,ans;
vector<bool>vs;
void dfs1(int u)
{
    vs[u]=true;
    for(int v:adj[u]){
        if(!vs[v])
            dfs1(v);
    }
    order.push_back(u);
}
void dfs2(int u)
{
    vs[u]=true;
    ans.push_back(u);
    for(int v:adj_rev[u]){
        if(!vs[v])
            dfs2(v);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    vs.assign(n+2,false);
    for(int i=1;i<=n;i++){
        if(!vs[i])
            dfs1(i);
    }
    vs.assign(n+2,false);
    reverse(order.begin(),order.end());
    int scc=1;
    for(int i:order){
        if(!vs[i]){
            dfs2(i);
            cout<<"SCC #"<<scc++<<":"<<endl;
            for(int it:ans)
                cout<<it<<" ";
            cout<<endl;
            ans.clear();
        }
    }
}
