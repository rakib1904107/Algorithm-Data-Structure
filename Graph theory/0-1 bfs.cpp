#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>d;
vector<pair<int,int>>graph[1000];
void bfs(int s,int n)
{
    d.assign(1e8,n+1);
    deque<int>dq;
    dq.push_back(s);
    d[s]=0;
    while(!dq.empty())
    {
        int u=dq.front();
        dq.pop_front();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i].first;
            if(d[v]>d[u]+graph[u][i].second)
            {
                d[v]=d[u]+graph[u][i].second;
                if(graph[u][i].second==0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }

        }
    }
}
int main()
{
    int node,edge,s;
    cin>>node>>edge>>s;
    int n1,n2,cost;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2>>cost;
        graph[n1].push_back({n2,cost});
        graph[n2].push_back({n1,cost});
    }

    bfs(s,node);
    int x;
    cin>>x;
    cout<<"Distance from source node: "<<d[x]<<endl;
}
