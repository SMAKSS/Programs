#include <stdio.h>
#include <stdlib.h>

void display(int a,int x,int y,int *p,int *pt);
char word(int a);
int main(int argc, char *argv[]) 
{
	int i,j,x,y,n,temp,ischecked=0,*p,*pt;
	p=&ischecked;
	pt=&temp;
	char *ptr;
	n=1;                  // for speed up testing of programm use this initial
	int board[8][8];/*={{ 8, 0,12, 0, 0, 0, 0, 8}, 
	                 { 7, 0, 0, 9,10, 0, 7, 0},
                     { 0, 0,10, 0, 0, 0, 0, 7},
	                 { 0, 7, 0, 9, 0, 7, 0, 0},
	                 { 0, 0, 1, 1, 0, 0, 0, 0},
                     { 0, 0, 0, 5, 0, 3, 4, 0},
	                 { 0, 1, 0, 0, 0, 1, 1, 1},
                     { 2, 11, 0, 0, 0, 0, 6, 0}};*/
	puts("\t\t\t\t**Chess**");
	puts("Please enter your board from up left to down right");
	puts("if you want enter numbers in line please use space");
	puts("and after each 8 number press enter on your keybord:");
	for(i=0;i<8;i++)
	{
        printf("\nPlease Enter Line %d\n",i+1);
	    for(j=0;j<8;j++)
			scanf("%d",&board[i][j]);
     }
		for(i=0;i<8;i++)
		    for(j=0;j<8;j++)
				if(board[i][j]==6)
				{
				   x=i;
				   y=j;
                 }
	printf("\nposition of the white king is %d %c\n",abs(x-7)+1,word(y));
	for(i=1;board[x][y-i]==0;i++);   //Left
	temp=board[x][y-i];
	if(temp==8 || temp==11 || temp==12 && i==1)
	   display(temp,x,y-i,p,pt);

    for(i=1;board[x][y+i]==0;i++);   //Right
	temp=board[x][y+i];
	if(temp==8 || temp==11 || temp ==12 && i==1)
	   display(temp,x,y+i,p,pt);
	   
    for(i=1;board[x-i][y]==0;i++);   //Up
	temp=board[x-i][y];
	if(temp==8 || temp==11 || temp ==12 && i==1)
	   display(temp,x-i,y,p,pt);
	   
    for(i=1;board[x+i][y]==0;i++);   //Down
	temp=board[x+i][y];
	if(temp==8 || temp==11 || temp ==12 && i==1)
	   display(temp,x+i,y,p,pt);
	   
    for(i=1;board[x-i][y+i]==0;i++);   //up Right
	temp=board[x-i][y+i];
	if(temp==7 && i==1 || temp==10 || temp==11 || temp ==12 && i==1)
	   display(temp,x-i,y+i,p,pt);
	   
    for(i=1;board[x-i][y-i]==0;i++);   //up Left
	temp=board[x-i][y-i];
	if(temp==7 && i==1 || temp==10 || temp==11 || temp ==12 && i==1)
	   display(temp,x-i,y-i,p,pt);
	   
    for(i=1;board[x+i][y+i]==0;i++);   //Down right
	temp=board[x+i][y+i];
	if(temp==10 || temp==11 || temp ==12 && i==1)
	   display(temp,x+i,y+i,p,pt);
	   
    for(i=1;board[x+i][y-i]==0;i++);   //Down left
	temp=board[x+i][y-i];
	if(temp==10 || temp==11 || temp ==12 && i==1)
	   display(temp,x+i,y-i,p,pt);
    if(board[x-2][y-1]==9)            //searching for knight
    {
       x-=2;
       y-=1;
    }
    else if(board[x-2][y+1]==9)
    {
         x-=2;
         y+=1;
     }   
    else if(board[x+2][y+1]==9)
    {
         x+=2;
         y+=1;
    }
    else if(board[x+2][y-1]==9)
    {
         x+=2;
         y-=1;
     }
    else if(board[x-1][y+2]==9)
    {
         x-=1;
         y+=2;
     }
    else if(board[x+1][y+2]==9)
    {
         x+=1;
         y+=2;
     }
    else if(board[x-1][y-2]==9)
    {
         x-=1;
         y-=2;
     }
    else if(board[x+1][y-2]==9)
    {
         x+=1;
         y-=2;
     }
     temp=board[x][y];
     if(temp==9)
        display(temp,x,y,p,pt);
    if(!ischecked)
       printf("No CHECK!\n");
	system("pause");	
	return 0;
}
void display(int a,int x,int y,int *p,int *pt)
{
     char name[10];
     char c;
     switch(a)
     {
              case 7:
                   strcpy(name,"PAWN");
                   break;
              case 8:
                   strcpy(name,"ROCK");
                   break;
              case 9:
                   strcpy(name,"KNIGHT");
                   break;
              case 10:
                   strcpy(name,"BISHOP");
                   break;
              case 11:
                   strcpy(name,"QUEEN");
                   break;
              case 12:
                   strcpy(name,"KING");
     }
     c=word(y);
     *p=1;
     *pt=0;
     x=abs(x-7);
     if(c)
     printf("\nBLACK %s AT %d, %c GAVE CHECK\n",name,x+1,c);
}
char word(int a)
{
     char c;
     switch (a+1)
     {
            case 1:
                 c='A';
                 break;
            case 2:
                 c='B';
                 break;
            case 3:
                 c='C';
                 break;
            case 4:
                 c='D';
                 break;
            case 5:
                 c='E';
                 break;
            case 6:
                 c='F';
                 break;
            case 7:
                 c='G';
                 break;
            case 8:
                 c='H';
                 break;
            default:
                 c='\0';
     }
     return c;
}