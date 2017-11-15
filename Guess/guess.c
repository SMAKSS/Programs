#include <stdio.h>
#include <stdlib.h>

int main() 
{
int s,n,i=1,e,a=0;
    printf("Enter start of your baze:\n");
	scanf("%d",&s);
	printf("Enter end of your baze:\n");
	scanf("%d",&e);
	 while(a!=1)
	 {
		n=(s+e)/2;
	    printf("#%d\nif your number is %d press 1\nelse if your number greather than %d press 2\nelse press 0\n",i,n,n);
		scanf("%d",&a);
		if(a==1)
	    printf("your number is %d",n);
	    else if(a==2)
		 s=n;
		else 
		 e=n;
		 i++;
   }
	getch();	
	return 0;
}
