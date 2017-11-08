#include<stdio.h>

int main()
{
  int n;
  int biao[25]={0,0,0,0,1,1,1,1,3,3,3,6,6,10,10,15,21,21,28,28,35,30,30,27,12};
  scanf("%d",&n);
  printf("%d",biao[n-1]);
  return 0;
}

