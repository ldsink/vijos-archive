#include<stdio.h>

int main()
{
    int N,M,a;double f[60];
    scanf("%d %d",&N,&M); 
    memset(f,0,sizeof(f)); 
    f[4]=1;f[5]=1;
    for(a=6;a<=N+5;a++)
        f[a]=2*f[a-1]-f[a-M-1];
    printf("%.0lf",f[N+5]);
    return 0;
}
