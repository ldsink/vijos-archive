#include<stdio.h>

int N;double D1,D2,C,Max,D[500],P[500];

void Search(int station,double num,double ans)
{
    int a;double b,c;
    if(station==N)
    {
        b=D1-D[N];
        if(b>Max)
            {printf("-1\n");return ;}
        else
        {
            b/=D2;
            if(num>=b)
                {printf("%.2lf\n",ans);return ;}
            else
                {b-=num;printf("%.2lf\n",ans+b*P[N]);return ;}
        }
    }
    else
    {
        b=D[station+1]-D[station];
        if(b>Max)
            {printf("-1\n");return ;}
        else if(P[station+1]<P[station])
        {
            b/=D2;
            if(num>=b)
                Search(station+1,num-b,ans);
            else
                Search(station+1,0,ans+(b-num)*P[station]);
        }
        else
        {
            for(a=station+1;a<=N;a++)
                if(D[a]-D[station]<=Max&&P[a]<P[station])
                    break;
            if(a==N+1)
            {
                b=D1-D[station];
                if(b<=Max)
                {
                    b/=D2;
                    if(num>=b)
                        {printf("%.2lf\n",ans);return ;}
                    else
                        {printf("%.2lf\n",ans+(b-num)*P[station]);return ;}
                }
                else
                {
                    b=D[station+1]-D[station];b/=D2;
                    Search(station+1,C-b,ans+(C-num)*P[station]);
                }
            }
            else
            {
                b=D[a]-D[station];b/=D2;
                if(num>=b)
                    Search(a,num-b,ans);
                else
                    Search(a,0,ans+(b-num)*P[station]);
            }
        }
    }
}

int main()
{
    scanf("%lf %lf %lf %lf %d",&D1,&C,&D2,&P[0],&N);
    int a,b;
    for(a=1;a<=N;a++)
        scanf("%lf %lf",&D[a],&P[a]);
    Max=D2*C;Search(0,0,0);
    return 0;
}
