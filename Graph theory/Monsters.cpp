#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
int d[1050][1050],visit[1050][1050];
int row,col,p[1000010],str[1005][1005];///if cell[][]=-1,this cell block.
string s[10005];
char s1[1000010];
int x=-1,y=-1;
void bfs(int sx,int sy)
{
    //memset(s1,'1',sizeof(s1));
    queue<pair<int,int>>q;
    visit[sx][sy]=1;
    q.push({sx,sy});
    while(!q.empty()){
        pair<int,int>top=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(tx>=0&&tx<row&&ty>=0&&ty<col&&s[tx][ty]!='#'&&s[tx][ty]!='M'&&visit[tx][ty]==0){
                visit[tx][ty]=1;
                d[tx][ty]=d[top.first][top.second]+1;
                q.push({tx,ty});
                p[str[tx][ty]]=str[top.first][top.second];
                if(i==0){
                    int z=str[tx][ty];
                    s1[z]='D';
                }
                else if(i==1)
                    s1[str[tx][ty]]='U';
                else if(i==2)
                    s1[str[tx][ty]]='R';
                else
                    s1[str[tx][ty]]='L';
                if(tx==0||ty==0||tx==(row-1)||ty==(col-1))
                    x=tx,y=ty;

            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>row>>col;
    for(int i=0;i<row;i++)
        cin>>s[i];

    int sx,sy,t=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            str[i][j]=t++;
            if(s[i][j]=='A'){
                sx=i,sy=j;
            }
        }
    }
    memset(s1,'1',sizeof(s1));
    bfs(sx,sy);
    if(x==-1)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<d[x][y]<<endl;
        string s2="";
        for(int v=str[x][y];v!=str[sx][sy];v=p[v])
            s2+=s1[v];
        reverse(s2.begin(),s2.end());
        cout<<s2<<endl;
    }
}


