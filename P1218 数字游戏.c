#include<stdio.h>

long N,M,Ans1,Ans2,Num[101],Temp[101],MaxL[11][53],MinL[11][53],Re[52][52];

long Max(long x,long y)
{
    if(x>y) return x;
    else return y;
}

long Min(long x,long y)
{
    if(x>y) return y;
    else return x;
}

int main()
{
    scanf("%ld %ld",&N,&M);
    long a,b,c,d;
    for(a=1;a<=N;a++)
        scanf("%ld",&Num[a]);
    Num[0]=Num[N];Ans1=-1000000;Ans2=1000000;
    for(b=1;b<=N;b++)
    {
        memset(Re,0,sizeof(Re));
        memset(Temp,0,sizeof(Temp));
        memset(MaxL,0,sizeof(MaxL));
        memset(MinL,0,sizeof(MinL));
        for(a=b;a<=b+N-1;a++)
                Temp[a-b+1]=Num[a%N];
        for(a=1;a<=N;a++)
            for(c=a;c<=N;c++)
                Re[a][c]=(Re[a][c-1]+((Temp[c]+10000000)%10))%10;
        for(a=1;a<=N;a++)
        {
            MaxL[1][a]=Re[1][a];
            MinL[1][a]=Re[1][a];
        }
        for(a=2;a<=M;a++)
            for(c=a;c<=N;c++)
            {
                MinL[a][c]=1000000;
                for(d=a-1;d<=c-1;d++)
                {
                    MaxL[a][c]=Max(MaxL[a][c],MaxL[a-1][d]*Re[d+1][c]);
                    MinL[a][c]=Min(MinL[a][c],MinL[a-1][d]*Re[d+1][c]);
                }
            }
        if(MaxL[M][N]>Ans1) Ans1=MaxL[M][N];
        if(MinL[M][N]<Ans2) Ans2=MinL[M][N];
    }
    printf("%ld\n%ld\n",Ans2,Ans1);
    return 0;
}
