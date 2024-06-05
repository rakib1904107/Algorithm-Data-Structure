#include<bits/stdc++.h>
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
///The Z-function of a string s is an array of length n where the i-th element
///is equal to the greatest number of characters starting from the position i
///that coincide with the first characters of s.
vector<int>build_z_function(string s){
    int n=s.size();
    vector<int>z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);

        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
            z[i]++;

        if(i+z[i]-1>r)
            l=i,r=i+z[i]-1;
    }
    return z;
}
int main(){
    FIO()
    string s;
    cin>>s;
    vector<int>z_function;
    z_function=build_z_function(s);
    for(int it:z_function)
        cout<<it<<" ";
}
