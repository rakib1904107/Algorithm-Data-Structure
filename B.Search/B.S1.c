#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int li=0,hi=n-1,mi,num,a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&num);
    while(li<=hi){
        mi=(li+hi)/2;
        if(num==a[mi]){
            break;
        }
        if(num<a[mi]){
            hi=mi-1;
        }
        else{
            li=mi+1;
        }
    }
    if(li>hi){
        printf("%d is not found\n",num);
    }
    else{
        printf("%d is found.%d th element",a[mi],mi);
    }
    return 0;
}
