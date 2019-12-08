#include <iostream>
#include <string>
#include <fstream>
#include "Algorithm.h"
using namespace std;


int main()
{
	char response;
	Algorithm Algorithm1;
	cout << "Welcome! Please select an option" << endl;
	do {


		cout << "A: Encrypt" << endl << "B: Decrypt" << endl << "C: Exit" << endl;

		cin >> response;
		cin.ignore();
		cout << endl;

		if (response == 'A' || response == 'a')
		{
			string fileInput;
			cout << "Please enter your file path." << endl;
			getline(cin, fileInput);
			cin.ignore();
			Algorithm1.encryptFile(fileInput);

		};

		if (response == 'B' || response == 'b')
		{
			string fileInput;
			cout << "Please enter your file path." << endl;
			getline(cin, fileInput);
			cin.ignore();
			Algorithm1.decryptFile(fileInput);

		};

		if (response == 'C' || response == 'c')
		{
			return 0;
		};
	} while (response != 'C' || response == 'c');
	system("pause");
	return 0;
}

