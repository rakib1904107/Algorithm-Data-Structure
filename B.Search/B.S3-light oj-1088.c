#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    long int n,q;
    for(int i=1;i<=T;i++){
        scanf("%ld %ld",&n,&q);
        long long a[n];
        for(int j=0;j<n;j++){
            scanf("%lld",&a[j]);
        }
        printf("Case %d:\n",i);
        long long A,B,k;
        for(k=0;k<q;k++){
            scanf("%lld %lld",&A,&B);
            long long low=0,up=n-1,mid;
            while(low<=up){
                mid=(low+up)/2;
                if(a[mid]==A){
                    low=mid;
                    break;
                }
                else if(a[mid]<A){
                    low=mid+1;
                }
                else{
                    up=mid-1;
                }
            }
            long long Low=low,Up;
            low=0,up=n-1,mid;
            while(low<=up){
                mid=(low+up)/2;
                if(a[mid]==B){
                    low=mid+1;
                    break;
                }
                else if(a[mid]<B){
                    low=mid+1;
                }
                else{
                    up=mid-1;
                }
            }
            Up=low;
           printf("%lld\n",Up-Low);
        }
    }
    return 0;
}
