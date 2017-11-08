#include<stdio.h>

int N,people[100][4]; 

void Left(int a);
void Right(int a);
int Min(int a,int b);

int main()
    {
    scanf("%d",&N);
    memset(people,0,sizeof(people));
    int i,j;
    for(i=0;i<N;i++)
        scanf("%d",&people[i][0]);
    N--;
    people[0][1]=0;
    people[N][2]=0;
    for(i=1;i<=N;i++)
        Left(i);
    for(i=N-1;i>=0;i--)
        Right(i);
    for(i=1,j=people[0][1]+people[0][2];i<=N;i++)
        {
        people[i][3]=people[i][1]+people[i][2];
        if(j>people[i][3])
            j=people[i][3];
        }
    printf("%d",j);
    return 0;
    } 

int Min(int a,int b)
{
    if(a>b)
        a=b;
    return(a); 
}

void Left(int a)
{
     int i,j,k;
     for(i=0,j=a;i<a;i++)
         if(people[a][0]>people[i][0])
             {j=a-i-1+people[i][1];break;}
     for(i=0;i<a;i++)
         if(people[a][0]>people[i][0])
         {
             k=a-i-1+people[i][1];
             j=Min(j,k);
         }
     people[a][1]=j;
}

void Right(int a)
{
     int i,j,k;
     for(i=a+1,j=N-a;i<=N;i++)
         if(people[a][0]>people[i][0])
             {j=i-a-1+people[i][2];break;}
     for(i=a+1;i<=N;i++)
         if(people[a][0]>people[i][0])
         {
             k=i-a-1+people[i][2];
             j=Min(j,k);
         }
     people[a][2]=j;
}
