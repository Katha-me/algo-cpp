#include "decrypter.h"

int decrypter::longestPalindrome(string sequence)
{
	//TODO: Berechne die Länge des längsten Palindroms in sequence 
	int maxLength = 1;
	int start = 0;

    for (int i = 0; i < sequence.length(); i++) {
        for (int j = i; j < sequence.length(); j++) {
            int flag = 1;
 
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (sequence[i + k] != sequence[j - k])
                    flag = 0;
 
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
	return maxLength;
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