#include<stdio.h>

int Fun(int m)
{
    if(m ==0)
        return 0;
    else
        return m^Fun(m/2);
}

int main()
{
    int N;
    scanf("%d",&N);
    printf("%d",Fun(N)+1);
    return 0;
}
