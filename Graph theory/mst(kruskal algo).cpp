#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    /*bool operator<(edge &p){
        return w<p.w;
    }*/
};
vector<edge>adj;
int par[10000];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int find_set(int r){
    if(par[r]==r)return r;
    else return par[r]=find_set(par[r]);
}
int mst(int n){
    sort(adj.begin(),adj.end(),cmp);
    for(int i=1;i<=n;i++)
        par[i]=i;
    int cost=0,cnt=0;
    for(edge it:adj){
        int u=find_set(it.u);
        int v=find_set(it.v);
        if(u!=v){
            par[v]=u;
            cost+=it.w;
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
    return cost;
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
    cout<<mst(n)<<endl;
    return 0;
}
