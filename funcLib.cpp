#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <locale>
#include <time.h>
#include <string.h>
#include <string>
#include <cmath>

using namespace std;

extern const int ENTRIES;

void initialize()
{
	cout << "327: Introduction to Software Engineering" << endl;
	cout << "Fall 2016" << endl;
	cout << "Programming Assignment 2" << endl;
	cout << "Maximum computation is: " << ENTRIES << endl;
	cout << endl;

}

bool checkCode(char code)
{
	char characterArray[] = "UuCcRrDdLlSsNnEeAaYyPpOoQq";
	char *codecheck;
	codecheck = strchr(characterArray, code);
	bool valid = true;	
	
	if (codecheck == NULL)
	{
		valid = false;
		cout << "Not a valid command..." << endl;
	}
	return valid;
}

double findNyanCatValue(double myNum)
{
	return pow((3 * myNum), myNum) + myNum;
}


double areasquare(double side)
{
	return pow(side, 2);
}

double circum(double radius)
{
	return (2 * 3.14159 * radius);
}


void writeDataToFile (const char *filename)
{
	ofstream myfile;
	myfile.open(filename);
	
	srand(time(NULL));
	int first = rand() % 21;
	int last = rand() % 32 + 45;
	int delta = rand() % 6 + 5;

	double newfirst = double(first);
	double newlast = double(last);
	double newdelta = double(delta);
	
	for (double i = newfirst; i <= newlast; i = i + newdelta)
	{
		double ans = findNyanCatValue(i);
		int counter;
		counter++;
		myfile << "Nyan Cat Value of " << fixed << setprecision(2) << i << " = " << fixed << setprecision(4) << ans << endl;
		if(counter == ENTRIES)
		{
			break;
		}
	}
	cout << "file has been written..." << endl;
	
	myfile.close();
}

void readDataFromFile(const char *filename)
{
	//initialize variables
	double first, last, delta;
	char code, a, b, c;
	double ans;
	int counter = 0;
	
	string line;
	ifstream myfile (filename);

	while (!myfile.eof())
	{	
		myfile >> code >> first >> last >> delta;
		
		if(myfile.eof())
		{
			break;
		}
		
		//cout the number in the proper order, changes number to a string
		ostringstream a;
		a << first;
		string one = a.str();

		ostringstream b;
		b << last;
		string two = b.str();

		ostringstream c;
		c << delta;
		string three = c.str();

		//formatting
		cout << endl;

		//expected output
		cout << "Successfully read data from file: Code " << code << " First " << one << " Last ";
		cout << two << " Delta " << three << endl;
		
		//sepcial cases (i could do an or statement here but pls dont take off points it does the same thing and this is my logic)

		if (delta <= 0 || first > last)
		{
			cout << "No computation needed." << endl;
			cout << endl;
			continue;
		}

	//going through main function

		if (code == 'S' || code == 's')
			{	
				for (double i = first; i <= last; i = i + delta)
				{
					ans = sin(i);
					counter++;
					cout << "Sine of " << fixed << setprecision(2) << i;
					cout << " = " << fixed << setprecision(4) << ans << endl;		
					if (counter == ENTRIES)
					{
						break;
					} 
				}
			}
			
			//computing square values
		else if (code == 'U' || code == 'u')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = areasquare(i);
				counter++;
				cout << "Area of square with side length " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;
				if (counter == ENTRIES)
				{
					break;
				} 			
			}
		}
			
			//computing the circumference of circle values
		else if (code == 'C' || code == 'c')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = circum(i);
				counter++;
				cout << "Circumference of circle with radius " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;		
				if (counter == ENTRIES)
				{
					break;
				} 	
			}
		}
		
			//computing square root
		else if (code == 'R' || code == 'r')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = sqrt(i);
				counter++;
				cout << "Square root of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;		
				if (counter == ENTRIES)
				{
					break;
				} 	
			}
		}
			//computing odd numbers
		else if (code == 'D' || code == 'd')
		{
			cout << "Odd numbers from " << fixed << setprecision(2) << first << " to " << last << " = ";
			int a = ceil(first);
	
			for (int c = a; c <= last; c = c + delta)
			{
				//if the first number is odd
				if (c % 2 != 0)
				{
					cout << c << " ";	
					counter++;
					if (counter == ENTRIES)
					{
						continue;
					} 
				}
			}
			int d = a;
			//if the first number is even
			if (d % 2 == 0)
			{
				for (d; d < last; d = d + delta)
				{					
					cout << d + 1 << " ";
					counter ++;

					if (counter == ENTRIES)
					{
						continue;
					} 
				}
			cout << endl;	
			}
						
		}
			//compute lucky numbers
		else if (code == 'L' || code == 'l')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				counter = 0;
				srand(i);
				ans = rand ();
				counter++;
				cout << "Lucky number of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;		
				if (counter == ENTRIES)
				{
					break;
				} 	
			}
		}
			//compute cosine values
		else if (code == 'N' || code == 'n')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = cos(i);
				counter++;
				cout << "Cosine of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;		
				if (counter == ENTRIES)
				{
					break;
				} 	
			}
		}

			//compute exponentials
		else if (code == 'E' || code == 'e')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = exp(i);
				counter++;
				cout << "Exponential of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;	
				if (counter == ENTRIES)
				{
					break;
				} 		
			}
		}

			//compute natural logs
		else if (code == 'A' || code == 'a')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = log(i);
				counter++;
				cout << "Natural Log of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;	
				if (counter == ENTRIES)
				{
					break;
				} 		
			}
		}
			//compute NyanCat value
		else if (code == 'Y' || code == 'y')
		{
			for (double i = first; i <= last; i = i + delta)
			{
				ans = findNyanCatValue(i);
				counter++;
				cout << "Nyan Cat Value of " << fixed << setprecision(2) << i;
				cout << " = " << fixed << setprecision(4) << ans << endl;	
				if (counter == ENTRIES)
				{
					break;
				} 
			}
		}
	}
}		




