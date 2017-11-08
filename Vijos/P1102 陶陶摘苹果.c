#include<stdio.h>

int count,high,apple[10];

int main()
{
      int i;
      for(i=0;i<10;i++)
          scanf("%d",&apple[i]);
      scanf("%d",&high);
      for(i=0;i<10;i++)
          if(apple[i]<=30+high)
              count++;
      printf("%d",count);
      return 0;
}
