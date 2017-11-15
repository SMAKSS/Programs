//
//program to convert temperature from celsius degree
//units into fahrenheit degree units:
//fahrenheit = celsius * (212 - 32)/100 + 32
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int nNumberofArgs, char* pszArgs[])
{
// Enter the temperature in celsius
 int celsius;
  cout << "Enter the temperature in celsius:";
  cin >> celsius;
// Calculate conversion factor for celsius
// to fahrenheit
 int factor;
  factor = 212 - 32;
// use conversion factor to convert celsius
// into fahrenheit values
 int fahrenheit;
  fahrenheit = factor * celsius/100 + 32;
// out put the resualt (follow in the new line)
  cout << "fahrenheit value is:";
  cout << fahrenheit << endl;
// wait until user is ready before terminating program
// to allow the user to see the program results
 system("pause");
 return 0;
}
