#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
 main()
{
 int k,i;
 float sum,count;
  sum=0;
  count=0;
  printf("Enter the number:\n");
  scanf("%d",&k);
  for(i=1;i<=k;i+=2)
    {
     sum=sum+pow(-1,count)*(1.0/i);
     count++;
  	}
  	sum=sum*4;
  	printf("%f is PI",sum);
      getch();
  return 0;
}
