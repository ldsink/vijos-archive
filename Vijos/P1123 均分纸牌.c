#include<stdio.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int a[n+1];
    for(i=1,j=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
        j=j+a[i];
    }
    for(j=j/n,i=1;i<=n;i++)
        a[i]=a[i]-j;
    for(i=1,j=0,k=0;i<=n;i++)
    {
        j=j+a[i];
        if(j!=0)
            k=k+1;
    }
    printf("%d",k);
    return 0;
}
