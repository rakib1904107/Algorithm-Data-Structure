#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 1000000000
using namespace std;
vector<pii>graph[1000];
vector<int>p(1000),d(1000);
int s,t;
void dijkstra(int n,int s)
{
    d.assign(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,s});
    d[s]=0,p[s]=-1;
    while(!q.empty()){
        int u=q.top().second;
        int d_u=q.top().first;
        q.pop();
        if(d_u!=d[u])continue;
        if(u==t)break;///only for one node .

        for(auto it:graph[u]){
            int v=it.first;
            int len=it.second;
            if(d[u]+len<d[v]){
                d[v]=d[u]+len;
                p[v]=u;
                q.push({d[v],v});
            }
        }
    }
}
int main()
{
    //freopen("df2.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    int n1,n2,w;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2>>w;
        graph[n1].push_back({n2,w});
        graph[n2].push_back({n1,w});
    }
    cin>>s>>t;
    dijkstra(node,s);

    cout<<"Shortest path from "<<s<<"--->"<<t<<" = "<<d[t]<<endl;
    cout<<"Sequence of path : ";
    vector<int>path;
    for(int v=t;v!=-1;v=p[v])
        path.push_back(v);
    reverse(path.begin(),path.end());
    for(auto it:path)
        cout<<it<<" ";
}

