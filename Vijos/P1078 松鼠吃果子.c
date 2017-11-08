#include<stdio.h>

int main()
{
    int m,n,i,k,num,a[201];
    long h,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        a[i]=i;
    for(i=1,j=1;i<=m;i++)
    {
        re:
        h=i*i*i%5+1;
        j+=h;
        if(j>n)
            {j=1;goto re;}
        num=a[j];
        for(k=j;k<n;k++)
            a[k]=a[k+1];
        n--;
    }
    printf("%d",num);
    return 0;
}


