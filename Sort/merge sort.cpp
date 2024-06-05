#include<bits/stdc++.h>
#define MAX 20000
using namespace std;
int a[MAX],temp[MAX];
void merging(int startpoint,int midpoint,int endpoint){
    int i,j,k;
    i=startpoint;
    j=midpoint+1;
    for(k=startpoint;i<=midpoint&&j<=endpoint;k++){
        if(a[i]<=a[j])
            temp[k]=a[i++];
        else temp[k]=a[j++];
    }
    while(i<=midpoint)
        temp[k++]=a[i++];
    while(j<=endpoint)
        temp[k++]=a[j++];
    for(i=startpoint;i<=endpoint;i++)
        a[i]=temp[i];
}
void sorting(int startpoint,int endpoint){
    if(startpoint>=endpoint)
        return;
    int midpoint=(startpoint+endpoint)/2;
    sorting(startpoint,midpoint);
    sorting(midpoint+1,endpoint);

    merging(startpoint,midpoint,endpoint);
}
int main()
{
    int n;
    cin>>n;
   // int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sorting(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
