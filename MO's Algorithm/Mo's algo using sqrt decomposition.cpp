#include<bits/stdc++.h>
#define mx 200010
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
struct data{
    int l,r,idx;
}query[mx];
int m[1000010];
int block;
bool comp(data q1,data q2){
    if(q1.l/block!=q2.l/block)
        return q1.l<q2.l;
    else return q1.r<q2.r;
}
int main()
{
    FIO();

    int n;
    scanf("%d",&n);
    int a[n+5];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&query[i].l,&query[i].r);
        query[i].l--;
        query[i].r--;
        query[i].idx=i;
    }
    block=sqrt(n);
    sort(query,query+q,comp);
    int l=0,r=-1,ans=0;
    vector<int>Ans(q+6);
    for(int i=0;i<q;i++){
        while(l<query[i].l){
            m[a[l]]--;
            if(m[a[l]]==0)ans--;
            l++;
        }
        while(r<query[i].r){
            m[a[r+1]]++;
            if(m[a[r+1]]==1)ans++;
            r++;
        }
        while(l>query[i].l){
            m[a[l-1]]++;
            if(m[a[l-1]]==1)ans++;
            l--;
        }
        while(r>query[i].r){
            m[a[r]]--;
            if(m[a[r]]==0)ans--;
            r--;
        }
        Ans[query[i].idx]=ans;
    }
    for(int i=0;i<q;i++)printf("%d\n",Ans[i]);

}
