#include<stdio.h>

int M,N,Ans,W[1000],Job[30][30],Time[30][30],Last[100],P[100];
char Line[30][10000],Thing[30][10000];

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%d %d",&M,&N);
    for(b=1;b<=M*N;b++)
        scanf("%d",W+b);
    for(b=1;b<=N;b++)
        for(c=1;c<=M;c++)
            scanf("%d",&Job[b][c]);
    for(b=1;b<=N;b++)
        for(c=1;c<=M;c++)
            scanf("%d",&Time[b][c]);
    for(Ans=0,b=1;b<=M*N;b++)
    {
        P[W[b]]++;
        f=Job[W[b]][P[W[b]]];
        e=Time[W[b]][P[W[b]]];
        for(g=0,a=Last[W[b]]+1;!g;a=c+1)
        {
            for(c=a+e-1;c>=a;c--)
            if(Thing[W[b]][c]||Line[f][c])break;
            if(c==a-1)
            {
                for(c=a;c<a+e;c++)
                Thing[W[b]][c]=Line[f][c]=W[b];
                if(a+e>Ans)Ans=a+e;
                Last[W[b]]=a+e-1;
                g=1;
            }
        }
    }
    printf("%d",Ans-1);
    return 0;
}
