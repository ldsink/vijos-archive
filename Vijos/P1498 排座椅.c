#include<stdio.h>

int M,N,K,L,D,x[1000],y[1000],record[1000];

void KP(int st,int en)
{
    int a,b,c,d;
    a=st,b=en;c=record[a];
    while(a<b)
    {
        while(a<b)
        {
            if(record[b]<c)
                {record[a]=record[b];break;}
            b--;
        }
        while(a<b)
        {
            if(record[a]>c)
                {record[b]=record[a];break;}
            a++;
        }
    }
    record[a]=c;
    if(st<a-1)
        KP(st,a-1);
    if(a+1<en)
        KP(a+1,en);
}

int main()
{
    scanf("%d %d %d %d %d",&M,&N,&K,&L,&D);
    int a,b,c,d,e;
    for(a=0;a<D;a++)
    {
        scanf("%d %d %d %d",&b,&c,&d,&e);
        if(b==d)
        {
            if(c>e)
                x[e]++;
            else
                x[c]++;
        }
        else
        {
            if(b>d)
                y[d]++;
            else
                y[b]++;
        }
    }
    for(d=0;K>0;K--)
    {
        for(a=1,b=0,c=0;a<M;a++)
            if(y[a]>b)
                {b=y[a];c=a;}
        if(y[c]==0)
            break;
        else
            {y[c]=0;record[d]=c;d++;}
    }
    KP(0,d-1);
    for(a=0;a<d;a++)
        printf("%d ",record[a]);
    printf("\n");
    for(d=0;L>0;L--)
    {
        for(a=1,b=0,c=0;a<N;a++)
            if(x[a]>b)
                {b=x[a];c=a;}
        if(x[c]==0)
            break;
        else
            {x[c]=0;record[d]=c;d++;}
    }
    KP(0,d-1);
    for(a=0;a<d;a++)
        printf("%d ",record[a]);
    return 0;
}
