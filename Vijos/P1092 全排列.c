#include<stdio.h>

int a[21],n;
long long b[21],m;

void Fun(int flag)
{
    int i,j;
    long long x,y;
    for(i=1;i<=n-flag;i++)
    {
        x=(b[n-1-flag]);
        y=i*x;
        x*=(i-1);
        if((x<m)&&(m<=y))
        {
            printf("%d ",a[i]);
            for(j=i;j<=n-flag-1;j++)
                a[j]=a[j+1];
            m-=x;
            if(flag+2<n)
                Fun(flag+1);
        }
    } 
}

int main()
{
    int i;
    scanf("%d %lld",&n,&m);
    b[0]=1;
    for(i=1;i<=n;i++)
        {
        a[i]=i;
        b[i]=b[i-1]*i;
        }
    Fun(0);
    printf("%d\n",a[1]);
    return 0;
}
