#include<bits/stdc++.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;
typedef long long ll;
vector<int>graph[1000];
vector<int>path;
int d[1000],f[1000],color[1000];
int t;
void DFS_Visit(int u)
{
    color[u]=GRAY;
    t++;
    d[u]=t;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(color[v]==WHITE){
            path.push_back(v);
            DFS_Visit(v);
        }
    }
    color[u]=BLACK;
    t++;
    f[u]=t;
}
void DFS(int V,int E)
{
    for(int i=1;i<=V;i++)
        color[i]=WHITE;
    t=0;
    for(int i=1;i<=V;i++){
        if(color[i]==WHITE){
            path.push_back(i);
            DFS_Visit(i);
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    int n1,n2;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    DFS(node,edge);
    cout<<"Visited Sequence : ";
    for(int x:path)
        cout<<x<<" ";
    cout<<endl;
    for(int i=1;i<=node;i++)
        cout<<d[i]<<" "<<f[i]<<endl;
}

