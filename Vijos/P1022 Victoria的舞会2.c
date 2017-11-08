#include<stdio.h>

int N,M,Index[201][201],Pan[201];

void Search(int site)
{
    Pan[site]=1;
    int a;
    for(a=1;a<=Index[site][0];a++)
        if(Pan[Index[site][a]]==0)
            Search(Index[site][a]);
}

int main()
{
    scanf("%d",&N);
    int a,b,c;
    for(a=0;a<N;a++)
    {
        scanf("%d",&b);
        while(b!=0)
        {
            Index[a+1][0]++;
            Index[a+1][200]=1;
            Index[a+1][Index[a+1][0]++]=b;
            Index[b][0]++;
            Index[b][200]=1;
            Index[b][Index[b][0]]=a+1;
            scanf("%d",&b);
        }
    }
    for(a=1,b=0,c=0;a<=N;a++)
        if(Index[a][200]==0)
            {Search(a);c++;}
    b=1;
    while(b==1)
    {
    for(a=1,b=0;a<=N;a++)
        if(Pan[a]==0)
            {b=1;Search(a);c++;break;}
    }
    printf("%d",c);
    return 0;
}
