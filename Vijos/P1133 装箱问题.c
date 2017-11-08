#include<stdio.h>

int v,n,s,Space[30];
int Cal(int space,int site);
int Min(int a,int b);

int main()
{
      scanf("%d",&v);
      scanf("%d",&n);
      int i;
      for(i=0;i<n;i++)
          scanf("%d",&Space[i]);
      s=Cal(v,0);
      printf("%d",s);
      return 0;
}

int Cal(int space,int site)
{
    if(space==0)
        site=n;
    if(site==n)
        return space;
    else
    {
        int a,b;
        if(space>=Space[site])
            {
            a=Cal(space,site+1);
            b=Cal(space-Space[site],site+1);
            return Min(a,b);
            }
        else
            return Cal(space,site+1);
    }
}

int Min(int a,int b)
{
    if(a>b)
        a=b;
    return a;
}
