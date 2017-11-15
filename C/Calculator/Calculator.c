#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() 
{
	char a[20],b[10];//a Aadad vorodi,b adad khoroji ast
	int i,j,count,k,c[10];
	float num[10],temp,count1;
	count=i=j=k=0;
	temp=0.0;
	puts("Enter a number and their symbol you want to calculate:");
	gets(a);
	while(a[count]!='\0')//taghadom amaliat va jodasazi
	{ 
	  if(a[count]<'0' || a[count]>'9')
	   {
		if(a[count]=='.')
		 {
		  count1=1.0;
		  count++;
		  temp=0;
		  while(a[count]>='0' && a[count]<='9')
		  {
		   temp=(a[count]-'0')/powf(10.0,count1)+temp;
		   count1++;
		   count++;
		  }
		 num[i]+=temp;
		 }
	    else
	    {
	     b[j++]=a[count++];
	     i++;
	     temp=0;
	    }
      }
	 else
	 {
				
	  temp=temp*10+(a[count]-'0');
	  num[i]=temp;
	  c[i]=1;
	  count++;
	 }
	b[j]='\0';
	}
	for(i=0;b[i]!='\0';i++)       
	{
	 if(b[i]=='n')
	  continue;
	 for(j=i+1;!c[j];j++);    
	 for(k=j-1;!c[k];k--);      
	 if(b[i]=='*')
	 {
	  b[i]='n';
	  num[j]=num[k]*num[j];
	  c[k]=0;
	 }
	 else if(b[i]=='/')
	 {
	  b[i]='n';
	  num[j]=num[k]/num[j];
	  c[k]=0;
	 }
	}
	for(i=0;b[i]!='\0';i++)       
	{
	 if(b[i]=='n')
	  continue;
	 for(j=i+1;!c[j];j++);    
	 for(k=j-1;!c[k];k--);      
	 if(b[i]=='+')
	 {
	  b[i]='n';
	  num[j]=num[k]+num[j];
	  c[k]=0;
	 }
	 else if(b[i]=='-')
	 {
	  b[i]='n';
	  num[j]=num[k]-num[j];
	  c[k]=0;
  	 }
	}
	for(i=0;i<count;i++)
	 if(c[i])
	 {
	  printf("\nThe result is : %f",num[i]);
	  break;
	 }
	getch();
	return 0;
}


