/*int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

তোমাকে nটা দোকান থেকে n টা জিনিস কিনতে হবে। জিনিসগুলো কিনতে তোমার a0,a1,a2,…,a(n-1) টাকা লাগে।
তোমার শহরটা খুব অদ্ভূত,তুমি যখন একটা জিনিস কিনে আরেক দোকানে যাও
তখন সেই দোকানদার তোমার আগের কেনা জিনিসগুলো দেখে তার দোকানের জিনিসের দাম বাড়িয়ে দেয়!!
কত দাম বাড়াবে সেটা নির্ভর করবে তুমি আগে আগে কোন কোন দোকানে গিয়েছো সেটার উপর। ধরো n=2,
তাহলে তোমাকে নিচের মতো একটা ম্যাট্রিক্স দেয়া থাকবে:
     10 10
     90 10

যদি (i==j) হয় তাহলে matrix[i][j]=matrix[i][i]=i’তম জিনিসটির আসল দাম।
যদি (i!=j) হয় তাহলে matrix[i][j]=j’তম জিনিসটি আগে কিনলে i’তম জিনিসটির সাথে যোগ হওয়া বাড়তি দাম।*/

#include<bits/stdc++.h>
using namespace std;
int w[20][20];
int n;
int dp[(1<<15)+2];
int Set(int n,int pos){
    return (n|(1<<pos));
}
bool check(int n,int pos){
    return (n&(1<<pos));
}
int call(int mask){
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int mn=1<<28;
    for(int i=0;i<n;i++){
        if(check(mask,i)==0){
            int price=w[i][i];
            for(int j=0;j<n;j++){
                if(i!=j&&check(mask,j)!=0)
                    price+=w[i][j];
            }
            int ans=price+call(Set(mask,i));
            mn=min(mn,ans);
        }
    }
    dp[mask]=mn;
    return mn;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    }
    memset(dp,-1,sizeof(dp));

    int ans=call(0);
    cout<<ans<<endl;
}
