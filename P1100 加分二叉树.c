#include<stdio.h>

int N,Num[31],Record[31][31],Score[31][31];

void Max(int a,int b)
{
     int c;
     if(a==b)
         {Record[a][b]=Num[a];Score[a][b]=a;return;}
     else if(a>b)
         {Record[a][b]=1;return;}
     if(Record[a][b])
         return;
     for(c=a;c<=b;c++)
     {
         Max(a,c-1);Max(c+1,b);
         if(Record[a][b]<Record[a][c-1]*Record[c+1][b]+Num[c])
         {
             Record[a][b]=Record[a][c-1]*Record[c+1][b]+Num[c];
             Score[a][b]=c;
         }
     }
}

void Tree(int p,int q)
{
     if(p>q)
         return;
     printf("%d ",Score[p][q]);
     Tree(p,Score[p][q]-1);
     Tree(Score[p][q]+1,q);
}

int main()
{
    int a,b;
    scanf("%d",&N);
    for(a=1;a<=N;a++)
        scanf("%d",&Num[a]);
    Max(1,N);
    printf("%d\n",Record[1][N]);
    Tree(1,N);
    printf("\n");
    return 0;
}
