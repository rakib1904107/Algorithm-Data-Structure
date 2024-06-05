///Given L,R and K...find the no. of elements in the range
///L to R which are strictly less than K..
#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 100005
using namespace std;
typedef long long ll;
int a[MX];
vector<int>st[3*MX];
void init(int n,int b,int e){
    if(b==e){
        st[n].push_back(a[b]);
        return ;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);

    int i=0,j=0;
    ///merging left & right subtree...
    while(i<st[l].size()&&j<st[r].size()){
        if(st[l][i]<=st[r][j]){
            st[n].push_back(st[l][i]);
            i++;
        }
        else{
            st[n].push_back(st[r][j]);
            j++;
        }
    }
    while(i<st[l].size()){
        st[n].push_back(st[l][i]);
        i++;
    }
    while(j<st[r].size()){
        st[n].push_back(st[r][j]);
        j++;
    }
}
int query(int n,int b,int e,int i,int j,int k){
    if(b>j||e<i)return 0;
    else if(b>=i&&e<=j){
        int res=lower_bound(st[n].begin(),st[n].end(),k)-st[n].begin();
        return res;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    int p1=query(l,b,mid,i,j,k);
    int p2=query(r,mid+1,e,i,j,k);
    return p1+p2;
}
int main(){
    FIO()
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    init(1,1,n);
    int l,r,k;
    while(q--){
        cin>>l>>r>>k;
        cout<<query(1,1,n,l,r,k)<<endl;
    }
}
