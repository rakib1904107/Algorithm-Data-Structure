#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>edges[1000];
vector<int>cost[1000];
int main()
{
    int node ,edge;
    cin>>node>>edge;
    int n1,n2,weight;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2>>weight;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
        cost[n1].push_back(weight);///cost vector is not needed for unweighted graph.
        cost[n2].push_back(weight);
    }
    for(int i=0;i<=node;i++){
        for(int j=0;j<edges[i].size();j++){
            cout<<i<<" "<<edges[i][j]<<" "<<cost[i][j]<<endl;
        }
    }
}
