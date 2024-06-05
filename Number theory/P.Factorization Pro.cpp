#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX 500
#define INF 1<<30
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define pi acos(-1)
int main()
{
    FIO();

    int p,n;
    char ch;
    while(scanf("%d%c%d",&p,&ch,&n)==3){
        int ans=0;
        for(int i=n+1;i<=2*n;i++){
            int a=n*i;
            int b=i-n;
            int y=a/b;
            if(a%b==0)ans++;
        }
        cout<<ans<<endl;
    }
}
