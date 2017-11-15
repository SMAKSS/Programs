//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem 6.3-c


#include <cstdlib>
#include <iostream>

using namespace std;


int m,n;

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


int main(int argc, char *argv[])
{   cout << "Enter the lenght of array:" <<endl;
    cin >> m;
    cout << "Enter the width of array:" <<endl;
    cin >> n;
    int Y[m][n];
    cout << "Enter your number:" <<endl;
    for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++)
         cin >> Y[i][j];
    }
int  EXTRACT_MIN(Y[m][n]);
    system("PAUSE");
    return EXIT_SUCCESS;
}


