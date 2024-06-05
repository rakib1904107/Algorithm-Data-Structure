#include<bits/stdc++.h>
#define MAX 20000
using namespace std;
int a[MAX],tree[3*MAX];
void init(int node,int b,int e){///b=begin point,,,e=endpoint
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j){
    if(i>e||j<b)
        return 0;///out of range
    else if(b>=i&&e<=j)
        return tree[node];///inside of range
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue){
    if(i>e||i<b)
        return;
    else if(b==e){
        tree[node]=newvalue;
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init(1,1,n);///initial tree making
    update(1,1,n,2,2);
    cout<<query(1,1,n,1,4)<<endl;
    update(1,1,n,1,5);
    cout<<query(1,1,n,1,5)<<endl;
}
