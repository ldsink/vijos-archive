#include<stdio.h>

int main()
{
    int a,b,max,min,num[26]={0};char ch[102],temp;
    gets(ch);a=strlen(ch);
    for(b=0;b<a;b++)
    {
        temp=ch[b];
        temp-='a';
        num[temp]++;
    }
    for(b=0,min=999,max=0;b<26;b++)
    {
        max=max<num[b]?num[b]:max;
        if(num[b]!=0)
            min=min>num[b]?num[b]:min;
    }
    for(a=2,b=1;a<max-min;a++)
        if(max-min%a==0)
            {b=0;break;}
    if(b==1&&max-min!=1&&max-min!=0)
        printf("Lucky Word\n%d\n",max-min);
    else
        printf("No Answer\n0\n");
    return 0;
}
