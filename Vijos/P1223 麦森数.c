#include<stdio.h>

long Out[501],Fen[1001];

void Solve(long n)
{
    long a,b;
    if(n==0)
        return;
    Solve(n/2);
    for(a=1;a<=500;a++)
        for(b=1;b<=500;b++)
            if(n%2==0)
                Fen[a+b-1]=Fen[a+b-1]+Out[a]*Out[b];
            else
                Fen[a+b-1]=Fen[a+b-1]+Out[a]*Out[b]*2;
    for(a=1;a<=500;a++)
    {
        Out[a]=Fen[a]%10;
        Fen[a+1]+=Fen[a]/10;
    }
    memset(Fen,0,sizeof(Fen));
}

int main()
{
    long n,a,b;
    scanf("%ld",&n);
    printf("%ld\n",(int)(n*log(2)/log(10.0)+1));
    Out[1]=1;Solve(n);
    for(a=500;a>1;a--)
    {
        printf("%ld",Out[a]);
        if(a%50==1)
            printf("\n");
    }
    printf("%ld",Out[1]-1);
    return 0;
}
