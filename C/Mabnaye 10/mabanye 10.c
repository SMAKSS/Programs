#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
    int a,w,h,r,temp,sum,count; //a is number,w is base of number.
    sum=0;
    count=0;
    printf("Enter a number:\n");
    scanf("%d",&a);
    printf("Enter the base of number:\n");
    scanf("%d",&w);
    while(h!=0)
    {
        h=a/10;
        r=a%10;
        temp=r*(pow(w,count));
        sum=sum+temp;
        a=h;
        count++;
    }
    printf("The number you enterd is <%d> in mabnaye 10",sum);
    getch();
}
