#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 1000000000
using namespace std;
vector<pii>graph[1000];
vector<int>p(1000),d(1000);
void dijkstra(int n,int s)
{
    d.assign(n+1,INF);
    set<pii>st;
    st.insert({0,s});
    d[s]=0;
    while(!st.empty()){
        int u=st.begin()->second;
        st.erase(st.begin());

        for(auto it:graph[u]){
            int v=it.first;
            int len=it.second;
            if(d[u]+len<d[v]){
                st.erase({d[v],v});
                d[v]=d[u]+len;
                st.insert({d[v],v});
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
    int s;
    cin>>s;
    dijkstra(node,s);

    for(int i=1;i<=node;i++)
        cout<<s<<"-->"<<i<<" = "<<d[i]<<endl;
}
