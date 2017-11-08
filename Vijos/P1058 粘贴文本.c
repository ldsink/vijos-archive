#include<stdio.h>

int N,K,A[100001],B[100001],Temp[100001];

int main()
{
    scanf("%d %d",&N,&K);
    int a,b,c,d,e,st,en,in;
    for(a=1;a<=N;a++)
        A[a]=a;
    for(c=0,b=0;b<K;b++)
    {
        scanf("%d %d %d",&st,&en,&in); 
        if(c==0)
        {
            for(a=0,d=st;d<=en;d++,a++)
                {Temp[a]=A[d];A[d]=0;}
            for(a=1,d=a;a<=in;a++)
            {
                while(1)
                {
                    if(A[d]!=0)
                        {B[a]=A[d];d++;break;}
                    d++;
                }
            }
            for(e=0;e<=en-st;e++,a++)
                B[a]=Temp[e];
            for(;a<=N;a++)
                while(1)
                {
                    if(A[d]!=0)
                        {B[a]=A[d];d++;break;}
                    d++;
                }
            c=1;
        }
        else
        {
            for(a=0,d=st;d<=en;d++,a++)
                {Temp[a]=B[d];B[d]=0;}
            for(a=1,d=a;a<=in;a++)
            {
                while(1)
                {
                    if(B[d]!=0)
                        {A[a]=B[d];d++;break;}
                    d++;
                }
            }
            for(e=0;e<=en-st;e++,a++)
                A[a]=Temp[e];
            for(;a<=N;a++)
                while(1)
                {
                    if(B[d]!=0)
                        {A[a]=B[d];d++;break;}
                    d++;
                }
            c=0; 
        }
    }
    if(c==1)
    {
        for(a=1;a<=10;a++)
            printf("%d\n",B[a]);
    }
    else
    {
        for(a=1;a<=10;a++)
            printf("%d\n",A[a]);
    }
    return 0;
}
