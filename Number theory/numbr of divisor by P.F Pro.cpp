#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(cin>>n&&n>0){
        ll divisor=1,cnt=1;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        divisor*=cnt;
        cnt=1;
        for(ll i=3;i<=sqrt(n);i+=2){
            while(n%i==0){
                cnt++;
                n/=i;
            }
            divisor*=cnt;
            cnt=1;
        }
        if(n>1)
            divisor*=2;

        cout<<divisor<<endl;
    }
}


