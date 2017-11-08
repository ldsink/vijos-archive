#include<stdio.h>

int main()
{
    char temp;
    int a,b,i,j;
    for(i=0;i<10;i++)
    {
        j=0;
        while(1)
        {
            temp=getchar();
            if(temp==' ')
                break;
            a=temp-'0';
        }
        while(1)
        {
            temp=getchar();
            if(temp=='\n')
                break;
            b=temp-'0';
        }
        if(a%5==2||a%5==3)
            if(b%5==2||b%5==3)
                j=1;
        switch(j)
        {
        case 1:printf("Shadow\n");break;
        case 0:printf("Matrix67\n");break;
        }
    }
    return 0;
}
