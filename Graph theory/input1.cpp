#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int adj[100][100],matrix[100][100];
int main()
{
    int node,edge;
    cin>>node>>edge;
    int n1,n2,cost;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2>>cost;
        adj[n1][n2]=cost;
        adj[n2][n1]=cost;
    }

    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    ///Another pattern.
    cin>>node>>edge;
    map<int,int>m;
    int x=1;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2>>cost;
        if(m[n1]==0)m[n1]=x++;
        if(m[n2]==0)m[n2]=x++;
        matrix[m[n1]][m[n2]]=cost;
        matrix[m[n2]][m[n1]]=cost;
    }
    for(int i=0;i<=node;i++){
        for(int j=0;j<=node;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
