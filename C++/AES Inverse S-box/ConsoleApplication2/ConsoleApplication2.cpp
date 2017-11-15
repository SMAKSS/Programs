// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


// If you using Microsoft Visual Studio you must add "stdafx.h" library to your program. because you must do their standards!
// Like this :
#include "stdafx.h"

// Include stdio.h for standard input/output.
// Used for giving output to the screen.
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <conio.h>

using namespace std;

int texttohex(unsigned char);

// The number of columns comprising a state in AES.
#define Nb 4

// The number of rounds in AES Cipher.
int Nr = 0;

// The number of 32 bit words in the key.
int Nk = 0;

// in - array hold the plaintext
// out - array to keep our output data after encryption.
// state - the array that holds the intermediate results during encryption.
unsigned char in[16], out[16], state[4][4];

// The array that stores the round keys.
unsigned char RoundKey[240];

// The Key input to the AES Program
unsigned char Key[32];

int getSBoxValue(int num)
{
	//http://en.wikipedia.org/wiki/Rijndael_S-box
	int sbox[256] = {
		//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
		0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,  //0
		0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,  //1
		0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,  //2
		0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,  //3
		0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,  //4
		0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,  //5
		0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,  //6
		0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,  //7
		0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,  //8
		0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,  //9
		0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,  //A
		0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,  //B
		0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,  //C
		0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,  //D
		0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,  //E
		0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D }; //F
	return sbox[num];
}

// The round constant word array, Rcon[i], contains the values given by 
// x to the power (i-1) being powers of x (x is denoted as {02}) in the field GF(28)
// Note that i starts at 1, not 0).
//http://en.wikipedia.org/wiki/Rijndael_key_schedule
int Rcon[255] = {
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
	0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
	0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
	0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
	0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
	0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
	0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
	0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
	0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
	0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
	0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
	0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
	0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
	0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
	0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
	0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb };

// This function produces Nb(Nr+1) round keys. The round keys are used in each round to encrypt the states. 
void KeyExpansion()
{
	int i, j;
	unsigned char temp[4], k;

	// The first round key is the key itself.
	for (i = 0; i<Nk; i++)
	{
		RoundKey[i * 4] = Key[i * 4];
		RoundKey[i * 4 + 1] = Key[i * 4 + 1];
		RoundKey[i * 4 + 2] = Key[i * 4 + 2];
		RoundKey[i * 4 + 3] = Key[i * 4 + 3];
	}

	// All other round keys are found from the previous round keys.
	while (i < (Nb * (Nr + 1)))
	{
		for (j = 0; j<4; j++)
		{
			temp[j] = RoundKey[(i - 1) * 4 + j];
		}
		if (i % Nk == 0)
		{
			// This function rotates the 4 bytes in a word to the left once.
			// [a0,a1,a2,a3] becomes [a1,a2,a3,a0]

			// Function RotWord()
			{
				k = temp[0];
				temp[0] = temp[1];
				temp[1] = temp[2];
				temp[2] = temp[3];
				temp[3] = k;
			}

			// SubWord() is a function that takes a four-byte input word and 
			// applies the S-box to each of the four bytes to produce an output word.

			// Function Subword()
			{
			temp[0] = getSBoxValue(temp[0]);
			temp[1] = getSBoxValue(temp[1]);
			temp[2] = getSBoxValue(temp[2]);
			temp[3] = getSBoxValue(temp[3]);
		}

			temp[0] = temp[0] ^ Rcon[i / Nk];
		}
		else if (Nk > 6 && i % Nk == 4)
		{
			// Function Subword()
			{
				temp[0] = getSBoxValue(temp[0]);
				temp[1] = getSBoxValue(temp[1]);
				temp[2] = getSBoxValue(temp[2]);
				temp[3] = getSBoxValue(temp[3]);
			}
		}
		RoundKey[i * 4 + 0] = RoundKey[(i - Nk) * 4 + 0] ^ temp[0];
		RoundKey[i * 4 + 1] = RoundKey[(i - Nk) * 4 + 1] ^ temp[1];
		RoundKey[i * 4 + 2] = RoundKey[(i - Nk) * 4 + 2] ^ temp[2];
		RoundKey[i * 4 + 3] = RoundKey[(i - Nk) * 4 + 3] ^ temp[3];
		i++;
	}
}

// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void AddRoundKey(int round)
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			state[i][j] ^= RoundKey[round * Nb * 4 + i * Nb + j];
		}
	}
}


// The SubBytes Function Substitutes the values in the
// state matrix with values in an S-box.
void SubBytes()
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			state[i][j] = getSBoxValue(state[i][j]);

		}
	}
}

// The ShiftRows() function shifts the rows in the state to the left.
// Each row is shifted with different offset.
// Offset = Row number. So the first row is not shifted.
void ShiftRows()
{
	unsigned char temp;

	// Rotate first row 1 columns to left	
	temp = state[1][3];
	state[1][3] = state[1][2];
	state[1][2] = state[1][1];
	state[1][1] = state[1][0];
	state[1][0] = temp;

	// Rotate second row 2 columns to left	
	temp = state[2][2];
	state[2][2] = state[2][0];
	state[2][0] = temp;

	temp = state[2][3];
	state[2][3] = state[2][1];
	state[2][1] = temp;

	// Rotate third row 3 columns to left
	temp = state[3][0];
	state[3][0] = state[3][1];
	state[3][1] = state[3][2];
	state[3][2] = state[3][3];
	state[3][3] = temp;
}


// MixColumns function mixes the columns of the state matrix
void MixColumns()
{
	int i;
	for (i = 0; i<4; i++)
	{
		state[i][0] = (state[i][0] * 'E') ^ (state[i][1] * 'B') ^ (state[i][2] * 'D') ^ (state[i][3] * '9');
		state[i][0] = (state[i][0] * '9') ^ (state[i][1] * 'E') ^ (state[i][2] * 'B') ^ (state[i][3] * 'd');
		state[i][0] = (state[i][0] * 'D') ^ (state[i][1] * '9') ^ (state[i][2] * 'E') ^ (state[i][3] * 'b');
		state[i][0] = (state[i][0] * 'B') ^ (state[i][1] * 'D') ^ (state[i][2] * '9') ^ (state[i][3] * 'e');
	}
}

// Cipher is the main function that encrypts the PlainText.
void Cipher()
{
	int i, j, round = 0;

	//Copy the input PlainText to state array.
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			state[j][i] = in[i * 4 + j];
		}
	}

	// Add the First round key to the state before starting the rounds.
	AddRoundKey(0);

	// There will be Nr rounds.
	// The first Nr-1 rounds are identical.
	// These Nr-1 rounds are executed in the loop below.
	for (round = 1; round<Nr; round++)
	{
		SubBytes();
		ShiftRows();
		MixColumns();
		AddRoundKey(round);
	}

	// The last round is given below.
	// The MixColumns function is not here in the last round.
	SubBytes();
	ShiftRows();
	AddRoundKey(Nr);

	// The encryption process is over.
	// Copy the state array to output array.
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			out[i * 4 + j] = state[j][i];
		}
	}
}
int main()
{
	int i;

	// Recieve the length of key here.
	while (Nr != 128 && Nr != 192 && Nr != 256)
	{
		printf("Enter the length of Key(128, 192 or 256 only): ");
		scanf_s("%d", &Nr);
	}

	// Calculate Nk and Nr from the recieved value.
	Nk = Nr / 32;
	Nr = Nk + 6;


	/*
	// Part 1 is for demonstrative purpose. The key and plaintext are given in the program itself.
	// 	Part 1: ********************************************************

	// The array temp stores the key.
	// The array temp2 stores the plaintext.
	unsigned char temp[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
	unsigned char temp2[32] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };

	// Copy the Key and PlainText
	for (i = 0; i<Nk * 4; i++)
	{
	Key[i] = temp[i];
	in[i] = temp2[i];
	}

	//	       *********************************************************
	*/


	// Methode 2 if you need to read key and plaintext from the keyboard.
	// 	Part 2: ********************************************************

	//Clear the input buffer
	//flushall();

	//Recieve the key from the user
	int size1, size2;
	cout << "Enter size of your key without sapce: ";
	cin >> size1;
	printf("Enter the Key: ");
	for (i = 0; i < size1; i++){
		scanf_s("%s", &Key[i]);
	}
	for (int jj = 0; jj < Nk * 4; jj++)
		Key[jj] = texttohex(Key[jj]);

	//Recieve Plaintext from user
	cout << "Enter size of your text without sapce: ";
	cin >> size2;
	printf("Enter the PlainText: ");
	for (i = 0; i < size2; i++){
		scanf_s("%s", &in[i]);
	}
	for (int jj = 0; jj < Nb * 4; jj++)
		in[jj] = texttohex(in[jj]);

	// 	        ********************************************************


	// The KeyExpansion routine must be called before encryption.
	KeyExpansion();

	// The next function call encrypts the PlainText with the Key using AES algorithm.
	Cipher();

	// Output the encrypted text.
	printf("\nText after encryption:\n");
	for (i = 0; i<Nb * 4; i++)
	{
		printf("%02x ", out[i]);
	}
	printf("\n\n");

	// If you use Microsoft Visual Studio (Again!!!!!) you must command program to stop then use the following two single word, show below.
	// Like this :	
	_getch();
}


