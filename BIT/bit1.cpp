///point update =>point query & range query
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
int query(int idx){
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
    }
    cout<<"Sum of first 4 elements : "<<query(4)<<endl;///point query
    cout<<"Sum of all elements in range [2,7] : "<<query(7)-query(2-1)<<endl;///range query

}

