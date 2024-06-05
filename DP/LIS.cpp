#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>Lis(n+1,1);
    int pre[n+1]={0};
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){///use max(Lis[i],Lis[j]+1) only for length.
                if(Lis[j]+1>Lis[i]){
                    Lis[i]=Lis[j]+1;
                    pre[i]=j;
                }
            }
        }
    }
    int p=max_element(Lis.begin(),Lis.end())-Lis.begin();
    cout<<Lis[p]<<endl;
    vector<int>b;
    while(1){
        b.push_back(a[p]);
        p=pre[p];
        if(p==0)
            break;
    }
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
}
