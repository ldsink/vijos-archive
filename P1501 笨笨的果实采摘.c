#include<stdio.h>

char a[40000];int Nun0,Nun1,N;long i,j,k,u,d,All;

int main()
{
    long pow[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
    scanf("%d",&N);
    scanf("%ld %ld",&u,&d);
    getchar();gets(a);
    for(k=d;k<u+1&&k<N+1;k++)
        for(j=0;j<pow[N-k];j++)
        {
            Nun0=0;Nun1=0;
            for(i=0;i<pow[k];i++)
            {
                if(a[pow[k]*j+i]=='0')
                {
                    Nun0=1;
                    if(Nun1==1)
                        break;
                }
                if(a[pow[k]*j+i]=='1')
                {
                    Nun1=1;
                    if(Nun0==1)
                        break;
                }
            }
            if(Nun0==1&&Nun1==1)
                All=All+1;
            if(Nun0==0&&Nun1==1)
                All=All+2;
            if(Nun0==1&&Nun1==0)
                All=All+5;
        }
    printf("%ld",All);
    return 0;
}
