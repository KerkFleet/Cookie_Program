#pragma once
#ifndef COOKIELIST_H
#define COOKIELIST_H


#include <cstring>
using namespace std;

const int CUSTOMER_NAME_SIZE = 31;
const int COOKIE_NAME_SIZE = 31;

// Class to create a linked list that stores the nodes with the customer name,
// cookie type, and the number of boxes cookies in each node. Includes a constructor,
// destructor, appendnode, sum, and display member functions.
class CookieList
{
private:
	struct CookieNode
	{
		char customer_name[CUSTOMER_NAME_SIZE]; //to store customer name
		char cookie_name[COOKIE_NAME_SIZE];		//to store cookie name
		int num_boxes;							//to store number of cookie boxes
		CookieNode* next;
	};

	CookieNode* head;
	//wrapper function?
	int sumNode(char cookie[], CookieNode * nP) const;
public:
	//Constructor
	CookieList()
	{
		head = nullptr;
	}

	//Destructor
	~CookieList();

	//Linked List Functions
	void appendNode(char customer[], char cookie[], int boxes);
	
	void displayList();

	//wrapper function
	int sumNode(char cookie[]) const
	{
		return(sumNode(cookie, head));
	}



};

#endif



