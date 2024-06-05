#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int ans;
string ansS;
int dp[1000][1000];
int lcs(int i,int j)
{
    if(s1[i]=='\0'||s2[j]=='\0')
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        ans=1+lcs(i+1,j+1);
    else
        ans=max(lcs(i+1,j),lcs(i,j+1));
    dp[i][j]=ans;
    return dp[i][j];
}
void printlcs(int i,int j){
    if(s1[i]=='\0'||s2[j]=='\0'){
        cout<<ansS<<endl;
        return;
    }
    if(s1[i]==s2[j]){
        ansS+=s1[i];
        printlcs(i+1,j+1);
    }
    else{
        if(dp[i][j+1]>dp[i+1][j])
            printlcs(i,j+1);
        else printlcs(i+1,j);
    }
}
int main()
{
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    for(int i=0;i<n;i++)
        memset(dp,-1,sizeof(dp));

    cout<<lcs(0,0)<<endl;
    printlcs(0,0);
}


