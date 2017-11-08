#include<stdio.h>

int i,j,k,n,max,count,f[10000],a[10000],temp[10000];

int main()
{
      char ch;
      do
          {
          scanf("%d",&a[n]);
          ch=getchar();
          n++;
          }while(ch!='\n');
      for(i=0;i<n;i++)
         f[i]=1;
      for(i=n-2;i>=0;i--)
          {
          for(j=i+1;j<n;j++)
            if(a[j]<=a[i]&&f[j]+1>f[i])
                f[i]=f[j]+1;
          }
      for(i=0;i<n;i++)
          if(f[i]>max)
              max=f[i];
      printf("%d,",max);
      k=max;
      for(i=0;i<n;i++)
          if(f[i]==max)
              {;j=a[i];break;}
      for(;i<n;i++)
          if(f[i]==max&&j>=a[i])
              {
              j=a[i];
              a[i]=0;
              max--;
              }
      start:
      if(k!=n)
      {
          count++;
          for(i=0,j=0;i<n;i++)
              if(a[i]!=0)
              {temp[j]=a[i];j++;}
          memset(a,0,sizeof(a));
          for(i=0;i<j;i++)
              a[i]=temp[i];
          memset(f,0,sizeof(f));
          memset(temp,0,sizeof(temp));
          n=j;
          for(i=0;i<n;i++)
             f[i]=1;
          for(i=n-2;i>=0;i--)
              {
              for(j=i+1;j<n;j++)
                if(a[j]<=a[i]&&f[j]+1>f[i])
                    f[i]=f[j]+1;
              }
          for(i=0;i<n;i++)
              if(f[i]>max)
                  max=f[i];
          k=max;
          for(i=0;i<n;i++)
              if(f[i]==max)
                  {;j=a[i];break;}
          for(;i<n;i++)
              if(f[i]==max&&j>=a[i])
                  {
                  j=a[i];
                  a[i]=0;
                  max--;
                  }
          goto start;
      }
      printf("%d",count);
      return 0;
}
