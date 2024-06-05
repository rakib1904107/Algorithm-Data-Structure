#include<bits/stdc++.h>
const int N =100000000;
using namespace std;
bitset<N>prime;
int setbit(int n,int p)
{
    n=n|(1<<p);
    return n;
}
int checkbit(int n,int p)
{
    return n&(1<<p);
}
void primeg(int n)
{
    prime[0]=setbit(prime[0],0);
    prime[0]=setbit(prime[0],1);

    for(int i=3;i<=sqrt(n);i+=2){
        if(!checkbit(prime[i/32],i%32)){
            for(int j=i*i;j<=n;j+=i+i){
                prime[j/32]=setbit(prime[j/32],j%32);
            }
        }
    }
    cout<<"2"<<" ";
    for(int i=3;i<=n;i+=2){
        if(!checkbit(prime[i/32],i%32))
            cout<<i<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    primeg(n);
}

