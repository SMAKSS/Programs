// PostFix.cpp : Defines the entry point for the console application.
//
//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem postfix

/* Introduction (please read before use the program):
when you run the program you should enter your first number then press enter then enter the second number
then enter then choose your operator like (+,-,*,/) after this you can enter the another number and then 
again choose your operator or press q to quit!
thank before to read this.
*/

#include "stdafx.h"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
#include "stdio.h"

using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, stack<double>& calcstack);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Welcome to postfix Calculator" << endl;
	stack<double> calcStack;
	string input;
	while(true)
	{
		cout << ">>";
		cin >> input;
		//check for numeric value
		double num;
		if(istringstream(input) >> num)
		
			calcStack.push(num);
		//check for operator
		else if(isOperator(input))
		
			performOp(input, calcStack);
		//check for quit
		else if (input == "q")
		
			return 0;
		//invalid input
		else
			cout << "Invalid input"<< endl;
	
		{

		}

	}
}

bool isOperator(const string& input)
{
	string ops [] = {"-","+","*","/"};
	for(int i=0;i<4;i++)
	{
		if(input == ops[i])
		{
			return true;
		}
	}
	return false;
}

void performOp(const string& input, stack<double>& calcStack)
{
	double lVal,rVal,result;
	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if(input == "-")

		result = lVal - rVal;

	else if(input == "+")

		result = lVal + rVal;

	else if(input == "*")

		result = lVal *rVal;

	else

		result = lVal /rVal;

	cout << result <<endl;
	calcStack.push(result);
}