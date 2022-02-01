#include <fstream>
#include <string>
#include <iostream>
#include "decrypter.h"

using namespace std;

int main(int argc, char** argv)
{
	//TODO: Setze die Pfade zu den beiden Dateien
	cout << "hi from main \n";
	ifstream codeStream("../code.txt");
	ifstream encryptedCoordinateStream("../koordinate.txt");
	string code((istreambuf_iterator<char>(codeStream)),(istreambuf_iterator<char>()));
	string encryptedCoordinate((istreambuf_iterator<char>(encryptedCoordinateStream)), (istreambuf_iterator<char>()));
	decrypter d(code, encryptedCoordinate);
	cout << "Decrypted coordinate:\t" << d.decrypt() << endl;
}
