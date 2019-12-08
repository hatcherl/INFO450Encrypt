#include <iostream>
#include <string>
#include <fstream>
#include "Algorithm.h"

using namespace std;

Algorithm::Algorithm(){}

int Algorithm::encryptFile(string fileName)
{
	fstream inputFile, tempFile;
	char ch;

	inputFile.open(fileName.c_str(), ios::in);
	if (!inputFile)
	{
		cout << "File can't be opened!?" << endl;
		return 2;
	}

	tempFile.open("mytemp123.txt", ios::out);
	//I added in ios::out because since I don't have a exact filepath, opening the file for output
	//will create it

	if (!tempFile)
	{
		cout << "Temp File can't be created!?" << endl;
		inputFile.close();
		system("pause");
		return 3;
	}

	while (!inputFile.eof())
	{
		//This will get the characters from the inputFile and increment their values by 5
		//And then output them into tempFile
			inputFile >> ch;
			ch = ch + 5;
			tempFile << ch;
	}

	inputFile.close();
	tempFile.close();

	inputFile.open(fileName.c_str(), ios::out);

	if (!inputFile)
	{
		cout << "Couldn't open the input file!" << endl;
		return 4;
	}

	tempFile.open("mytemp123.txt");
	if (!tempFile)
	{
		cout << "Couldn't open temp file!" << endl;
		return 5;
	}

	while (!tempFile.eof())
	{
		//this takes the characters from tempFile and writes them into inputFile
		tempFile >> ch;
		inputFile << ch;
	}
	cout << "The file was encrypted." << endl;
	inputFile.close();
	tempFile.close();

	system("pause");
	return 0;
}

int Algorithm::decryptFile(string fileName)
{
	fstream inputFile, tempFile;
	char ch;

	inputFile.open(fileName.c_str());
	if (!inputFile)
	{
		cout << "File can't be opened!?" << endl;
		return 6;
	}

	tempFile.open("mytemp123.txt");
	//I added in ios::out because since I don't have a exact filepath, opening the file for output
	//will create it

	cout << "testing..." << endl;

	if (!tempFile)
	{
		cout << "Temp File can't be created!?" << endl;
		inputFile.close();
		system("pause");
		return 7;
	}

	cout << "testing1..." << endl;

	while (!tempFile.eof())
	{
		//This will reverse what we did earlier in the encryption function
		tempFile >> ch;
		ch = ch - 5;
		inputFile << ch;
	}

	cout << "testing2..." << endl;

	cout << "File has been decrypted." << endl;
	inputFile.close();
	tempFile.close();

	system("pause");
	return 0;
}

