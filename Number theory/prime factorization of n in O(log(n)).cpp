#include<bits/stdc++.h>
using namespace std;
#define N 10000005
int m[N];
void prime(){
     for(int i=0;i<N;i++)
        m[i]=i;
    for(int i=2;i*i<=N;i++){
        if(m[i]==i){
            for(int j=2*i;j<N;j+=i){
                m[j]=min(m[j],i);
            }
        }
    }
}
int main()
{
    prime();
    int n;
    cin>>n;
    while(n>1){
        cout<<m[n]<<" ";
        n/=m[n];
    }
}
