#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int matrix[110][110];
void floyd_warshall(int n)
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                matrix[i][j]=matrix[i][j]||(matrix[i][k]&matrix[k][j]);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int u,v;
    while(cin>>u>>v){
        matrix[u][v]=1;
    }
    floyd_warshall(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

}

