//branch history testing


#include "CookieFile.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//for switch function
enum num {PRINT = 1, SEARCH, EXIT};

int main()
{
	//main variables for user input and class function access
	CookieFile obj;
	int input;
	string filename;
	bool go = false;

	//retrieve file name and open file
	cout << "Please enter the name of the file followed by the '.txt' extension: ";
	cin >> filename;
	cout << "Opening and reading file...\n";
	obj.read_File(filename);
	cout << "File opened succesfully!\n\n";

	//print menu on loop until exit is specified
	do
	{
		//menu
		cout << "\nPlease choose a menu option\n";
		cout << "1. Print Customer Summary\n";
		cout << "2. Search Cookie Type\n";
		cout << "3. Exit\n";
		cout << "Menu option(1-3):";

		//store user input
		cin >> input;
		cin.ignore();
		cout << endl;

		//check to make sure option is 1-3
		while (go == false)
		{
			if (input <= 3 && input >= 1)
			{
				go = true;
			}
			else
			{
				cout << "Invalid menu option, enter again:";
				cin >> input;
				cin.ignore();
				cout << endl;
			}

		}

		//case to pick function based on input
		switch (input)
		{
		case PRINT: obj.print_summary();
			break;
		case SEARCH: obj.search_cookie();
			break;
		case EXIT: 
			break;
		}
		
	} while (input != 3);
}
