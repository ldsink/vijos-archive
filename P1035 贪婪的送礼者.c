#include<stdio.h>

char names[10][15],tname[15];
int np,i,ng,j,present,togive,gp,rp;
int given[10],received[10];

int main()
{
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        scanf("%s",names[i]);
        given[i]=received[i]=0;
    }
    for(i=0;i<np;i++)
    {
        scanf("%s%d%d",tname,&present,&ng);
        for(gp=0;gp<np&&strcmp(names[gp],tname);gp++);
            if(ng)
            given[gp]+=present-present%ng,togive=present/ng;
        for(j=0;j<ng;j++)
        {
            scanf("%s",tname);
            for(rp=0;rp<np&&strcmp(names[rp],tname);rp++);
                received[rp]+=togive;
        }
    }
    for(i=0;i<np;i++)
            printf("%s %d\n",names[i],received[i]-given[i]);
    return 0;
} 
