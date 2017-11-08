#include<stdio.h>

long Site[1000],A[1000][1000],B[1000][1000];

int main()
{
    long N,M,a,b,c,d;
    scanf("%ld %ld",&N,&M);
    for(b=1;b<=N;b++)
        scanf("%ld",&Site[b]);
    for(b=1;b<=N;b++)
        for(a=1;a<=N;a++)
        {
            c=Site[(a+b)/2];
            for(d=b;d<=a;d++)
                B[b][a]+=abs(Site[d]-c);
        }
    for(b=1;b<=N;b++)
        A[b][1]=B[1][b];
    for(a=2;a<=M;a++)
        for(b=a;b<=N-M+a;b++)
        { 
            A[b][a]=999999999; 
            for(c=a-1;c<=b-1;c++)
                if(A[b][a]>A[c][a-1]+B[c+1][b])
                    A[b][a]=A[c][a-1]+B[c+1][b];
        } 
    printf("%ld",A[N][M]);
    return 0;
}
