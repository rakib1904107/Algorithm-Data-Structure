#include<bits/stdc++.h>
using namespace std;
int d,x,y;
void extendeuclied(int a,int m)
{
    if(m==0){
        d=a;
        x=1;
        y=0;
    }
    else{
        extendeuclied(m,a%m);
        int temp=x;
        x=y;
        y=temp-(a/m)*y;
    }
}
int moduloinverse(int a,int m)
{
    extendeuclied(a,m);
    return (x%m+m)%m;
}
int main()
{
    int a,m;
    cin>>a>>m;
    int p=moduloinverse(a,m);
    cout<<p;
}
