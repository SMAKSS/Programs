//This Application have been programmed by Mustafa
//Allrights reserved by M2
#include <stdio.h>
#include <conio.h>
#include<math.h>

	int main() 
{
	char input[50],opr[24];
	int i,j,count,l,flag[26];
	float num[26],temp,dec_count;
	count=i=j=l=0;
	temp=0.0;
	puts("\t\t\t\t**Calculator**\n");
	puts("please enter an input to calculate:");
	gets(input);
	while(input[count]!='\0')   //Marhaleye jodasazi a'adad az amalgarha
	{ 
	    if(input[count]<'0' || input[count]>'9')
		{
			if(input[count]=='.')
			{
				dec_count=1.0;
				count++;
				temp=0;
			    while(input[count]>='0' && input[count]<='9')
			    {
				    temp+=(input[count]-'0')/powf(10.0,dec_count);
				    dec_count++;
				    count++;
			    }
				num[i]+=temp;
			}
			else
			{
			   opr[j++]=input[count++];
			   i++;
			   temp=0;
			}
		}
		else
		{
				
			temp=temp*10+(input[count]-'0');
			num[i]=temp;
			flag[i]=1;
			count++;
		}
		opr[j]='\0';
	}
	for(i=0;opr[i]!='\0';i++)       //anjam amalyat zarb va taghsim
	{
		if(opr[i]=='n')
		   continue;
		for(j=i+1;!flag[j];j++);    //finding the index of first number to operate
		for(l=j-1;!flag[l];l--);      //finding the index of second number to operate
	    if(opr[i]=='*')
		{
			opr[i]='n';
			num[j]=num[l]*num[j];
			flag[l]=0;
		}
		else if(opr[i]=='/')
		{
			opr[i]='n';
			num[j]=num[l]/num[j];
			flag[l]=0;
		}
	}
	for(i=0;opr[i]!='\0';i++)       //anjam amalyat jam'ava tafrigh
	{
		if(opr[i]=='n')
		   continue;
		for(j=i+1;!flag[j];j++);    //finding the index of first number to operate
		for(l=j-1;!flag[l];l--);      //finding the index of second number to operate
	    if(opr[i]=='+')
		{
			opr[i]='n';
			num[j]=num[l]+num[j];
			flag[l]=0;
		}
		else if(opr[i]=='-')
		{
			opr[i]='n';
			num[j]=num[l]-num[j];
			flag[l]=0;
		}
	}
	for(i=0;i<count;i++)
		if(flag[i])
		{
		   printf("\nThe result is : %f\n",num[i]);
		   break;
		}
	getch();
	return 0;
}


