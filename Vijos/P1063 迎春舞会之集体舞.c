#include<stdio.h>

long N,L,Re[101][221];
char Map[101][221];

long Min(long a,long b)
{
	if(a>b) return b;
	else return a;
}

int main()
{
	scanf("%ld",&N);
	char temp;long i,j,k;
	temp=getchar();
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=2*N-i;j++)
		{
			Map[i][j]=getchar();
			if(Map[i][j]=='-')
				Re[i][j]=Min(Min(Re[i-1][j-1],Re[i-1][j]),Re[i-1][j+1])+1;
			else
				Re[i][j]=0;
			if(Re[i][j]>L&&(j+i)%2==0)	L=Re[i][j];
		}
		temp=getchar();
	}
	memset(Re,0,sizeof(Re));
	for(i=N;i>0;i--)
		for(j=1;i<=2*N-i;j++)
		{
			if(Map[i][j]=='-')
				Re[i][j]=Min(Min(Re[i+1][j-1],Re[i+1][j]),Re[i+1][j+1])+1;
			else
				Re[i][j]=0;
			if(Re[i][j]>L&&(j+i)%2==1)	L=Re[i][j];
		}
	printf("%ld\n",L*L);
	return 0;
}
