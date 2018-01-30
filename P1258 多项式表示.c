#include<stdio.h>

int xiang[10],count,pan; 

void First(int a)
{
     if(a>1)
     {
         if(xiang[a]>0)
         {
             if(xiang[a]==1)
                 printf("x^%d",a);
             else
                 printf("%dx^%d",xiang[a],a);
             pan=1;
         }
         else if(xiang[a]<0)
         {
             if(xiang[a]==-1)
                 printf("-x^%d",a);
             else
                 printf("%dx^%d",xiang[a],a);  
             pan=1;
         }
         count--;
     }
     else
     {
         if(a==1)
         {
             if(xiang[a]>0)
             {
                 if(xiang[a]==1)
                     printf("x");
                 else
                     printf("%dx",xiang[a]);
                 pan=1;
             }
             else if(xiang[a]<0)
             {
                 if(xiang[a]==-1)
                     printf("-x");
                 else
                     printf("%dx",xiang[a]);  
                 pan=1;
             }
             count--;
         }
         else
         {
         printf("%d",xiang[a]);
         pan=1;
         count--;
         } 
     }
}

void Second(int a)
{
     if(a>1)
     {
         if(pan==1)
         {
             if(xiang[a]>0)
             {
                 if(xiang[a]==1)
                     printf(" + x^%d",a);
                 else
                     printf(" + %dx^%d",xiang[a],a);
             }
             else if(xiang[a]<0)
             {
                 if(xiang[a]==-1)
                     printf(" - x^%d",a);
                 else
                     printf(" - %dx^%d",-xiang[a],a);  
             }
             count--;
         }
         else
             First(a);
    }
    else
    {
        if(a==1)
        {
            if(pan==1)
             {
                 if(xiang[a]>0)
                 {
                     if(xiang[a]==1)
                         printf(" + x");
                     else
                         printf(" + %dx",xiang[a]);
                 }
                 else if(xiang[a]<0)
                 {
                     if(xiang[a]==-1)
                         printf(" - x",a);
                     else
                         printf(" - %dx",-xiang[a]);  
                 }
                 count--;
             }
             else
                 First(a);
        }
        else
        {
            if(pan==1)
             {
                 if(xiang[a]>0)
                 {
                     if(xiang[a]==1)
                         printf(" + 1");
                     else
                         printf(" + %d",xiang[a]);
                 }
                 else if(xiang[a]<0)
                 {
                     if(xiang[a]==-1)
                         printf(" - 1");
                     else
                         printf(" - %d",-xiang[a]);  
                 }
                 count--;
             }
             else
                 First(a);
        }
    }
}

int main()
{
    int i;
    for(i=8;i>=0;i--)
        scanf("%d",&xiang[i]);
    pan=0;count=8;
    First(count);
    while(count>=0)
        Second(count); 
    return 0;
} 
