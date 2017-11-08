#include<stdio.h>
#define f(x) (a*x*x*x+b*x*x+c*x+d)
#define E 1e-2

double a,b,c,d;
double findsol(double x1,double x2)
{
    double xmid=(x1+x2)/2;
    if(x2-x1<E)
        return xmid;
    else if(f(xmid)*f(x1)<0.0)
        return findsol(x1,xmid);
    else
        return findsol(xmid,x2);
}

int main()
{
    double x1,x2,fx1,fx2;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    x1=-100.005;
    fx1=f(x1);
    for(x2=-99.005;x2<=100.995;x2++)
    {
        fx2=f(x2);
        if(fx1*fx2<0.0)
            printf("%.2lf ",findsol(x1,x2));
        x1=x2;
        fx1=fx2;
    }
    return 0;
}
