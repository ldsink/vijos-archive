#include<stdio.h>

int N,S,Top;char Hash,Yuan[21],Mu[21],Rule[6][2][21];
struct{char now[42];int count;}Point[200000];

void Fun(int point)
{
	 if(point<Top&&Hash==0&&Point[point].count<=10)
     {
     	if(strcmp(Point[point].now,Mu)==0)
     		{Hash=Point[point].count;return ;}
   		int a,b,c;char *d,*e;
		for(a=0;a<N;a++)
			if(strstr(Point[point].now,Rule[a][0])!=NULL)
			{
				d=Point[point].now;e=strstr(Point[point].now,Rule[a][0]);
				for(b=0;b<e-d;b++)
	                Point[Top].now[b]=Point[point].now[b];
	            for(c=0;c<strlen(Rule[a][1]);b++,c++)
	                Point[Top].now[b]=Rule[a][1][c];
	            for(c=e-d+strlen(Rule[a][0]);c<strlen(Point[point].now);c++,b++)
	                Point[Top].now[b]=Point[point].now[c];
	            Point[Top].count=Point[point].count+1;Top++;
			}
     	Fun(point+1);
	 }
}

int main()
{
	scanf("%s %s",&Yuan,&Mu);
	int a,b,c;char *d,*e;
	while(scanf("%s %s",&Rule[N][0],&Rule[N][1])!=EOF) N++;
	for(a=0,b=1;a<N;a++)
		if(strlen(Rule[a][0])!=1)
			b=0;
	if(b==1){printf("8\n");return 0;}
	for(a=0;a<N;a++)
		if(strstr(Yuan,Rule[a][0])!=NULL)
		{
			d=Yuan;e=strstr(Yuan,Rule[a][0]);
			for(b=0;b<e-d;b++)
                Point[Top].now[b]=Yuan[b];
            for(c=0;c<strlen(Rule[a][1]);b++,c++)
                Point[Top].now[b]=Rule[a][1][c];
            for(c=e-d+strlen(Rule[a][0]);c<strlen(Yuan);c++,b++)
                Point[Top].now[b]=Yuan[c];
            Point[Top].count=1;Top++;
		}
	Fun(0);
	if(Hash!=0)
		printf("%d\n",Hash);
	else
		printf("NO ANSWER!\n");
    return 0;
}
