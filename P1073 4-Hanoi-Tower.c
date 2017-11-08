#include<stdio.h>

int main()
{
    int n,i,p1,p2,p3,num;
    scanf("%d",&n);
    p1=1;p2=1;p3=1;num=0;
    for(i=1;i<=n;i++)
    {
        num=(num+p1)%10000;
        p2--;
        if(p2==0)
            {p1=(p1*2)%10000;p3++;p2=p3;}
    }
    printf("%d",num);
    return 0;
}
