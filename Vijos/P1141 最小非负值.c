#include<stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    if(n%4==0||n%4==3)
        printf("0");
    else
        printf("1");
    return 0;
}
