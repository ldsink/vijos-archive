#include<stdio.h>
#include<math.h>

int main()
{
    double g,Wucha,H,S,V,L,K,t1,t2,l1,l2;
    long n,i,total;
    Wucha=0.00001;g=10.0;
    scanf("%lf %lf %lf %lf %lf %d",&H,&S,&V,&L,&K,&n);
    t1=sqrt(2*(H-K)/g);
    t2=sqrt(H*2/g);
    l1=S-V*t2;
    l2=S-V*t1+L;
    for(i=0,total=0;i<n;i++)
    {
        if(l1-Wucha<=i&&i<=l2+Wucha)
            total++;
    }
    printf("%d",total);
    return 0;
}
