/*
Author ZHOU Cheng
Date 2010-3-14
Quicksort
*/

#include<stdio.h>

int N,Num[1994];

void Qsort(int st,int en,int *line)
{
	int a,b,c;
	a=st;b=en;c=line[st];
	while(a<b)
	{
		while(a<b)
		{
			if(line[b]<c)
				{line[a]=line[b];break;}
			b--;
		}
		while(a<b)
		{
			if(line[a]>c)
				{line[b]=line[a];break;}
			a++;
		}
	}
	line[a]=c;
	if(st<a-1) Qsort(st,a-1,line);
	if(a+1<en) Qsort(a+1,en,line);
}

int main()
{
	freopen("Quicksort.in","r",stdin);
	freopen("Quicksort.out","w",stdout);
	int var;
	scanf("%d",&N);
	for(var=0;var<N;var++)
		scanf("%d",&Num[var]);
	Qsort(0,N-1,Num);
	for(var=0;var<N-1;var++)
		printf("%d ",Num[var]);
	printf("%d\n",Num[var]);
	return 0;
}
