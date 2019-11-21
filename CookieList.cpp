#include "CookieList.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//Member function defenitions for the CookieList Class

//appends a node to the linked list with the customer and cookie type names, along 
// with the number of boxes sold to the customer
void CookieList::appendNode(char customer[], char cookie[], int boxes)
{
	CookieNode* newNode;
	CookieNode* nodePtr;

	//allocate new node and store values
	newNode = new CookieNode;
	strncpy_s(newNode -> customer_name, customer, CUSTOMER_NAME_SIZE);
	strncpy_s(newNode->cookie_name, cookie, COOKIE_NAME_SIZE);
	newNode->num_boxes = boxes;
	newNode->next = nullptr;

	//if head is nullptr, make first node in the list
	if(!head)
	{
		head = newNode;
	}
	//else cycle through the list until we find nullptr
	//then set it to new Node
	else
	{
		nodePtr = head;
		//cycling through
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}

}

//sums the number of boxes ordered of a user-specified cookie type
int CookieList::sumNode(char cookie[], CookieNode* nP) const
{


	//if nP is null, end of recursion, return 0
	if (!nP)
		return 0;
	//if nP is not null, check if input matches current node, return box number if true
	// and move to the next node to check again
	else if (strstr(nP->cookie_name, cookie))
	{
		return (nP->num_boxes + sumNode(cookie, nP->next));
	}
	//else if nP is not null and input doesnt match, move to next noe
	else
		return sumNode(cookie, nP->next);
			
}

//Displays the linked list in table format when called
void CookieList::displayList()
{
	CookieNode* nodePtr = nullptr;
	if (!head)
		cout << "No information in the list!";
	else
	{
		nodePtr = head;
		//Table headers
		cout << "Customer" << setw(28) << "Cookie" << setw(28) << "Amount\n";
		//loop to cycle nodes and display all fields
		while (nodePtr)
		{
			cout << left  << setw(30) << nodePtr->customer_name
				<< setw(28)
				<< nodePtr->cookie_name << right << setw(5)
				<< nodePtr->num_boxes << endl;

			nodePtr = nodePtr->next;
		}

	}
}


//Destructor
CookieList::~CookieList()
{
	CookieNode* nPtr = nullptr;
	CookieNode* prev = nullptr;
	nPtr = head;
	//cycles through nodes and deletes each of them
	while (nPtr)
	{
		prev = nPtr;
		nPtr = nPtr->next;
		delete prev;
	}
}
