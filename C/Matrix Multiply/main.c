/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem Sparse Matrix Multiply

#include<stdio.h>
#include "share.h"

int main()
{

  int i, j, k, n, pid, nproc, **a, **b, **c;
  int m=0, shmidc[10], sh6;
  int *ival, *jval, *kval, sh, sh2, sh3, sh4, sh5, shmid[10], shmidb[10];

        printf("Enter the size for the matrix :: ");
        scanf("%d",&n);


        *a=(int *)create_memory(sizeof(int)*n, &sh);
        for(i=0;i<n;i++)
                a[i]=(int *)create_memory(n*2, &shmid[i]);


        b=(int **)create_memory(n*sizeof(int),&sh2);
        for(i=0;i<n;i++)
                b[i]=(int *)create_memory(n*2, &shmidb[i]);  


        c=(int **)create_memory(n*2,&sh3);
        for(i=0;i<n;i++)
                c[i]=(int *)create_memory(n*2,&shmidc[i]);


        ival=(int *)create_memory(n*n*n*2, &sh4);
        jval =(int *)create_memory(n*n*n*2, &sh5);
        kval =(int *)create_memory(n*n*n*2, &sh6);

        printf("\nEnter the value of first matrix\n");


        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("Enter the value of a[%d][%d] :: ",i+1,j+1);
                        scanf("%d",&a[i][j]);
                }
        }

        printf("\nEnter the value of second matrix\n");



        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)      
                {
                        printf("Enter the value of b[%d][%d] :: ",i+1,j+1);
                        scanf("%d",&b[i][j]);
                }
        } 


      m=0;
       for(i=0;i<n;i++)
         {
          for(j=0;j<n;j++)
            {
              for(k=0;k<n;k++)
               {
                   ival[m]=i;
                   jval[m]=j;
                   kval[m]=k;
                   m++;
                 }
             }
        }
        
        printf("Enter the total number of processes :: ");
        scanf("%d",&nproc);         

        pid=create_process(&nproc);
        for(m=pid;m<n*n*n;m+=nproc)
        {
                i=ival[m];
                j=jval[m];
                k=kval[m];
                c[i][j] += a[i][k]*b[k][j];
        }
        join_process(&nproc,&pid);

        printf("\nThe resultant matrix is\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("%d\t",c[i][j]);
                }
                printf("\n");
        }
        for(i=0;i<n;i++)
        {
                cleanup_memory(&shmid[i]);    
                cleanup_memory(&shmidc[i]);
                cleanup_memory(&shmidb[i]);
        }
        cleanup_memory(&sh);
        cleanup_memory(&sh2);
        cleanup_memory(&sh3);
        cleanup_memory(&sh4);
        cleanup_memory(&sh5);
        cleanup_memory(&sh6);
        printf("\n");
		system("PAUSE");
        return 0;

}   
