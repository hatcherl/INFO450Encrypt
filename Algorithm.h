#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Algorithm
{
private:

public:
	
	Algorithm();
	int encryptFile(string filename);
	int decryptFile(string filename);
};