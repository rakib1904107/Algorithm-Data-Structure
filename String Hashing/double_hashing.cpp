#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M1=1e9+9;
const ll x1=1e5+1;

const ll M2=1e8+1e5+1;
const ll x2=1e6+1;

const ll nmax=1e5+5;
ll hash_value1[nmax];///hash_value[i]=hash of s[0...i]
ll power1[nmax];///power[i]=x^i

ll hash_value2[nmax];///hash_value[i]=hash of s[0...i]
ll power2[nmax];///power[i]=x^i


void precal(){
    power1[0]=power2[0]=1;
    for(ll i=1;i<nmax;i++){
        power1[i]=(power1[i-1]*x1)%M1;
        power2[i]=(power2[i-1]*x2)%M2;
    }
}

void buildHash(string& s){
    hash_value1[0]=s[0]-'a'+1;
    hash_value2[0]=s[0]-'a'+1;

    for(ll i=1;i<s.size();i++){
        hash_value1[i]=(hash_value1[i-1]*x1 + (s[i]-'a'+1))%M1;
        hash_value2[i]=(hash_value2[i-1]*x2 + (s[i]-'a'+1))%M2;
    }

}

pair<ll,ll> hashval(ll l,ll r){
    ll res1=hash_value1[r];
    ll res2=hash_value2[r];

    if(l!=0){
        res1-=(hash_value1[l-1]*power1[r-l+1]);
        res1%=M1;
        if(res1<0)res1+=M1;

        res2-=(hash_value2[l-1]*power2[r-l+1]);
        res2%=M2;
        if(res2<0)res2+=M2;
    }

    return {res1,res2};
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

        auto p=hashval(l,r);

        cout<<"Hash Value of substring s[l...r] : "<<p.first<<" "<<p.second<<endl;
    }
}

