#include<stdio.h>

int main()
{
    int num[1000],a,b,i,j,t;
    scanf("%d %d",&a,&b);
    for(i=1;i<=a;i++)
        scanf("%d",&num[i]);
    for(i=1;i<a;i++)
        for(j=i+1;j<=a;j++)
            if(i*num[i]==j*num[j])
                {t=(i+j)/2;goto Out;}
    Out:
    printf("%d ",t);j=0;
    if(b==0)
        for(i=1;i<=t;i++)
            j+=num[i];
    else
        for(i=a;i>=t;i--)
            j+=num[i];
    printf("%d\n",j);
    return 0;
}
