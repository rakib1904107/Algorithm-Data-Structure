#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    multiset<int>lis;///This technic is used also for unique & duplicate value of the arry.
    for(int i=0;i<n;i++){
        lis.insert(a[i]);
        auto it=lis.upper_bound(a[i]);
        if(it!=lis.end())lis.erase(it);
    }
    cout<<lis.size()<<endl;
    for(auto it:lis){
        cout<<it<<" ";
    }
}

