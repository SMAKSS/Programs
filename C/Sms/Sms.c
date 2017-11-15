#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
 int i;
  char str[100];
 printf("Enter your string:\n");
 gets(str);
 for(i=0;str[i]!='\0';i++)
 {
  switch (str[i])
  {
   case 'a':
    printf("2");
    break;
   case'b':
    printf("22");
    break;
   case'c':
    printf("222");
    break;
   case'd':
    printf("3");
    break;
   case'e':
    printf("33");
    break;
   case'f':
    printf("333");
    break;
   case'g':
    printf("4");
    break;
   case'h':
    printf("44");
    break;
   case'i':
    printf("444");
    break;
   case'j':
    printf("5");
    break;
   case'k':
    printf("55");
    break;
   case'l':
    printf("555");
    break;
   case'm':
    printf("6");
    break;
   case'n':
    printf("66");
    break;
   case'o':
    printf("666");
    break;
   case'p':
    printf("7");
    break;
   case'q':
    printf("77");
    break;
   case'r':
    printf("777");
    break;
   case's':
    printf("7777");
    break;
   case't':
    printf("8");
    break;
   case'u':
    printf("88");
    break;
   case'v':
    printf("888");
    break;
   case'w':
    printf("9");
    break;
   case'x':
    printf("99");
    break;
   case'y':
    printf("999");
    break;
   case'z':
    printf("9999");
    break;
   default:
	printf("0");
	break;	
 }
 printf(" ");
}
  getch();	
  return 0;
}
