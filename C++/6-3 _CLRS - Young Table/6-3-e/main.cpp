//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem 6.3-e

#include <cstdlib>
#include <iostream>

using namespace std;

int m,n;


int main(int argc, char *argv[])
{   
    cout << "Enter the lenght of array:" <<endl;
    cin >> m;
    cout << "Enter the width of array:" <<endl;
    cin >> n;
    int Y[m][n];
    cout << "Enter your number:" <<endl;
    for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++)
         cin >> Y[i][j];
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}


int DECREASE_KEY(int Y[50][50],int i,int j,int k){
 int temp;
 if (Y [i][j]<= k)
   return false;
 Y [i][j]=k;
 int threshold='\0';
 int largesti=i;
 int largestj=j;
 while(((i > 1) || (j > 1)) && (Y [i][j] < threshold)){
    temp =Y [i][j];
    Y [i][j]=Y [largesti][largestj];
    Y [largesti][largestj]=temp;
    i=largesti;
    j=largestj;
    if ((i - 1 >= 1) && Y [i][j] < Y [i - 1][j]){
       largesti=i - 1;
       largestj=j;
    }
    if ((j - 1 >= 1) && Y [largesti][largestj] < Y [i][j - 1]){
       largesti=i;
       largestj=j - 1;
       threshold=Y [largesti][largestj];
    }
 }
}

int INSERT(int Y[50][50],int k){
     DECREASE_KEY(Y, m, n, k);
}

int youngify(int N[50][50],int i,int j){
    int smallesti=i;
    int smallestj=j;
    int temp;
    if((i+1<=50)&&(N[i][j]>N[i+1][j])){
       smallesti=i+1;
       smallestj=j;
    }  
    if ((j + 1 < 50) && (N[smallesti][smallestj] > N [i] [j + 1])){
       smallesti=i;
       smallestj=j + 1;
    }    
    if ((smallesti != i) || (smallestj != j)){
      temp=N [i][j]; 
      N[i][j]=N [smallesti][smallestj];
      N [smallesti][smallestj]=temp;
    }
 return youngify(N, smallesti,smallestj);
}


int EXTRACT_MIN(int N[50][50]){
     int x;
     x=N [1][1];
     N [1][1]=1;
     youngify(N, 1, 1);
     return x;
}


int SORT(int A[]){    // A has length m = n^2 and Q is an empty n * n
    int Q[0][0];
    for(int i=1;i<m;i++)
      // Q[0][0].INSERT(A[i]);
    for(int i=1;i<m;i++)
     //  A[i]=Q[0][0].EXTRACT_MIN();
;}
