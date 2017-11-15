#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int calc(int z);
main()
{
   int a,k,i,count;
   count=0;
   printf("Enter The Number:\n");
   scanf("%d",&i);
   if(calc(i)==1)    
   {
        for (k=0;k<=i;k++)
        { 
           if (calc (k)==1)
           {
               printf("%d\t",k);
               count++;
           }
        }
       if (calc (count)==1)
           printf("yes");
       else
           printf("no");
    printf("\n%d",count);           
   }
   else
     printf("your number is not avval");
   getch();
}
int calc(int z)
{ 
     int count,x,w;
     count=0;
     for(x=1;x<=z;x++)
     {
       if(z%x==0)
         count++;
     }
     if(count==2)
          w=1;
          else 
          w=2;
     return w;
}