#include<stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    double x,y,c;
    for(i=1;i<=T;i++){
        scanf("%lf %lf %lf",&x,&y,&c);
        double l=0.0,up=y,m,h1,h2,h,d;
        int j;
        for(j=1;j<100;j++){
            m=(l+up)/2.0;
            d=m;
            h1=sqrt(x*x - m*m);
            h2=sqrt(y*y - m*m);
            h=(h1*h2)/(h1+h2);
            if(h>c){
                l=m;
            }
            else{
                up=m;
            }
        }
        printf("Case %d: %lf\n",i,d);
    }
    return 0;
}
