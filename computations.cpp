#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "funcLib.h"

using namespace std;

extern const int ENTRIES = 23;

int main()
{
	double first;
	double last;
	double delta;
	double ans;
	
	initialize();

	while (true)
	{
		char code;
		bool valid = false;
		int counter = 0; //making a counter to check if the iterations exceed 23
		
		do
		{
			//will conintually ask for a command code until the code is valid
			cout << "Please enter a command code: ";
			cin >> code;
			
			valid = checkCode(code);
		}while(!valid);

			// checking for the quit command to break the code
		if (code == 'Q' || code == 'q')
		{
			cout << "quitting ... " << endl;		
			break;
		}
		 	
		//do the write to output function
		else if (code == 'O' || code == 'o')
		{
			writeDataToFile("q1Output.txt");
			cout << endl;
		}
	
		//do the read data from file function
		else if (code == 'P' || code == 'p')
		{
			readDataFromFile("q1Input.txt");
			cout << endl;
		}
		
		//moving on when code is valid and not the quit command
		else 
		{
			//checks for case when only one nubmer is input
			cout << "Please enter command parameters: ";
			cin >> first;
			if(cin.get() == '\n')
			{
				cout << "No computation needed." << endl;
				cout << endl;
				continue;
			}
			cin >> last;
			if(cin.get() == '\n')
			{
			cout << "No computation needed." << endl;
				cout << endl;
				continue;
			}
			
			cin >> delta;

			//checks for special cases
			if (delta <= 0)
			{
				cout << "No computation needed." << endl;
				cout << endl;
				continue;
			}

			else if (first > last)
			{
				cout << "No computation needed." << endl;
				cout << endl;
				continue;
			}
	
			//sin command
			if (code == 'S' || code == 's')
			{	
				//i wrote most of my code in this type of for loop in main, most of my functions only take one parameter in the header file and i iterate through in the main. I know that you could do it with this iteration in the funclib.cpp instead. 
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
			cout << endl;
			
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
				cout << endl;
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
				cout << endl;
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
			cout << endl;
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
						cout << endl;
					}
				}
				
				if (counter == ENTRIES)
				{
					break;
				} 
				cout << endl; //this one ends the printing line
				cout << endl; //this one adds a new line
			}

			//compute lucky numbers
			else if (code == 'L' || code == 'l')
			{
				for (double i = first; i <= last + 1; i = i + delta)
				{
					srand(i);
					ans = rand ();
					counter++;
					cout << "Lucky number of " << fixed << setprecision(2) << i;
					cout << " = " << fixed << setprecision(4) << ans << endl;		
					if (counter == 23)
					{
						break;
					} 	
				}
			cout << endl;
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
			cout << endl;
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
			cout << endl;
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
			cout << endl;
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
				cout << endl;
			}
		
		}
	}
	return 0;
}

