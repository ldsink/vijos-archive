#include<stdio.h>

int main()
{
    long i,j,n,a[1001]={0};
    scanf("%ld",&n);
    a[1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i/2;j++)
            a[i]=a[i]+a[j];
        a[i]++;
    }
    printf("%ld",a[n]);
    return 0;
} 
