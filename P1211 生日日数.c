#include<stdio.h>

int YY,MM,DD,day[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};

void run(int YY)
{
    if(0==YY%400 || 0==YY%4&&0!=YY%100)
        day[2]=29;
    else
        day[2]=28;
}

int main()
{
    int o;
    scanf("%d%d%d",&YY,&MM,&DD);
    run(YY);
    for(o=1;o<=10000;++o)
    {
        ++DD;
        if(DD>day[MM])
            DD=1,++MM;
        if(MM==13)
        {
            MM=1;
            ++YY;
            run(YY);
        }
    }
    printf("%d-%d-%d",YY,MM,DD);
    return 0;
}
