#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>ans;
int indegree[100];
void kahn(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    kahn(n);
    cout<<"topsort: ";
    for(int it:ans)
        cout<<it<<" ";
}
