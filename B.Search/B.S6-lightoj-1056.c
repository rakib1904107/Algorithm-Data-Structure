#include<stdio.h>
double value(int a,int b,double x)
{
    double r,theta,s,y;
    r=sqrt(a*a + b*b)/2.0;
    theta=acos((r*r + r*r -b*b)/(2.0*r*r));
    s=r*theta;
    y=((2*a*x)+(2*s*x));
    return y;
}
double b_search(int a,int b)
{
    int j;
    double x,l,h,m;
    l=0.0,h=400.0;
    for(j=1;j<100;j++){

        m=(l+h)/2.0;
        x=m;
        if(value(a,b,x)>400.0){
            h=m;
        }
        else{
            l=m;
        }
    }
    return x;

}
int main()
{
    int T;
    scanf("%d",&T);
    int a,b,i;
    double ans;
    for(i=1;i<=T;i++){
        scanf("%d : %d",&a,&b);
        ans=b_search(a,b);
        printf("Case %d: %lf %lf\n",i,a*ans,b*ans);
    }
}
