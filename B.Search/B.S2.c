#include<stdio.h>
double b_search(double X)
{
    double low=0.0,high=X,mid;
    int n=1;
    while(n<=50){
        mid=(low+high)/2;
        if(mid*mid>X){
            high=mid;
        }
        else{
            low=mid;
        }
        n++;
    }
    return mid;
}
int main()
{
    double X,mid;
    scanf("%lf",&X);
    mid=b_search(X);
    printf("%lf %lf\n",mid,mid*mid);
    return 0;
}
