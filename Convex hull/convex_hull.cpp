/// Collinear point:Three point is called collinear if their cross product is equal to zero
/// Minimum Convex hull: When not include collinear point.This code is a minimum convex hull
/// Maximum convex hull : When include collinear point

#include<bits/stdc++.h>
using namespace std;

#define pb    push_back
#define ff    first
#define ss    second
#define pairr pair<int,int>

int Cross_Product(pairr a,pairr b,pairr c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss);
}

vector<pairr> Convex_Hull(vector<pairr> vp)
{
    int n=vp.size();
    sort(vp.begin(),vp.end());
    pairr u=vp.front(),v=vp.back();
    vector<pairr> up,down;
    up.pb(u),down.pb(u);
    for(int i=1;i<n;i++)
    {
        int CrossProduct=Cross_Product(u,v,vp[i]);
        /// CrossProduct er value >0 hole counter clockwise order hobe
        /// CrossProduct er value <0 hole clockwise order hobe
        if(i==n-1||CrossProduct>0)
        {
            while(up.size()>=2&&Cross_Product(up[up.size()-2],up[up.size()-1],vp[i])>=0) up.pop_back();
            up.pb(vp[i]);
        }
        if(i==n-1||CrossProduct<0)
        {
            while(down.size()>=2&&Cross_Product(down[down.size()-2],down[down.size()-1],vp[i])<=0) down.pop_back();
            down.pb(vp[i]);
        }
    }
    vector<pairr> hull=up;
    for(int i=down.size()-2;i>0;i--)
        hull.pb(down[i]);
    return hull;

}

int main()
{
    int n,x,y;
    cin>>n;
    vector<pairr> vp;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        vp.pb({x,y});
    }
    vector<pairr> hull= Convex_Hull(vp);
    cout<<hull.size()<<endl;
    for(int i=0;i<hull.size();i++){
        pairr it=hull[i];
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}


