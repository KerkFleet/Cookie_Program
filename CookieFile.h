#pragma once
#ifndef COOKIEFILE_H
#define COOKIEFILE_H

#include "CookieList.h"
#include <string>
using namespace std;

//Class that includes methods to read the cookie list file,
// search for the cookie type by name(use recursion), and print a customer summary
// that displays the data from the list in a table

class CookieFile
{
private:
	//for access to the cookielist public functions
	CookieList list;

public:
	//cookie file member functions
	void read_File(string filename);
	void search_cookie();
	void print_summary();

};

#endif

//double branch merge testing
//test comment to test branches as I am still learning how they work :)

