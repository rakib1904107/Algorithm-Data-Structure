#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

const int MX=100005;
const int LOG=18;
vector<int> adj[MX];
int depth[MX];
int up[MX][LOG];

void dfs(int node,int parent) {
    up[node][0]=parent;
    for (int i=1;i<LOG;++i) {
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for (int neighbor : adj[node]) {
        if (neighbor!= parent) {
            depth[neighbor]=depth[node]+1;
            dfs(neighbor, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int main()
{
    FIO();
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int q;
    cin>>q;
    while(q--){
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}
