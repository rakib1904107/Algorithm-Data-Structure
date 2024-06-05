#include<bits/stdc++.h>
#define mx 100002
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int L[mx],T[mx];///level and parent array
int P[mx][30];///sparse table
int n,m;
vector<int>adj[mx];
void dfs(int par,int node,int lev){
    T[node]=par;
    L[node]=lev;
    for(int child:adj[node]){
        if(child!=par)
            dfs(node,child,lev+1);
    }
}
void lca_init(){///form sparse table
    memset(P,-1,sizeof(P));
    for(int i=1;i<=n;i++)
        P[i][0]=T[i];

    for(int j=1;(1<<j)<n;j++){
        for(int i=1;i<=n;i++){
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int p,int q){///find LCA
    if(L[p]<L[q])swap(p,q);

    int log=1;
    while(1) {///or log=log2(L[p]) but it may occure precission error
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }

    for(int i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])
            p=P[p][i];
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
    dfs(-1,1,0);
    lca_init();
    cout<<lca_query(6,3)<<endl;
}
