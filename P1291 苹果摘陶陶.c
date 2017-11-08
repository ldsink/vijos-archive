#include<stdio.h>

int N,M,apple[2000],taotao[2000];


void KP(int start,int end,int *line)
{
    int a,b,c,d,e,f;
    a=start;b=end;c=a;d=line[c];
    while(a<b)
    {
        while(a<b)
        {
            if(line[b]<d)
                {line[c]=line[b];c=b;break;}
            b--;
        }
        while(a<b)
        {
            if(line[a]>d)
                {line[c]=line[a];c=a;break;}
            a++;
        }
    }
    line[c]=d;
    if(start<c-1)
        KP(start,c-1,line);
    if(c+1<end)
        KP(c+1,end,line);
}

int main()
{
    int a,b,c,d;
    scanf("%d %d",&N,&M);
    for(a=0;a<N;a++)
        scanf("%d",&apple[a]);
    for(a=0;a<M;a++)
        scanf("%d",&taotao[a]);
    KP(0,N-1,apple);
    KP(0,M-1,taotao);
    for(a=N-1,b=M,c=0;a>=0;a--)
    {
        while(b>=0)
        {
            b--;
            if(apple[a]>taotao[b]&&taotao[b]>0)
                break;
            else
                c++;
        }
    }
    c+=b;
    printf("%d",c);
    return 0;
}
