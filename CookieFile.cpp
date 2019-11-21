#include "CookieFile.h"
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

//read contents of file into structure records of linked list
void CookieFile::read_File(string filename)
{
	ifstream infile;
	char customer[CUSTOMER_NAME_SIZE];
	char cookie[COOKIE_NAME_SIZE];
	int box_num;
	int amount;
	infile.open(filename);
	//test if file exists
	if (!infile)
	{
		cout << "Error opening file! \n";
		exit(102);
	}

	//loop through to read in data
	while (infile.getline(customer, CUSTOMER_NAME_SIZE ))
	{
		//read number of types ordered and store
		infile >> box_num;
		for (box_num; box_num > 0; box_num--)
		{
			//for loop to iterate for each type, getting the number ordered
			infile >> amount;
			infile.ignore();
			// and the cookie type, then calling append node passing in name, type, and boxes
			infile.getline(cookie, COOKIE_NAME_SIZE);
			list.appendNode(customer, cookie, amount);
		}
	}

}

//gets search name from user and passes it into sumNode, storing
// the return value into an int variable
void CookieFile::search_cookie()
{
	int total = 0;

	//get search name from user
	char type[COOKIE_NAME_SIZE];
	cout << "Enter the cookie type name you would like to search: ";
	cin.getline(type, COOKIE_NAME_SIZE);

	//return number of boxes by calling sumNode
	total = list.sumNode(type);
	cout << "The total number of " << type << " boxes ordered is: " << total << endl;

}

//prints a summary by calling displaylist from cookielist.h
void CookieFile::print_summary()
{
	list.displayList();
}
