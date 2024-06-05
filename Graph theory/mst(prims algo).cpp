#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pii>adj[100005];
int vis[10005];
int mst_prims(int n)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});
    int tot_cost=0,cnt=0;
    while(!pq.empty()){
        int u=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(!vis[u]){
            vis[u]=1;
            tot_cost+=w;
            cout<<u<<" "<<w<<endl;
            cnt++;
            for(auto it:adj[u]){
                int v=it.first;
                int cost=it.second;
                if(!vis[v])
                    pq.push({cost,v});
            }
            if(cnt==n)break;
        }
    }
    return tot_cost;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<mst_prims(n)<<endl;
}
