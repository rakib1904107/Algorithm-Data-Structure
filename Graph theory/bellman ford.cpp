#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
struct edge{
    int a,b,cost;
};
int n,m,s;
vector<edge>e(1000);
vector<int>d;
vector<int>p;
void bellmanford()
{
    d.assign(n+3,INF);
    d[s]=0;
    p.assign(n+3,-1);
    for(int i=1;i<=(n-1);i++){
        bool any=false;
        for(int j=0;j<m;j++){
            if(d[e[j].a]<INF){
                if(d[e[j].a]+e[j].cost<d[e[j].b]){
                    d[e[j].b]=d[e[j].a]+e[j].cost;
                    p[e[j].b]=e[j].a;
                    any=true;
                }
            }
        }
        if(!any)break;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>m>>s;
    int n1,n2,w;
    for(int i=0;i<m;i++){
        cin>>e[i].a>>e[i].b>>e[i].cost;
    }
    bellmanford();
    int t;
    cin>>t;
    if(d[t]==INF)
        cout<<"No path\n";
    else{
        cout<<"Distance from "<<s<<" to "<<t<<" : "<<d[t]<<endl;
        vector<int>path;
        for(int v=t;v!=-1;v=p[v])
            path.push_back(v);
        reverse(path.begin(),path.end());
        cout<<"Path from "<<s<<" to "<<t<<" : ";
        for(auto it:path)
            cout<<it<<" ";
    }
}

