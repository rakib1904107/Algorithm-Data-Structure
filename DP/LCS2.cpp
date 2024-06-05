#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int dp[n+1][m+1],i,j;
    for(i=0;i<=n;i++)dp[i][0]=0;
    for(i=0;i<=m;i++)dp[0][i]=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s1[i]==s2[j])
                dp[i+1][j+1]=1+dp[i][j];
            else
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    cout<<dp[n][m]<<endl;
    string s="";
    i=n,j=m;
    while(i>0&&j>0){
        if(dp[i][j]==dp[i][j-1])
            j--;
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else{
            s+=s1[i-1];
            i--,j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
