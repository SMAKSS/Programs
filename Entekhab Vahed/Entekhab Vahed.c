#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size_s 500
#define size_t 100
#define size_l 50

struct stu
{int codemeli,codeD;
 char name[size_s];
 char surename[size_s];
};
struct tea
{int code;
 char name[size_t];
 char surename[size_t];
 char field[size_t];
};
struct les
{int code,unit;
 char name[size_l];
};
 
void Add_s(struct stu *ptr);
void Add_t(struct tea *ptr);
void Add_l(struct les *ptr);
int search(struct stu *pis,struct tea *pit,struct les *pil,int sc,int ac);
    
int main()
{ int a,b;
 aa: printf("Please select the following item:\n\n1-Student\t\t2-Teacher\n\n3-Lesson\t\t4-Search\n\n5-Report\t\t6-Exit\n");
     scanf("%d",&a);
     printf("Please select option you want to do it:\n\n1-Add\t\t\t2-Delete\n\n3-Search\t\t4-Report\n\n5-Back to up\t\t6-Exit\n");
     scanf("%d",&b);
 struct stu s[size_s],*ps;
 struct tea t[size_t],*pt;
 struct les l[size_l],*pl;
 ps=&s[0];
 pt=&t[0];
 pl=&l[0]; 
 search(ps,pt,pl,0,1);
 if((a==1)&&(b==1))
  Add_s(ps);
 if((a==2)&&(b==1))
  Add_t(pt);
 if((a==3)&&(b==1))
  Add_l(pl);
 if(b==5)
  goto aa;
 getch();	
 return 0;
}

void Add_s(struct stu *ptr)
{
     int i;
     for(i=0;i<size_s;i++)
     {
        puts("\nEnter name:");
        scanf("%s",&ptr->name);
        if(ptr->name[0]=='*')
           break;
        puts("Enter SureName:");
        scanf("%s",&ptr->surename);
        puts("Enter Code Meli:");
        scanf("%d",&ptr->codemeli);
        puts("Enter code Daneshjuie:");
        scanf("%d",&ptr->codeD);
        ptr++;
     }
        
}
void Add_t(struct tea *ptr)
{
     int i;
     for(i=0;i<size_t;i++)
     {
        puts("\nEnter name:");
        scanf("%s",&ptr->name);
        if(ptr->name[0]=='*')
           break;
        puts("Enter SureName:");
        scanf("%s",&ptr->surename);
        puts("Enter Code:");
        scanf("%d",&ptr->code);
        puts("Enter Field:");
        scanf("%s",&ptr->field);
        ptr++;
     }
        
}
void Add_l(struct les *ptr)
{
     int i;
     for(i=0;i<size_l;i++)
     {
        puts("\nEnter name:");
        scanf("%s",&ptr->name);
        if(ptr->name[0]=='*')
           break;
        puts("Enter Code:");
        scanf("%d",&ptr->code);
        puts("Enter Unit:");
        scanf("%d",&ptr->unit);
        ptr++;
     }
        
}
int search(struct stu *pis,struct tea *pit,struct les *pil,int sc,int ac)
{
    int index=-1,i;
    switch(ac)
    {
       case 1:
            for(i=0;i<size_s || (pis++)->codeD!=sc;i++);
            break;
       case 2:
            for(i=0;i<size_t || (pit++)->code!=sc;i++);
            break;
       case 3:
            for(i=0;i<size_l || (pil++)->code!=sc;i++);
            break;
    }
    return index;
}
