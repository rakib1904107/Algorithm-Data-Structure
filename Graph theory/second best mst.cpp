#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    bool operator<(edge &p){
        return w<p.w;
    }
};
vector<edge>adj;
vector<edge>mst_edge;
int par[10000];
int find_set(int r){
    if(par[r]==r)return r;
    else return par[r]=find_set(par[r]);
}
int mst(edge it,int n)
{
    for(int i=1;i<=n;i++)par[i]=i;
    int cnt=0,cost=0;
    for(edge e:adj){
        if(e.u!=it.u||e.v!=it.v||e.w!=it.w){
            int u=find_set(e.u);
            int v=find_set(e.v);
            if(u!=v){
                par[v]=u;
                cost+=e.w;
                cnt++;
                if(cnt==n-1)break;
            }
        }
    }
    return cost;
}
int second_best_mst(int n){
    sort(adj.begin(),adj.end());
    for(int i=1;i<=n;i++)par[i]=i;
    int cnt=0;
    edge in;
    for(edge it:adj){
        int u=find_set(it.u);
        int v=find_set(it.v);
        if(u!=v){
            par[v]=u;
            in.u=it.u;
            in.v=it.v;
            in.w=it.w;
            mst_edge.push_back(in);
            cnt++;
            if(cnt==n-1)break;
        }
    }
    int mn=1e8;
    for(edge it:mst_edge){
        int p=mst(it,n);
        mn=min(p,mn);
    }
    return mn;
}
int main()
{
    int n,m;
    cin>>n>>m;
    edge in;
    for(int i=0;i<m;i++){
        cin>>in.u>>in.v>>in.w;
        adj.push_back(in);
    }
    cout<<second_best_mst(n)<<endl;
}
