#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=1e9+9;
const ll x=53;

const ll nmax=1e5+5;
ll hash_value[nmax];///hash_value[i]=hash of s[0...i]
ll power[nmax];///power[i]=x^i

void precal(){
    power[0]=1;
    for(ll i=1;i<nmax;i++)power[i]=(power[i-1]*x)%M;
}

void buildHash(string& s){
    hash_value[0]=s[0]-'a'+1;

    for(ll i=1;i<s.size();i++){
        hash_value[i]=(hash_value[i-1]*x + (s[i]-'a'+1))%M;
    }

}

ll hashval(ll l,ll r){
    ll res=hash_value[r];
    if(l==0)return res;

    res-=(hash_value[l-1]*power[r-l+1]);
    res%=M;
    if(res<0)res+=M;

    return res;
}
int main(){
    precal();

    string s;
    cin>>s;

    buildHash(s);

    ll q;
    cin>>q;
    ll l,r;
    while(q--){
        cin>>l>>r;
        l--,r--;

        cout<<"Hash Value of substring s[l...r] : "<<hashval(l,r)<<endl;
    }
}

