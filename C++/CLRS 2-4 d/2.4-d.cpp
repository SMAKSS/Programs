//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem 2.4-d

#include <cstdio>
#include <iostream>

using namespace std;

void displayArray(int intarray[], int sizeOfarray)//show number in the array by index
{
     cout << "the value of the array after sort(merge_sort) is:" <<endl;
     for(int i=1;i<=sizeOfarray;i++)
     {
             cout.width(3);
             cout << i << ":" << intarray[i]<<endl;
     }
     cout<< endl;
} 
int m=0;//count the number of inversion
int a[50];//maximum lenght of array
void merge(int p,int q,int r){//p is 1st square, q is mid and r is last
 int h,i,j,b[50],k,;
 h=p;
 i=p;//if the rate of p is variable
 j=q+1;

 while((h<=q)&&(j<=r))
 {

  if(a[h]<=a[j])
  {  if((h<j)&&(a[h]>a[j])||((h>j)&&(a[h]<a[j])))//check for inversion
        m++;
   b[i]=a[h];
   h++;
  }
  
  else
  {if((i<j)&&(a[i]>a[j])||((i>j)&&(a[i]<a[j])))
        m++;
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>q)
 {if((h<q)&&(a[h]>a[q])||((h>q)&&(a[h]<a[q])))
        m++;
  for(k=j;k<=r;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {if((h<q)&&(a[h]>a[q])||((h>q)&&(a[h]<a[q])))
        m++;
  for(k=h;k<=q;k++)
  {
   b[i]=a[k];
   i++;
  }  
 }
 for(k=p;k<=r;k++){
     a[k]=b[k];
 } 
}


void merge_sort(int p,int r){//p is 1st square of array and r is last
     int q;//q is mid array square
     if(p<r){
       q = (p+r)/2;
       merge_sort(p,q);
       merge_sort(q+1,r);
       merge(p,q,r);
     }
}

int main(int argc, char *argv[])
{   int n,g;//n is array length, g is "for" variable
    do{
       cout << "Enter your array length:\n(Please don't select negative number)" <<endl;
       cin >> n;
      }while(n<0);
        cout << "Enter the "<<n<<" input number:" << endl;
    for(g=0;g<n;g++)
        cin >> a[g] ;
    merge_sort(0,n);
    displayArray(a,n);
    cout << "number of inversion is: " << m <<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

