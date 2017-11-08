/*
Author ZHOU Cheng
Date 2010-3-14
Dijkstra
*/

#include<stdio.h>
#define MaxNum 1000000 //边权最大值

int N; //节点数目
int Dist[501]; //到节点1的最短路径值
int Data[501][501]; //邻接矩阵
char State[501]; //节点被搜索过状态指示

//查找权值最小的节点
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
    //初始化
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
			done++; //找到的点的数目加1
			State[node]=1; //标记已经找到了从节点1到节点node的最短路径
			for(var=1; var<=N; var++)//更新还没有找到的点的路径值
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
