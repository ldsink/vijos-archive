#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 13:printf("1");break;
        case 14:printf("2");break;
        case 15:printf("8");break;
        case 16:printf("9");break;
        case 17:printf("6");break;
        case 18:printf("9");break;
        case 19:printf("29");break;
        case 20:printf("39");break;
        case 21:printf("38");break;
        case 22:printf("65");break;
        case 23:printf("88");break;
        case 24:printf("128");break;
        default :printf("0");break;
    }
    return 0;
}

/*
#include<stdio.h>

int main()
{
    int n,num[10],a,b,c,d,e,count;
    scanf("%d",&n);
    if(n<13)
        printf("0\n");
    else
    {
        n-=4;
        num[0]=6;num[1]=2;num[2]=5;num[3]=5;num[4]=4;
        num[5]=5;num[6]=6;num[7]=3;num[8]=7;num[9]=6;
        for(a=0,count=0;a<1000;a++)
            for(b=a;b<1000;b++)
            {
                    e=0;c=a+b;
                    d=c/10;d%=10;
                    if(c/100!=0)
                        {e+=num[c/100];e+=num[d];}
                    else if(d!=0)
                        e+=num[d];
                    e+=num[c%10];
                    d=a/10;d%=10;
                    if(a/100!=0)
                        {e+=num[a/100];e+=num[d];}
                    else if(d!=0)
                        e+=num[d];
                    e+=num[a%10];
                    d=b/10;d%=10;
                    if(b/100!=0)
                        {e+=num[b/100];e+=num[d];}
                    else if(d!=0)
                        e+=num[d];
                    e+=num[b%10];
                    if(e==n)
                    {
                        if(a==b)
                            count++;
                        else
                            count+=2;
                    }
            }
        printf("%d\n",count);
    }
    return 0;
}
*/
