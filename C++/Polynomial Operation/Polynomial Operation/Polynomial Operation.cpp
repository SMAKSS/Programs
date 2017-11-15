// Polynomial Operation.cpp : Defines the entry point for the console application.
//
//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem Polynomial

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class poly {
public:
	double coeff;
	poly *next;
	poly(double c, poly* n) : coeff(c), next(n) { }
};

/**
 * Auxiliary method that displays the program menu.
 */
char makeChoice() {
	cout << "Choose what operation to do next:" << endl <<
			"f - Read the polynomial f" << endl <<
			"g - Read the polynomial g" << endl <<
			"c - Display the coefficient of a polynomial" << endl <<
			"d - Display the values of polynomials f and g" << endl <<
			"s - Compute the polynomial sum f+g" << endl <<
			"p - Compute the polynomial product f*g" << endl <<
			"q - Quit program" << endl;
	char c;
	cin >> c;
	return c;
}

/**
 * stringPoly(poly *f) computes a string representation of polynomial h
 */
string stringPoly(poly* h) {
	stringstream convert;
	if (h == 0)
		convert << "nil";
	else {
		int deg = 0;
		while( h != 0) {
			if (deg == 0) {
				convert << h->coeff;
			} else if (h->coeff < 0) {
				convert << " " << h->coeff <<"*x^" << deg;
			} else if (h->coeff > 0) {
				convert << " +" << h->coeff << "*x^" << deg;
			}
			deg++;
			h = h->next;
		}
	}
	return convert.str();
}

/**
 * clearPoly(poly *f) clears the memory allocated to store the dense representation of f
 */
void clearPoly(poly *f) {
	if(f != 0) {
		clearPoly(f->next);
		delete f;
	}
}

/**
 * auxiliary function that computes the degree of a polynomial.
 * A null polynomial is defined to have degree -1.
 */
int degree(poly *f) {
	if (f == 0)
		return -1;
	else return 1 + degree(f->next);
}

/**
 * auxiliary function that returns the coefficient of x^d in polynomial f.
 */
int coeff(poly *f, int d) {
	int deg = degree(f);
	if (deg < d)
		return 0;
	int i = 0;
	while (i != d) {
		f = f->next;
		i++;
	}
	return f->coeff;
}
/**
 * sum(poly *f, poly *g) computes the dense representation of the polynomial f+g
 */
poly *sum(poly *f, poly *g) {
	if (f == 0) return g;
	if (g == 0) return f;
	// TODO: allocate space for the dense representation of f+g, and compute it

    return 0;
}

/**
 * prod(poly *f, *poly *g) computes the dense representation of the polynomial f*g
 */
poly *prod(poly *f, poly *g) {
	// TODO
	return 0;
}

/**
 * Reads the coefficients of a polynomial from the console
 */
poly* readPoly(string polyName) {
	cout << "Enter the sequence of coefficients a_n ... a_1 a_0"
			<< " of " << polyName << endl << "separated by spaces:" << endl << endl;
	double coeff;
	poly *f = 0;
	string str="";
	while (str=="")
		getline(cin,str);
	stringstream ss(str);
	while (ss >> coeff) {
		f = new poly(coeff,f);
	}
	return f;
}

void selectPolyAndCoeff(char &c, int &i) {
	cout << "Choose the polynomial you want to analyze (f/g): ";
	c= ' ';
	while(c!='f' && c != 'g') {
		cin >> c;
	}
	cout << "Choose the power of x whose coefficient you want to know: ";
	cin >> i;
}

int main() {
	poly *f, *g, *h;
	f = 0; g = 0;
	char answer = makeChoice();
	while (answer != 'q') {
		switch (answer) {
		case 'f':
			clearPoly(f);
			f = readPoly("f");
			break;
		case 'g':
			clearPoly(g);
			g = readPoly("g");
			break;
		case 'd':
			cout << "f=" << stringPoly(f) << endl
			<< "g=" << stringPoly(g) << endl;
			break;
		case 's':
			h = sum(f,g);
			cout << "f+g=" << stringPoly(h) << endl;
			break;
		case 'c':
			char c;
			int i;
			selectPolyAndCoeff(c,i);
			switch(c) {
			case 'f':
				cout << "Coeff. of x^"<<i<<" in f is "<< coeff(f,i) << endl;
				break;
			case 'g':
				cout << "Coeff. of x^"<<i<<" in g is "<< coeff(g,i) << endl;
				break;
			}
			break;
		case 'p':
			h = prod(f,g);
			cout << "f*g=" << stringPoly(h) << endl;
			break;
		case 'q':
			continue;
		}
		answer = makeChoice();
	}
	return 0;
}