#include<stdio.h>

long M,S,T,Ans,A[3][300000],B[300000];

int main()
{
    scanf("%ld %ld %ld",&M,&S,&T);
    A[2][0]=M;
    for(Ans=1;Ans<=T;Ans++)
    {
        if(A[2][Ans-1]>=10)
        {
            A[1][Ans]=A[1][Ans-1]+60;
            A[2][Ans]=A[2][Ans-1]-10;
        }
        else
        {
            A[1][Ans]=A[1][Ans-1];
            A[2][Ans]=A[2][Ans-1]+4;
        }
        if(B[Ans-1]+17>A[1][Ans])
            B[Ans]=B[Ans-1]+17;
        else
            B[Ans]=A[1][Ans];
        if(B[Ans]>=S)
        {
            printf("Yes\n%d\n",Ans);
            return 0;
        }
    }
    printf("No\n%d\n",B[T]);
    return 0;
}
