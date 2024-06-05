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
void print_All_lcs(int i,int j,string ansS){
    if(s1[i]=='\0'||s2[j]=='\0'){
        cout<<ansS<<endl;
        return;
    }
    if(s1[i]==s2[j]){
        ansS+=s1[i];
        print_All_lcs(i+1,j+1,ansS);
    }
    else{
        if(dp[i][j+1]>dp[i+1][j])
            print_All_lcs(i,j+1,ansS);
        else if(dp[i+1][j]>dp[i][j+1])
            print_All_lcs(i+1,j,ansS);
        else{
            print_All_lcs(i+1,j,ansS);
            print_All_lcs(i,j+1,ansS);
        }
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
    print_All_lcs(0,0,ansS);
}


