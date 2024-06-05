#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fx[]={-2,-2,-1,+1,+2,+2,-1,+1};
int fy[]={-1,+1,+2,+2,+1,-1,-2,-2};
int d[100][100],visit[100][100];
int row,col,cell[100][100];///if cell[][]=-1,this cell block.
void bfs(int sx,int sy)
{
    queue<pair<int,int>>q;
    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    visit[sx][sy]=1;
    q.push({sx,sy});
    while(!q.empty()){
        pair<int,int>top=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(tx>0&&tx<=8&&ty>0&&ty<=8&&visit[tx][ty]==0){
                visit[tx][ty]=1;
                d[tx][ty]=d[top.first][top.second]+1;
                //cout<<d[tx][ty]<<endl;
                q.push({tx,ty});
            }
        }
    }
}
int main()
{
    char ch1,ch2;
    int x,y;
    map<char,int>m;
    int p=1;
    for(char ch='a';ch<='h';ch++)
        m[ch]=p++;
    while(cin>>ch1>>x>>ch2>>y){
        int sx,sy,fy,fx;
        sx=x,sy=m[ch1];
        fx=y,fy=m[ch2];
        bfs(sx,sy);
        cout<<"To get from "<<ch1<<x<<" to "<<ch2<<y<<" takes "<<d[fx][fy]<<" knight moves.\n";
    }
}
