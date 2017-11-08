#include<stdio.h>

int main()
{
    double n,m;int a;
    scanf("%lf",&n);
    int A[33]={0},B[33]={0};
    for(a=1;n>0;a++)
        {A[a]=(int)n%2;n=(int)n/2;}
    for(a=17;a<33;a++)
        B[a]=A[a-16];
    for(a=0;a<17;a++)
        B[a]=A[a+16];
    for(n=0,a=1,m=1;a<33;a++,m*=2)
        if(B[a]==1)
            n+=m;
    printf("%.0lf",n);
    return 0;
}
