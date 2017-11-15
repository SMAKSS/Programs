#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 100

int main() 
{
int a,b[size],i,sum,k,j;
    sum=0,j=0;
	printf("Enter your number\nyour number must be greather or equal to 1 and an integer\nafter you input the last number please press 0:\n");
	scanf("%d",&a);
	if(a>=1)
	{
	  while(b[j]!=0)
	  {
	    printf("Enter your other number:\n");
		scanf("%d",&b[j]); 
	  if(b[j]%a==0)
	   sum=sum+b[j];  
	  }
	  printf("\n%d is sum mazrabhaye %d",sum,a);
	}   
	else
	printf("your number must be greather or equal to 1");
	getch();	
	return 0;
}
