#include<stdio.h>

int main()
{
    int ISBN[10],i,j;
    char temp;
    i=0;
    while(i<10)
    {
        temp=getchar();
        if(temp!='-')
            if(i<9)
                {ISBN[i]=temp-'0';i++;}
            else
                {ISBN[i]=temp;i++;}
    }
    for(i=0,j=0;i<=8;i++)
        j+=(i+1)*ISBN[i];
    j%=11;
    if(j==10) j='X';
    else j+='0';
    if(j==ISBN[9])
        printf("Right");
    else
        printf("%d-%d%d%d-%d%d%d%d%d-%c",
        ISBN[0],ISBN[1],ISBN[2],ISBN[3],ISBN[4],ISBN[5],ISBN[6],ISBN[7],ISBN[8],j);
    return 0;
}
