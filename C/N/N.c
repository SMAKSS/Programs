#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() 
{
int a,i,j,z,k;
	printf("Enter your number:\n");
	scanf("%d",&a);
	if(a>=3)
	 for(i=1;i<=a;i++)
	  {
	  k=a-i;
	  printf("*");
	  for(j=2;j<=i;j++)
	   printf(" ");
	  if((i!=1)&&(i!=a))
	   printf("*");
	  else
	   printf(" ");
      for(z=1;z<=k;z++)
       printf(" ");
      printf("*\n");
	
	  }
	else
	 printf("your number must be greather or equal to 3");
	getch();	
	return 0;
}
