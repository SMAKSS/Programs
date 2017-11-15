// Sparse Matrix Multiply.cpp : Defines the entry point for the console application.
//
//All Rights Reseverd by Programmer SMAli KSS
//F_Name: Seyed Mohammad ali, L_Name: Kazemi Sheikh Shabani
//Student ID: 92222004
//Problem Sparse Matrix Multiply

#include <stdio.h>
#include "stdafx.h"
#include <iostream>

using namespace std;

#define M 10
#define P 7
#define N 8

void ftrans( int a[][3], int b[][3] ) {
    /*
     * finds fast-transpose of a in b.
     */
int t[P+1];
    int i, j, n, terms;
    int temp, temp2;

    n = a[0][1];
    terms = a[0][2];
    b[0][0] = n;
    b[0][1] = a[0][0];
    b[0][2] = terms;

    if( terms <= 0 )
        return;
    for( i=0; i<n; ++i )
        t[i] = 0;
    for( i=1; i<=terms; ++i )
        t[a[i][1]]++;
    temp = t[0];
    t[0] = 1;
    for( i=1; i<n; ++i ) {
        temp2 = t[i], t[i] = t[i-1]+temp, temp = temp2;
        //printf( "t[%d] = %d.\n", i, t[i] );
    }
    for( i=1; i<=terms; ++i ) {
        j = t[a[i][1]];
        b[j][0] = a[i][1], b[j][1] = a[i][0], b[j][2] = a[i][2];
        t[a[i][1]] = j+1;
    }
}

void printMatrix( int a[][3] ) {
    /*
     * prints the matrix in the form of 3-tuples.
     */
int i;
    int nterms = a[0][2];

    printf( "rows=%d cols=%d vals=%d.\n", a[0][0], a[0][1], a[0][2] );
    for( i=1; i<=nterms; ++i )
        printf( "a[%d][%d] = %d.\n", a[i][0], a[i][1], a[i][2] );
    putchar( '\n' );
}

void insert( int c[][3], int row, int col, int val ) {
    /*
     * insert or add the triplet (row,col,val) in c.
     * update c[0][2] is necessary.
     */
int i, terms = c[0][2];

    for( i=1; i<=terms && c[i][0]<row; ++i )
        ;
    for( ; i<=terms && c[i][1]<col; ++i )
        ;
    if( i<=terms && c[i][1] == col )    // already inserted.
        c[i][2] += val;
    else {                    // a new entry should be inserted at i.
        c[i][0] = row; c[i][1] = col; c[i][2] = val;
        c[0][2]++;
    }
}

void mmult( int a[][3], int b[][3], int c[][3] ) {
    /*
     * c = a*b;
     */
int i=0, j=0, mn = M*N;
    int aterms = a[0][2], bterms = b[0][2];
    int rowsofb = b[0][0];
    int *t = (int *)malloc( rowsofb*sizeof(int) );
    int temp, temp2;
    int arow, acol, aval, brow, browstart, browend;

    c[0][0] = a[0][0];
    c[0][1] = b[0][1];

    // init c.for( i=0; i<=mn; ++i )
        c[i][2] = 0;

    // fill t[] : t[i] points to row of b where actual row i starts.// last+1 entry is also maintained for easing loops.for( i=0; i<=rowsofb; ++i )
        t[i] = 0;
    for( i=1; i<=bterms; ++i )
        t[b[i][0]]++;
    temp = t[0];
    t[0] = 1;
    for( i=1; i<=rowsofb; ++i ){
        temp2 = t[i], t[i] = t[i-1]+temp, temp = temp2;

    // now start mult.for( i=1; i<=aterms; ++i ) {
        arow = a[i][0]; acol = a[i][1]; aval = a[i][2];
        brow = acol;
        browstart = t[brow]; browend = t[brow+1];
        for( j=browstart; j<browend; ++j )
            insert( c, arow, b[j][1], aval*b[j][2] );
    }
}

int main() {
    int a[][3] =    {    
                        /*{4,5,4},
                        {0,0,1},
                        {0,1,2},
                        {1,0,3},
                        {1,1,4}*/

                        {4,2,3},
                        {0,1,2},
                        {1,0,3},
                        {3,1,4}
                        /*{7,7,8},
                        {1,1,15},
                        {1,4,22},
                        {1,6,-15},
                        {2,2,11},
                        {2,3,3},
                        {3,4,-6},
                        {5,1,91},
                        {6,3,28}*/

                    };
    int b[][3] =    {
                        /*{5,3,4},
                        {0,1,5},
                        {0,2,6},
                        {1,1,7},
                        {1,2,8}*/

                        {2,3,3},
                        {0,2,5},
                        {1,0,7},
                        {1,1,6}
                    };
    int c[M*N+1][3];

    printMatrix(a);
    //ftrans( a, b );
    printMatrix(b);
    mmult( a, b, c );
    printMatrix(c);

	system("PAUSE");
    return 0;
}

