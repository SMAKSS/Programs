#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int calc(int d);
main()
{int r,o,p;
  printf("Enter your Number:\n");
  scanf("%d",&r);
  if(calc(r)==2)
    {
      p=r/10;
    if(calc(p)==2)
     printf("%d is fara avval",r);
    }
    else
      printf("%d is not fara avval",r);
   getch();	
   return 0;
}
int calc(int d)
{ int m,k,i;
  k=0;
      for(i=1;i<=d;i++)
       {
        if(d%i==0)
        k++;
       }
        if(k==2)
        m=2;
        else
        m=0;      
        return m;
}