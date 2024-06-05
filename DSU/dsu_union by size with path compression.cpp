#include<bits/stdc++.h>
#define Mx 10000
using namespace std;
int parent[Mx];
int Size[Mx];
void make_set(int n){
    parent[n]=n;
    Size[n]=1;
}
int find_set(int r){
    if(parent[r]==r)
        return r;
    else
        return parent[r]=find_set(parent[r]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a==b)
        cout<<"a & b are in same set\n";
    else{
        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        make_set(i);
    union_sets(1,2);
    union_sets(2,3);
    union_sets(4,5);
    union_sets(3,5);
    union_sets(3,5);
    union_sets(1,4);
}

