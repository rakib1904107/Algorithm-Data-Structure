#include<bits/stdc++.h>
#define mx 100002
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int euler_tour[2*mx];///euler tour nodes sequence
int e_t_depth[2*mx];///depth of each node in euler tour
int n_idx[mx];///nodes index in euler tour
int mn[mx][22];///sparse table
int vs[mx],bin_log[2*mx];
vector<int>adj[mx];
int n,m;
int rm_query(int l,int r){
    int len=r-l+1;
    int j=bin_log[len];
    int x=mn[l][j];
    int y=mn[r-(1<<j)+1][j];
    if(e_t_depth[x]<e_t_depth[y])
        return mn[l][j];
    else
        return mn[r-(1<<j)+1][j];
}
void dfs(int u,int dep,int &idx){
    vs[u]=1;
    n_idx[u]=idx;
    euler_tour[idx]=u;
    e_t_depth[idx]=dep;
    idx++;
    for(int v:adj[u]){
        if(!vs[v]){
            dfs(v,dep+1,idx);
            n_idx[u]=idx;
            euler_tour[idx]=u;
            e_t_depth[idx]=dep;
            idx++;
        }
    }
}
void MinSparseTable(){
    int len=2*n-1;
    bin_log[1]=0;
    for(int i=2;i<=len;i++)
        bin_log[i]=bin_log[i/2]+1;

    for(int i=0;i<len;i++)
        mn[i][0]=i;
    for(int j=1;(1<<j)<=len;j++){
        for(int i=0;i<=(len-(1<<j));i++){
            int x=mn[i][j-1];
            int y=mn[i+(1<<(j-1))][j-1];
            if(e_t_depth[x]<e_t_depth[y])
                mn[i][j]=mn[i][j-1];
            else
                mn[i][j]=mn[i+(1<<(j-1))][j-1];
        }
    }
}
int lca_query(int p,int q){
    int l=min(n_idx[p],n_idx[q]);
    int r=max(n_idx[p],n_idx[q]);
    int i=rm_query(l,r);
    return euler_tour[i];
}
int main()
{
    FIO();

    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x=0;
    dfs(0,0,x);
    MinSparseTable();
    cout<<lca_query(8,6)<<endl;
}

