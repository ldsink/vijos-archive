#include<stdio.h>

int main()
{
    int i,j,k,x[20001]={0};
    scanf("%d",&k);
    for(i=1;i<=20000;i++)
        for(j=1;j<=20000/i;j++)
            x[i*j]++;
    for(i=1;i<=20000;i++)
        if(x[i]==k)
            {printf("%d",i);return 0;}
    printf("NO SOLUTION");
    return 0;
}
