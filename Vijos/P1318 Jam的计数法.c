#include<stdio.h>

int s[100],p,i,j,n,w,t,tt,ss,time;
char m[100];

void fun()
{
     while(p>0&&time<5)
     {
        if(s[p]>tt)
            p--;
        else
            if(p==w)
            {
                time++;
                for(i=1;i<=p;i++) printf("%c",s[i]);
                printf("\n");
            }
            else
            {
                p++;
                s[p]=s[p-1];
            }
            s[p]++;
     }
}

int main()
{
    scanf("%d %d %d\n",&ss,&tt,&w);
    scanf("%s",m);
    for(i=0;i<w;i++)
        s[i+1]=m[i];
    s[w]++;
    tt+=96;
    ss+=96;
    p=w;
    fun();
    return 0;
}
