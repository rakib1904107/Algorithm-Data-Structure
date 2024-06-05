#include<bits/stdc++.h>
#define Mx 1000
const int INF=1e9+7;
using namespace std;
vector<int>adj[Mx];
vector<vector<int>>capacity(Mx,vector<int>(Mx));
int n,m;
int bfs(int s,int t,vector<int>& p){
    p.assign(n+2,-1);
    p[s]=-1;
    queue<pair<int,int>>q;
    q.push({s,INF});
    while(!q.empty()){
        int cur=q.front().first;
        int flow=q.front().second;
        q.pop();

        for(int next:adj[cur]){
            if(p[next]==-1 && capacity[cur][next]){
                p[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);///minimum residual capacity
                if(next==t)return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t)
{
    int flow=0;
    vector<int>p(n+5);
    int new_flow;///minimum residual capacity

    while(new_flow=bfs(s,t,p)){
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=p[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
int main()
{
    cin>>n>>m;
    int u,v,cap;
    for(int i=0;i<m;i++){
        cin>>u>>v>>cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v]=cap;
        capacity[v][u]=0;
    }
    int s,t;
    cin>>s>>t;

    cout<<"Maximum Flow from s to t : "<<maxflow(s,t)<<endl;
}
