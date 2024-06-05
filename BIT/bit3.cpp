/// Range upadte => sum of range query()..
#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int BIT1[1000],BIT2[1000],n;
void update1(int idx,int n_val){
    while(idx<=n){
        BIT1[idx]+=n_val;
        idx+=idx & (-idx);
    }
}
int query1(int idx){
    int ans=0;
    while(idx>0){
        ans+=BIT1[idx];
        idx-=idx & (-idx);
    }
    return ans;
}
void update2(int idx,int n_val){
    while(idx<=n){
        BIT2[idx]+=n_val;
        idx+=idx & (-idx);
    }
}
int query2(int idx){
    int ans=0;
    while(idx>0){
        ans+=BIT2[idx];
        idx-=idx & (-idx);
    }
    return ans;
}
int main()
{
    FIO();

    cin>>n;
    int a[n]={0};
    int q;
    cin>>q;
    int c,l,r,val;
    while(q--){
        cin>>c;
        if(c){
            cin>>l>>r>>val;
            update1(l,val);
            update1(r+1,-val);
            update2(l,val*(l-1));
            update2(r+1,-val*r);
        }
        else{
            cin>>l>>r;
            int v1=query1(l-1)*(l-1) - query2(l-1);
            int v2=query1(r)*r - query2(r);
            cout<<"Sum of all element in range [l,r] : "<<v2-v1<<endl;

        }
    }
}

