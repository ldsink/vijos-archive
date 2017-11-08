#include<stdio.h>

int Map_min(const void*a,const void*b)
{
    return*(char*)a-*(char*)b;
}

int Map_max(const void*a,const void*b)
{
    return*(char*)b-*(char*)a;
}

int main()
{
    int i,j,k,t;
    char tmp_a[30],tmp_b[30];
    double n,a,b,res[10000];
    while((scanf("%lf",&n))==1)
    {
        res[0]=n;
        for(t=1;;)
        {
            sprintf(tmp_a,"%.0f",n);
            strcpy(tmp_b,tmp_a);
            qsort(tmp_a,strlen(tmp_a),sizeof(tmp_a[0]),Map_max);
            qsort(tmp_b,strlen(tmp_b),sizeof(tmp_b[0]),Map_min);
            for(a=b=0,j=0;j<strlen(tmp_a);++j)
                {a=(a*10+tmp_a[j]-'0');b=(b*10+tmp_b[j]-'0');}
            res[t++]=n=a-b;
            for(i=0;i<t-1;++i)
                if(n==res[i])
                    {k=i;n=-1;}
            if(n<0)
                break;
        }
        for(i=k;i<t-1;++i)
            printf("%.0lf",res[i]);
        puts("");
    }
    return 0;
}
