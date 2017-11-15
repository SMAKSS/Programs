#include <stdio.h>
#include <stdlib.h>

int main()
{
int n[10],a,i,b,j;
  printf("adad aval\n");
  scanf("%d",&n[0]);
     for(i=1;i<10;i++)
     {
       printf("adad ra vared kon:\n");
       scanf("%d",&a);
         for(j=0;j<i;j++)
           if(a<n[j])
            {     
             b=a;
             a=n[j];
             n[j]=b;
            }
          n[i]=a;
     }
  for(i=0;i<10;i++)
  printf("%d\n",n[i]);
     
    
  system("PAUSE");	
  return 0;
}
