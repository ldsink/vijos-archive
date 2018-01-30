#include<stdio.h>

long N,M,Line[100000];
double Weight[100000],Apple[100000];

void KPA(long st,long en)
{
    long a,b,c;
    a=st;b=en;c=Apple[a];
    while(a<b)
    {
        while(a<b)
        {
            if(Apple[b]>c)
                {Apple[a]=Apple[b];break;}
            b--;
        }
        while(a<b)
        {
            if(Apple[a]<c)
                {Apple[b]=Apple[a];break;}
            a++;
        }
    }
    Apple[a]=c;
    if(st<a-1) KPA(st,a-1);
    if(a+1<en) KPA(a+1,en);
}

void KPB(long st,long en)
{
    long a,b,c;
    a=st;b=en;c=Line[a];
    while(a<b)
    {
        while(a<b)
        {
            if(Weight[Line[b]]>Weight[c])
                {Line[a]=Line[b];break;}
            b--;
        }
        while(a<b)
        {
            if(Weight[Line[a]]<Weight[c])
                {Line[b]=Line[a];break;}
            a++;
        }
    }
    Line[a]=c;
    if(st<a-1) KPB(st,a-1);
    if(a+1<en) KPB(a+1,en);
}

int main()
{
    scanf("%ld %ld",&N,&M);
    long a,b,c;
    for(a=0;a<N;a++)
        scanf("%lf",&Apple[a]);
    for(a=0;a<M;a++)
        scanf("%lf",&Weight[a]);
    for(a=0;a<M;a++)
        Line[a]=a;
    KPA(0,N-1);KPB(0,M-1);
    memset(Weight,0,sizeof(Weight));
    for(a=0,b=0;a<N;a++)
    {
        Weight[Line[b]]+=Apple[a];
        b++;
        if(b==M)
            b=0;
    }
    for(a=0;a<M;a++)
        printf("%.0lf ",Weight[a]);
    return 0;
}