int texttohex(unsigned char e){

	int i = 0;
	while (e != '\0')
	{
		switch (e)
		{

		case 'a':
			e = 0x61;
			break;
		case 'b':
			e = 0x62;
			break;
		case 'c':
			e = 0x63;
			break;
		case 'd':
			e = 0x64;
			break;
		case 'e':
			e = 0x65;
			break;
		case 'f':
			e = 0x66;
			break;
		case 'g':
			e = 0x67;
			break;
		case 'h':
			e = 0x68;
			break;
		case 'i':
			e = 0x69;
			break;
		case 'j':
			e = 0x6a;
			break;
		case 'k':
			e = 0x6b;
			break;
		case 'l':
			e = 0x6c;
			break;
		case 'm':
			e = 0x6d;
			break;
		case 'n':
			e = 0x6e;
			break;
		case 'o':
			e = 0x6f;
			break;
		case 'p':
			e = 0x70;
			break;
		case 'q':
			e = 0x71;
			break;
		case 'r':
			e = 0x72;
			break;
		case 's':
			e = 0x73;
			break;
		case 't':
			e = 0x74;
			break;
		case 'u':
			e = 0x75;
			break;
		case 'v':
			e = 0x76;
			break;
		case 'w':
			e = 0x77;
			break;
		case 'x':
			e = 0x78;
			break;
		case 'y':
			e = 0x79;
			break;
		case 'z':
			e = 0x7a;
			break;

		case 'A':
			e = 0x41;
			break;
		case 'B':
			e = 0x42;
			break;
		case 'C':
			e = 0x43;
			break;
		case 'D':
			e = 0x44;
			break;
		case 'E':
			e = 0x45;
			break;
		case 'F':
			e = 0x46;
			break;
		case 'G':
			e = 0x47;
			break;
		case 'H':
			e = 0x48;
			break;
		case 'I':
			e = 0x49;
			break;
		case 'J':
			e = 0x4a;
			break;
		case 'K':
			e = 0x4b;
			break;
		case 'L':
			e = 0x4c;
			break;
		case 'M':
			e = 0x4d;
			break;
		case 'N':
			e = 0x4e;
			break;
		case 'O':
			e = 0x4f;
			break;
		case 'P':
			e = 0x50;
			break;
		case 'Q':
			e = 0x51;
			break;
		case 'R':
			e = 0x52;
			break;
		case 'S':
			e = 0x53;
			break;
		case 'T':
			e = 0x54;
			break;
		case 'U':
			e = 0x55;
			break;
		case 'V':
			e = 0x56;
			break;
		case 'W':
			e = 0x57;
			break;
		case 'X':
			e = 0x58;
			break;
		case 'Y':
			e = 0x59;
			break;
		case 'Z':
			e = 0x5a;
			break;
		case'0':
			e = 0x30;
			break;
		case'1':
			e = 0x31;
			break;
		case'2':
			e = 0x32;
			break;
		case'3':
			e = 0x33;
			break;
		case'4':
			e = 0x34;
			break;
		case'5':
			e = 0x35;
			break;
		case'6':
			e = 0x36;
			break;
		case'7':
			e = 0x37;
			break;
		case'8':
			e = 0x38;
			break;
		case'9':
			e = 0x39;
			break;
		default:
			e = 0x20;
			break;
		}
		i++;
	}
	return e;
}
