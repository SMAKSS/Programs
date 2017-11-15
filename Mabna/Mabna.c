#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define size 100

int mabna10(int z,int base1);
int main() 
{
int base,a,b,x,y,i,j,k[size];
  i=0;
   printf("Enter your number:\n");
   scanf("%d",&a);
   printf("Enter base of your input number:\n");
   scanf("%d",&base);
   printf("Enter base of your output number\nyour output base must be 2 or power of 2:\n");
   scanf("%d",&b);
   x=mabna10(a,base);
   while(x!=0)
	{
	 y=x/b;
	 k[i]=x%b;
	 x=y;
	 i++;
	}
	printf("\nnumber you entered in mabnaye %d is ",b);
   for(j=(i-1);j>=0;j--)
   {	
	if(k[j]==10)
	 printf("A");
	else if(k[j]==11)
	 printf("B");
	else if(k[j]==12)
	 printf("C"); 	
	else if(k[j]==13)
	 printf("D");
	else if(k[j]==14)
	 printf("E");
	else if(k[j]==15)
	 printf("F");
	else if(k[j]==16)
	 printf("G");
	else if(k[j]==17)
	 printf("H");
	else if(k[j]==18)
	 printf("I");
	else if(k[j]==19)
	 printf("J");
	else if(k[j]==20)
	 printf("K");
	else if(k[j]==21)
	 printf("L");
	else if(k[j]==22)
	 printf("M");
	else if(k[j]==23)
	 printf("N");
	else if(k[j]==24)
	 printf("O");
	else if(k[j]==25)
	 printf("P");
	else if(k[j]==26) 
	 printf("Q");
	else if(k[j]==27)  
	 printf("R");
	else if(k[j]==28) 
	 printf("S");
	else if(k[j]==29) 
	 printf("T");
	else if(k[j]==30) 
	 printf("U");
	else if(k[j]==31)
	 printf("V"); 
	else 
	 printf("%d",k[j]);
   }
 getch();
 return 0;
}
int mabna10(int z,int base1)
{
int h,w,count,x,sum;
 count=0;
 sum=0;
  while(z!=0)
  {
	h=z/10;
	w=z%10;
	x=w*(pow(base1,count));
	sum=sum+x;
	z=h;
	count++;
  }
  return sum;																    	
}  
