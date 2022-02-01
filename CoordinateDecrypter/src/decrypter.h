#pragma once
#include <string>
#include <algorithm>
using namespace std;

class decrypter
{
	private:
		// Code for decrypting the encryptedCoordinate
		string code;
		// The coordinate to be decrypted
		string encryptedCoordinate;
	public:
		/** 
		* Creates a decrypter Object initialized with the code to use to decrypt the given coordinate.
		* @param _code The code for decyphering the encrypted coordinate
		* @param _encryptedCoordinate The encrypter coordinate
		* @return A decrypter object
		*/
		decrypter(string _code, string _encryptedCoordinate);
		/**
		* Decrypts the stored encryptedCoordinate using the stored code.
		* @return A string containing the decrypted coordinate
		*/
		string decrypt();
		/**
		* Computes the length of the longest palindrome contained in a given string.
		* @param sequence The string for which the length of the longest palindrom should be computed
		* @return The length of the longest palindrom within sequence.
		*/
		int longestPalindrome(string sequence);
};