#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=1e9+9;
const ll x=1e5+1;

const ll nmax=1e5+5;
ll hash_value[nmax];///hash_value[i]=hash of s[0...i]

ll buildHash(string& s){
    hash_value[0]=s[0]-'a'+1;

    for(ll i=1;i<s.size();i++){
        hash_value[i]=(hash_value[i-1]*x + (s[i]-'a'+1))%M;
    }
    return hash_value[s.size()-1];
}

int main(){
    string s;
    while(1){
        cin>>s;
        if(s==".")break;

        cout<<"Hash value of "<<s<<" : "<<buildHash(s)<<endl;
    }
}

