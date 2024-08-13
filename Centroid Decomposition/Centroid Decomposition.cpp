#include<bits/stdc++.h>
using namespace std;

const int N=1e5+9;

vector<int>adj[N];
int subtree_sz[N];
int tot_node,done[N],centroid_par[N];

void calc_subtree_sz(int u,int par){
    tot_node++;
    subtree_sz[u]=1;
    for(int v:adj[u]){
        if(v==par||done[v])continue;
        calc_subtree_sz(v,u);
        subtree_sz[u]+=subtree_sz[v];
    }
}

int get_centroid(int u,int par){
    for(int v:adj[u]){
        if(v==par||done[v])continue;
        if(subtree_sz[v]>tot_node/2)return get_centroid(v,u);
    }
    return u;
}
void build_centroid_decomp(int u,int par){
    tot_node=0;
    calc_subtree_sz(u,par);
    int centroid=get_centroid(u,par);
    centroid_par[centroid]=par;
    done[centroid]=1;
    for(int v:adj[centroid]){
        if(v==par||done[v])continue;
        build_centroid_decomp(v,centroid);
    }
}

int main(){

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build_centroid_decomp(1,0);

    cout<<"Centroid Decomposed Tree :\n\n";
    for(int i=1;i<=n;i++)
        cout<<centroid_par[i]<<" "<<i<<endl;

}
