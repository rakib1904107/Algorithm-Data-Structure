#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 1000000000
using namespace std;
vector<int>graph[1000],cost[1000];
vector<int>p(1000),d(1000);
void dijkstra(int n,int s)
{
    d.assign(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        int u=q.top().second;
        int d_u=q.top().first;
        q.pop();
        if(d_u!=d[u])continue;

        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            int len=cost[u][i];
            if(d[u]+len<d[v]){
                d[v]=d[u]+len;
                //cout<<d[v]<<endl;
                q.push({d[v],v});
            }
            //cout<<u<<" "<<v<<" "<<len<<" "<<d[v]<<" "<<d[u]<<endl;
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
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        cost[n1].push_back(w);
        cost[n2].push_back(w);
    }
    int s;
    cin>>s;
    dijkstra(node,s);
     for(int i=1;i<=node;i++){
        cout<<s<<" --> "<<i<<" = "<<d[i]<<endl;
    }
}


