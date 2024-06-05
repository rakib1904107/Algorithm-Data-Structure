#include<bits/stdc++.h>
#define mx 100002
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int L[mx],T[mx];
int P[mx][30];
int n,m;
vector<int>adj[mx];
void dfs(int par,int node,int lev){
    P[node][0]=par;
    T[node]=par;
    L[node]=lev;
    for(int child:adj[node]){
        if(child!=par)
            dfs(node,child,lev+1);
    }
}
void lca_init(){
    memset(P,-1,sizeof(P));
    dfs(-1,1,0);
    for(int j=1;1<<j<n;j++){
        for(int i=1;i<=n;i++){
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int p,int q){
    if(L[p]<L[q])swap(p,q);
    int d=L[p]-L[q];
    int log=log2(L[p]);
    while(d>0){
        int i=log2(d);
        p=P[p][i];
        d-=(1<<i);
    }

    if(p==q)return p;

    for(int i=log;i>=0;i--){
        if(P[p][i]!=-1&&P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];
    }

    return T[p];
}
int main()
{
    FIO();

    cin>>n>>m;
    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lca_init();
    cout<<lca_query(6,8)<<endl;
}
