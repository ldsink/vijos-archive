#include<stdio.h>

int N,t,maxfi,fi[101],ti[101],save[101][1002];

int MaxHappy(int site,int time);
int Max(int a,int b);

int main()
{
    scanf("%d %d",&t,&N);
    int i;
    for(i=0;i<N;i++)
        scanf("%d %d",&ti[i],&fi[i]);
    maxfi=MaxHappy(0,t);
    printf("%d",maxfi);
    return 0;
}

int MaxHappy(int site,int time)
{
    if(save[site][time]==0)
        if(site<N&&time>0)
        {
            if(time>=ti[site])
                save[site][time]=Max(MaxHappy(site+1,time),
                fi[site]+MaxHappy(site+1,time-ti[site]));
            else
                save[site][time]=MaxHappy(site+1,time);
        }
    return save[site][time];
}

int Max(int a,int b)
{
    if(a<b)
        a=b;
    return a;
}
