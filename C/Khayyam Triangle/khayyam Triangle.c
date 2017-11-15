#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fact(int z);
int main() 
{
  int sum1,sum2,sum,i,n,j;
   printf("Enter the number of line:\n");
   scanf("%d",&n);
   for(j=0;j<=n;j++)
   {
	for(i=0;i<=j;i++)
    {
	 sum1 = fact(j);
	 sum2 = (fact(j-i)*fact(i));
	 sum = sum1/sum2;
	 printf("%d\t",sum);
    }
    printf("\n");
   }
	getch();	
	return 0;
}
int fact(int z)
{
 int sum1,sum;
  sum = sum1 = 1;
  while(z!=0)
  {
   sum1 = z;
   sum = sum * sum1;
   z = z-1;
  }
 return sum;  		
}
