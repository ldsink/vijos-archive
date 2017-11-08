#include<stdio.h>

int main()
{
    int a,b,c,d,N,Num[10001]={0};
    scanf("%d",&N);
    for(a=0,c=0,d=0;a<N;a++)
    {
        scanf("%d",&b);
        Num[b]++;
        if(Num[b]==2)
        {
            if(c==0)
                c=b;
            else
            {
                c=0;d++;
                memset(Num,0,sizeof(Num));
            }
        }
        else if(Num[b]==4)
        {
             c=0;d++;
             memset(Num,0,sizeof(Num));
        }
    }
    printf("%d",d);
    return 0;
}
