#include<bits/stdc++.h>
#define M 10000000
using namespace std;
int phi[M];
void calculatephi(int n)
{
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<phi[i]<<" ";
}
int main()

{
    int n;
    cin>>n;
    calculatephi(n);
}
