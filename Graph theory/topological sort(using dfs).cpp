#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>ans;
vector<bool>visit(100);
int n,m;
void dfs(int u)
{
    visit[u]=true;
    for(int v:adj[u]){
        if(!visit[v])
            dfs(v);
    }
    ans.push_back(u);
}
void top_sort()
{
    for(int i=1;i<=n;i++){
        if(!visit[i])
            dfs(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout<<it<<" ";
}
int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    top_sort();
}
