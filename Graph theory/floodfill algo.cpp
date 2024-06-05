#include<bits/stdc++.h>
using namespace std;
string s[1000];
int row,col,visit[1000][1000];
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
void floodfill(int i,int j)
{
    if(i<0||i>=row||j<0||j>=col)
        return;
    if(s[i][j]=='.'&&visit[i][j]==0){
        visit[i][j]=1;
        for(int k=0;k<8;k++){
            int x=i+fx[k];
            int y=j+fy[k];
            floodfill(x,y);
        }
    }
}
int main()
{
    cin>>row>>col;
    for(int i=0;i<row;i++)
        cin>>s[i];

    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='.'&&visit[i][j]==0){
                cnt++;
                floodfill(i,j);
            }
        }
    }
    cout<<"The number of region of dot(.) : "<<cnt<<endl;
}
