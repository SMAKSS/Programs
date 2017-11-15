//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem 6.3-d

#include <cstdlib>
#include <iostream>

int m,n;

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


using namespace std;

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







