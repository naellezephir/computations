#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include "FileFunctions.h"

using namespace std;

void WriteRandomDataToFile(const char *filename, int N, int M)
{
	srand(time(NULL));

	int myArray[N];

	ofstream myfile;
	myfile.open(filename);

	for (int i = 0; i < N; i++)
	{
		int number = rand() % (M + 1);
		myArray[i] = number;
		myfile << myArray[i] << endl;
	}
	
	myfile.close();
}

void ReadDataFromFile(const char *filename, int myArray[], int &size)
{
	ifstream myfile(filename);
	int numoflines;

	string line;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int c = atoi(line.c_str());
			myArray[numoflines] = c;
			numoflines++;
		}
	}

	size = numoflines;
	cout << "Array Size is: " << size << endl;
}
	

	
