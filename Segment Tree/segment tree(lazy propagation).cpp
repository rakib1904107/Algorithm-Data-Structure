#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 10000
using namespace std;
struct info{
    int sum,prop;///prop=propagated value
}tree[3*MX];
int a[MX];
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=a[b];
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].sum=tree[Left].sum+tree[Right].sum;
}
int query(int node,int b,int e,int i,int j,int carry){
    if(i>e||j<b)
        return 0;
    else if(b>=i&&e<=j)
        return tree[node].sum+carry*(e-b+1);
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(Right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
void update(int node,int b,int e,int i,int j,int x){
    if(i>e||j<b)return;
    else if(b>=i&&e<=j){
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}
int main(){
    FIO()

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init(1,1,n);
    //cout<<tree[1].sum<<endl;
    cout<<query(1,1,n,2,5,0)<<endl;
    update(1,1,n,3,6,4);
    cout<<query(1,1,n,1,5,0)<<endl;
    update(1,1,n,1,3,2);
    cout<<query(1,1,n,3,6,0)<<endl;
}
