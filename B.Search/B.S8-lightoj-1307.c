#include<stdio.h>
int triangle(long long s[],int N,int k,int l)
{
    int r,po,low,high,mid;

    r=s[k]+s[l];
    low=l+1;
    high=N-1;
    po=l;
    while(low<=high){
        mid=low+(high-low)/2;
        if(s[mid]<r){
            po=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return (po-l);
}
int main()
{
    int T;
    long long s[100005];
    scanf("%d",&T);
    int N,p;
    for(p=1;p<=T;p++){
        scanf("%d",&N);
        int q;
        for(q=0;q<N;q++){
            scanf("%lld",&s[q]);
        }
        int i,j,t;
        for(i=0;i<N;i++){
            for(j=0;j<N-i-1;j++){
                if(s[j]>s[j+1]){
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
        int k,l,d=0;
        for(k=0;k<N-2;k++){
            for(l=k+1;l<N-1;l++){
                d=d+triangle(s,N,k,l);
            }
        }
        printf("Case %d: %d\n",p,d);
    }

    return 0;
}

