#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 500005
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
ll INF=(1ll<<32);
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> Os;
#define pi acos(-1)
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int blck=sqrt(n)+1;///divide the array into sqrt(n) block
    vector<int>pre(blck+1);
    ///find the sum of each block.
    for(int i=0;i<n;i++)
        pre[i/blck]+=a[i];

    ///calculate sum of each query...
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int ans=0;
        for(int i=l;i<=r; ){
            if(i%blck==0&&i+(blck-1)<=r){///if a whole block lie in l to r
                ans+=pre[i/blck];
                i+=blck;
            }
            else{
                ans+=a[i];
                i++;
            }
        }
        cout<<ans<<endl;
    }
}
int main()
{
    FIO();
   // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
}
