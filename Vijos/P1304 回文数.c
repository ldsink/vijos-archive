#include<stdio.h>

char s[1000];
long n,i,a[1000],all,b[1000],c[1000];

int ok(long a[1000])
{
    long i;
    for(i=1;i<=a[0]/2;i++)
        if(a[i]!=a[a[0]-i+1])
            return 0;
    return 1;
}

void add(long a[1000],long b[1000])
{
     long i;
     for(i=1;i<=a[0];i++)
         b[i]=a[i]+a[a[0]-i+1];
     b[0]=a[0];
     for(i=1;i<b[0];i++)
     {
         b[i+1]+=b[i]/n;
         b[i]%=n;
     }
     while(b[b[0]]>=n)
     {
         b[b[0]+1]=b[b[0]]/n;b[b[0]]%=n;
         b[0]++;
     }
}

int main()
{
    scanf("%d\n",&n);
    gets(s);
    for(i=0;i<=9;i++)
        a[i+48]=i;
    for(i=10;i<=n;i++)
        a[i+55]=i;
    all=0;
    b[0]=strlen(s);
    for(i=1;i<=b[0];i++)
        b[i]=a[s[b[0]-i]];
    while(all<31)
    {
        if(ok(b))
        {
            printf("STEP=%d\n",all);
            return 0;
        }
        all++;
        add(b,c);
        for(i=0;i<=c[0];i++)
            b[i]=c[i];
    }
    printf("Impossible!");
    return 0;
}
