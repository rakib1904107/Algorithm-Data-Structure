#include<bits/stdc++.h>
using namespace std;
int d,x,y;
void extendeuclied(int a,int b)
{
    if(b==0){
        d=a;
        x=1;
        y=0;
    }
    else{
        extendeuclied(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    extendeuclied(a,b);
    cout<<"GCD(A,B) = "<<d<<endl;
    cout<<"Coefficients x and y are "<<x<<" "<<y<<endl;
}
