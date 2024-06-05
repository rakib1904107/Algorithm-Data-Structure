#include<stdio.h>
#include<math.h>
double ratio(double a,double b,double c,double ad)
{
     double de,ae,s1,s2,tr,r,Sa,La;
        de=(ad*b)/a;
        ae=(ad*c)/a;
        s1=(ad+de+ae)/2.0;
        s2=(a+b+c)/2.0;
        Sa=sqrt(s1*(s1-ad)*(s1-de)*(s1-ae));
        La=sqrt(s2*(s2-a)*(s2-b)*(s2-c));
        tr=La-Sa;
        r=Sa/tr;
        return r;
}
double length(double a,double b,double c,double R)
{

      double low,high,ad,mid,n=0;
      low=0.0,high=a;
     while(n<100){
            n++;
            mid=(low+high)/2.0;
            ad=mid;
            if(ratio(a,b,c,ad)>R){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return ad;
}
int main()

{
    int T,i;
    scanf("%d",&T);
    double a,b,c,R,ans;
    for(i=1;i<=T;i++){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&R);
        ans=length(a,b,c,R);
        printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
