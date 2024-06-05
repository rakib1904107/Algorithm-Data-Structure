#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 10000
using namespace std;
int a[MX],lazy[3*MX],tree[3*MX];
void init(int node,int b,int e){
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
    if(lazy[node]!=0){
        tree[node]=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b)
        return 0;
    else if(b>=i&&e<=j)
        return tree[node];
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int j,int x){

    if(lazy[node]!=0){
        tree[node]=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b)return;
    else if(b>=i&&e<=j){
        tree[node]=(e-b+1)*x;
        if(b!=e){
            lazy[2*node]=x;
            lazy[2*node+1]=x;
        }
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node]=tree[Left]+tree[Right];
}
int main(){
    FIO()
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init(1,1,n);
    //cout<<tree[1].sum<<endl;
    cout<<query(1,1,n,2,5)<<endl;
    update(1,1,n,1,6,4);
    update(1,1,n,1,3,2);
    update(1,1,n,1,6,4);
    update(1,1,n,4,5,1);
    cout<<query(1,1,n,3,6)<<endl;
   // update(1,1,n,1,3,2);
    //cout<<query(1,1,n,3,6)<<endl;
}
