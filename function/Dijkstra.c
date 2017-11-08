/*
Author ZHOU Cheng
Date 2010-3-14
Dijkstra
*/

#include<stdio.h>
#define MaxNum 1000000 //��Ȩ���ֵ

int N; //�ڵ���Ŀ
int Dist[501]; //���ڵ�1�����·��ֵ
int Data[501][501]; //�ڽӾ���
char State[501]; //�ڵ㱻������״ָ̬ʾ

//����Ȩֵ��С�Ľڵ�
int Findmin()
{
    int var,minnode=0, min=MaxNum;
    for(var=1;var<=N;var++)
        if ((Dist[var]<min) && (!State[var]))
        {
            min=Dist[var];
            minnode=var;
        }
    return minnode;
}

int main()
{
    freopen("Dijkstra.in","r",stdin);
	freopen("Dijkstra.out","w",stdout);
    scanf("%d",&N);
	int p,q;
    for(p=1; p<=N; p++)
        for(q=1; q<=N; q++)
        {
            scanf("%d",&Data[p][q]);
            if (Data[p][q]==0) Data[p][q]=MaxNum;
        }
    //��ʼ��
	int var;
    for(var=1; var<=N; var++)
        Dist[var]=Data[1][var];
	State[1]=1;
	int done=1;
	while (done<N)
	{
		int node=Findmin();
		if (node!=0)
		{
			done++; //�ҵ��ĵ����Ŀ��1
			State[node]=1; //����Ѿ��ҵ��˴ӽڵ�1���ڵ�node�����·��
			for(var=1; var<=N; var++)//���»�û���ҵ��ĵ��·��ֵ
				if ((Dist[var]>Dist[node]+Data[node][var]) && (!State[var]))
					Dist[var]=Dist[node]+Data[node][var];
		}
		else break;
	}
	for(var=1; var<=N; var++)
	{
		if (Dist[var]==MaxNum) printf("-1");
		else printf("%d",Dist[var]);
		if (var==N) printf("\n");
		else printf(" ");
	}
	return 0;
}
