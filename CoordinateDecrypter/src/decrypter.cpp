#include "decrypter.h"
#include <iostream>

//help function to determine maximum of 2 ints
int max(int x, int y){
	return (x>y ? x : y);
}

int decrypter::longestPalindrome(string sequence)
{

	int n = sequence.length(); //length of sequence
   	int i, j, subl;
	int T[n][n]; //creat table with nxn
	

	for (i = 0; i < n; i++)

		T[i][i] = 1;

		for (subl=2; subl<=n; subl++)
		{
			for (i=0; i<n-subl+1; i++)
			{
				j = i+subl-1;
				if (sequence[i] == sequence[j] && subl == 2){
					T[i][j] = 2;
				}
				else if (sequence[i] == sequence[j]){
					T[i][j] = T[i+1][j-1] + 2;
				}
				else{
					T[i][j] = max(T[i][j-1], T[i+1][j]);
				}
			}
		}
		return T[0][n-1];
}

string decrypter::decrypt()
{
	int position = longestPalindrome(code);
	string decryptedCoordinate = "";
	for (int p = 0; p < encryptedCoordinate.length(); p += position)
	{	
		// Um die Leerzeichen zu entfernen, kann folgende Zeile auskommentiert werden
		if (encryptedCoordinate.at(p) != ' ')
		decryptedCoordinate += encryptedCoordinate.at(p);
	}
	return decryptedCoordinate;
}

decrypter::decrypter(string _code, string _encryptedCoordinate)
{
	code = _code;
	encryptedCoordinate = _encryptedCoordinate;
}