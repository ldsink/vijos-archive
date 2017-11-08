#include<stdio.h>

int n,site[15000][2],protect[15000],num[15000];

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d %d",&site[i][0],&site[i][1]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
        if(i!=j)
            if(site[i][0]>=site[j][0]&&site[i][1]>=site[j][1])
                protect[i]++;
        }
    for(i=0;i<n;i++)
        num[protect[i]]++;
    for(i=0;i<n;i++)
        printf("%d\n",num[i]);
    return 0;  
}
