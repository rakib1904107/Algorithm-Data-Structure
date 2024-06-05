#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    set<int>s;///This technic used for unique value of the arry.
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        auto it=s.find(a[i]);///find() is like lower_bound() function.
        it++;
        if(it!=s.end())s.erase(it);
    }
    cout<<s.size()<<endl;
}
