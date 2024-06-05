#include<bits/stdc++.h>
using namespace std;
int main()
{
    ///solution of equation ax+by=c,
    x=x0*c/gcd;///c must divisible by gcd
    y=y0*c/gcd;///x0 & y0 are the solution of ax+by=gcd(a,b)

    ///All solution of ax+by=c
    x=x0+k*(b/gcd);
    y=y0-k*(a/gcd);/// here k is an integer

    ///Minimum value of x+y
    x=x0+k*(b/gcd);
    y=y0-k*(a/gcd);
    x+y=x0+y0+(k*(b-a)/gcd);
}
