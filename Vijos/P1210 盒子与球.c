#include<stdio.h> 

int main()
{ 
    int n,r,f[20][100]={0}; 
    scanf("%d %d",&n,&r);
    int a,b;
    for(a=1;a<=n;a++) 
        f[a][1]=1; 
    for(a=2;a<=n;a++) 
        for(b=2;b<=r;b++) 
            f[a][b]=f[a-1][b-1]+f[a-1][b]*b;
    for(a=1;a<=r;a++) 
        f[n][r]*=a;
    printf("%d",f[n][r]); 
    return 0; 
}
