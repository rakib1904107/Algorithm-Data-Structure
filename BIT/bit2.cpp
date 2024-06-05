///range update => point query(to find the value of this point)
#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int a[1000],BIT[1000],n;
void update(int idx,int n_val){
    while(idx<=n){
        BIT[idx]+=n_val;
        idx+=idx & (-idx);
    }
}
int getelement(int idx){
    int ans=0;
    while(idx>0){
        ans+=BIT[idx];
        idx-=idx & (-idx);
    }
    return ans;
}
int main()
{
    FIO();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
        update(i+1,-a[i]);
    }
    int q;
    cin>>q;
    int c,l,r,val,idx;
    while(q--){
        cin>>c;
        if(c){
            cin>>l>>r>>val;
            update(l,val);
            update(r+1,-val);
        }
        else{
            cin>>idx;
            cout<<"Value of idx'th index : "<<getelement(idx)<<endl;
        }
    }
}

