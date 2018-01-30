#include<stdio.h>

int N,K,Ans,Re[201][201][6];

int Search(int last,int num,int team)
{
    if(team==K)
    {
        if(num>=last)
            return 1;
        else
            return 0;
    }
    if(Re[last][num][team]==0)
    {
        int temp;
        for(temp=last;temp<=num;temp++)
            Re[last][num][team]+=Search(temp,num-temp,team+1);
    }
    return Re[last][num][team];
}

int main()
{
    scanf("%d %d",&N,&K);
    Ans=Search(1,N,1);
    printf("%d\n",Ans);
    return 0;
}
