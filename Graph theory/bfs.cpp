#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool>visit(100);
vector<int>p(100),d(100);
vector<int>adjl[10000];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visit[s]=true;
    d[s]=0,p[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adjl[u].size();i++){
            int v=adjl[u][i];
            if(!visit[v]){
                visit[v]=true;
                q.push(v);
                d[v]=d[u]+1;
                p[v]=u;
            }
        }
    }
}
int main()
{
    int node,edge,s;
    cin>>node>>edge>>s;
    int n1,n2;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2;
        adjl[n1].push_back(n2);
        adjl[n2].push_back(n1);
    }

    bfs(s);
    ///If we have to restore and display the shortest path from the source to some vertex u, it can be done in the following manner
    int x;
    cin>>x;
    if(!visit[x])
        cout<<"No path\n";
    else{
        vector<int>path;
        for(int v=x;v!=-1;v=p[v])
            path.push_back(v);
        reverse(path.begin(),path.end());
        cout<<"Distance from the source :"<<d[x]<<endl;
        cout<<"Path :";
        for(int v:path)
            cout<<v<<" ";
    }
}

