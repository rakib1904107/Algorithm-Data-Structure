#include<bits/stdc++.h>
#define mx 100002
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int a[mx];
int mn[mx][22];
int bin_log[mx];
int n;
void sparse_t(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<=(n-(1<<j));i++)
            mn[i][j]=min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
    }
}
int rm_query(int l,int r){
    int len=r-l+1;
    int j=bin_log[len];
    int ans=min(mn[l][j], mn[r-(1<<j)+1][j]);
    return ans;
}
int main()
{
    FIO();

    cin>>n;
    bin_log[1]=0;
    for(int i=2;i<=n;i++)
        bin_log[i]=bin_log[i/2]+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn[i][0]=a[i];
    }
    sparse_t();
    cout<<rm_query(2,5)<<endl;
}

