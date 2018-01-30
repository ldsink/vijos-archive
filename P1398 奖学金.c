#include<stdio.h>

int num,score[300][4],count[300];

int Compare(int a,int b)
{
    if(score[count[b]][1]<=score[count[a]][1])
        count[b]=count[a];
    return b;
}

void Score()
{
     int max,i,j,k;
     for(max=0,i=0;i<num;i++)
         if(max<score[i][0])
             max=score[i][0];
     for(i=0,j=0;i<num;i++)
         if(max==score[i][0])
             {count[j]=i;j++;}
     if(j==1)
         {k=j;printf("%d %d\n",count[k-1]+1,score[count[k-1]][0]);}
     else
     {
         for(i=1;i<=j;i++)
             k=Compare(i-1,i);
         printf("%d %d\n",count[k-1]+1,score[count[k-1]][0]);
     }
     score[count[k-1]][0]=0;
}

int main()
{
    scanf("%d",&num);
    int i;
    for(i=0;i<num;i++)
        scanf("%d %d %d",&score[i][1],&score[i][2],&score[i][3]);
    for(i=0;i<num;i++)
        score[i][0]=score[i][1]+score[i][2]+score[i][3];
    for(i=0;i<5;i++)
        {memset(count,0,sizeof(count));Score();}
    return 0;
}
