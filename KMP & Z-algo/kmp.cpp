#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MX 100050
using namespace std;
typedef long long ll;
int lps[MX];///lps=longest prefix suffix
///The lps function of a string s is defined as an array lps of length n,
///where lps[i] is the length of the longest proper prefix of the substring s[0...i]
///which is also a suffix of this substring.
void build_failure_function(string pattern,int m){
    lps[0]=0;
    lps[1]=0;
    for(int i=2;i<=m;i++){
        int j=lps[i-1];
        while(1){
            if(pattern[j]==pattern[i-1]){
                lps[i]=j+1;
                break;
            }
            if(j==0){
                lps[i]=0;
                break;
            }
            j=lps[j];
        }
    }
}
bool kmp(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    build_failure_function(pattern,m);
    int i=0,j=0;
    while(1){
        if(i==n)return false;
        if(text[i]==pattern[j]){
            i++,j++;
            if(j==m)
                return true;
        }
        else{
            if(j==0)
                i++;
            else
                j=lps[j];
        }
    }
    return false;
}
int main(){
    FIO()
    string text,pattern;
    cin>>text>>pattern;
    bool ans=kmp(text,pattern);
    if(ans)cout<<"pattern is the substring of text\n";
    else cout<<"pattern is not a substring of text\n";
}

