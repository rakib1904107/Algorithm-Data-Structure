#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
vector<pair<int,int>>adj[1000];
vector<int>d(1000);
bool bellmanford(int s,int n)
{
    d.assign(n+2,INF);
    vector<int>cnt(n+2,0);
    vector<bool>inq(n+2,false);
    queue<int>q;
    d[s]=0;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(auto it:adj[u]){
            int v=it.first;
            int len=it.second;
            if(d[u]+len<d[v]){
                d[v]=d[u]+len;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                    cnt[v]++;
                    if(cnt[v]>n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,m,s;
    cin>>n>>m>>s;
    int n1,n2,w;
    for(int i=0;i<m;i++){
        cin>>n1>>n2>>w;
        adj[n1].push_back({n2,w});
    }
    bool ans=bellmanford(s,n);
    int t;
    cin>>t;
    if(ans){
        if(d[t]==INF)
            cout<<"No Path\n";
        else
            cout<<"Distance from "<<s<<" to "<<t<<" : "<<d[t]<<endl;
    }
    else
        cout<<"Detected negative cycle\n";
}
