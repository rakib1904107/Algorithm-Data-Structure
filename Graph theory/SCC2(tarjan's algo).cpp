#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1005];
vector<bool>vs,onStack;
int disc[1005],low[1005];
stack<int>st;
int t=1,scc=1;
void dfs1(int u)
{
    vs[u]=true;
    st.push(u);
    onStack[u]=true;
    disc[u]=low[u]=t++;
    for(int v:adj[u]){
        if(vs[v]==true&&onStack[v]==true){
            low[u]=min(low[u],disc[v]);
        }
        else if(vs[v]==false){
            dfs1(v);
            if(onStack[v]==true)
                low[u]=min(low[u],low[v]);
        }
    }
    if(disc[u]==low[u]){
        cout<<"SCC #"<<scc++<<":"<<endl;
        int x;
        while(1){
            x=st.top();
            st.pop();
            onStack[x]=false;
            cout<<x<<" ";
            if(x==u)break;
        }
        cout<<endl;
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
    }
    vs.assign(n+2,false);
    onStack.assign(n+2,false);
    for(int i=1;i<=n;i++){
        if(!vs[i])
            dfs1(i);
    }
}

