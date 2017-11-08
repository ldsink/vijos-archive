#include<stdio.h>

long long a,b,c;

int main()
{
    for(a=0;a<10;a++)
    {
        scanf("%lld %lld",&b,&c);
        if(b>c)
        {
            if(b%4==0)
                printf("2\n");
            else
                printf("1\n");
        }
        else
        {
            if(c%4==0)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
