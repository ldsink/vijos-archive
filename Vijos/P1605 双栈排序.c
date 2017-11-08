#include<stdio.h>

int N,Switch,In[1000],Color[1000],SPFA[1000][1000];

void DFS(int site,int color)
{
    int a,b;
    Color[site]=color;
    color=color>1?1:2;
    for(a=1;a<=SPFA[site][0];a++)
        if(Color[SPFA[site][a]]==0)
            DFS(SPFA[site][a],color);
        else if(Color[SPFA[site][a]]==Color[site])
            {Switch=0;break;}
}

void Pan()
{
    if(Switch<N)
    {
    if(SPFA[0][SPFA[0][0]]==Switch)
        {Switch++;SPFA[0][0]--;printf("b ");Pan();}
    else if(SPFA[1][SPFA[1][0]]==Switch)
        {Switch++;SPFA[1][0]--;printf("d ");Pan();}
    }
}

int main()
{
    scanf("%d",&N);
    int a,b,c;
    for(a=0;a<N;a++)
        {scanf("%d",&In[a]);In[a]--;}
    for(a=0;a<N;a++)
        for(b=a+1;b<N;b++)
            if(In[b]>In[a])
                for(c=b+1;c<N;c++)
                    if(In[c]<In[a])
                    {
                        SPFA[In[a]][0]++;
                        SPFA[In[a]][SPFA[In[a]][0]]=In[b];
                        SPFA[In[b]][0]++;
                        SPFA[In[b]][SPFA[In[b]][0]]=In[a];
                    }
    for(Switch=1,a=0;a<N&&Switch==1;a++)
        if(Color[a]==0)
            DFS(a,1);
    if(Switch==0)
        printf("0\n");
    else
    {
        Switch=0;
        memset(SPFA,0,sizeof(SPFA));
        //此处SPFA用来存 栈A 和 栈B。
        //SPFA[0][0] 栈A top;
        //SPFA[1][0] 栈B top;
        for(a=0;a<N;a++)
        {
        if(In[a]==Switch)
            {printf("a b ");Switch++;Pan();}
        else if(SPFA[0][0]==0)
            {SPFA[0][0]++;SPFA[0][SPFA[0][0]]=In[a];printf("a ");}
        else if(Color[SPFA[0][SPFA[0][0]]]!=Color[In[a]])
            {SPFA[1][0]++;SPFA[1][SPFA[1][0]]=In[a];printf("c ");}
        else
            {SPFA[0][0]++;SPFA[0][SPFA[0][0]]=In[a];printf("a ");}
        }
    }
    return 0;
}
