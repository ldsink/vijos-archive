#include<stdio.h>

int M,N,T,cell[100][100],temp[100][100];

int Next(int i,int j)
{
    int count=0;
    if(i-1>=0&&j-1>=0&&cell[i-1][j-1]==1)
        count++;
    if(i-1>=0&&cell[i-1][j]==1)
        count++;
    if(i-1>=0&&j+1<M&&cell[i-1][j+1]==1)
        count++;
    if(j-1>=0&&cell[i][j-1]==1)
        count++;
    if(j+1<M&&cell[i][j+1]==1)
        count++;   
    if(i+1<N&&j-1>=0&&cell[i+1][j-1]==1)
        count++;
    if(i+1<N&&cell[i+1][j]==1)
        count++;
    if(i+1<N&&j+1<M&&cell[i+1][j+1]==1)
        count++;
    if(count<2)
        return 0;
    else if(count>3)
        return 0;
    else
        {
        if(count==3&&cell[i][j]==0)
            return 1;
        else
            return cell[i][j];
        }
}

int main()
{
    scanf("%d %d %d",&M,&N,&T);
    int i,j,k;
    char tempch;
    tempch=getchar();
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            tempch=getchar();
            cell[i][j]=tempch-'0';
        }
        tempch=getchar();
    }
    for(k=1;k<T;k++)
    {
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                temp[i][j]=Next(i,j);
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                cell[i][j]=temp[i][j];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            printf("%d",cell[i][j]);
        printf("\n");
    }
    return 0;
}
