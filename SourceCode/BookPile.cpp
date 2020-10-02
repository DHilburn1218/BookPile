/**
@author Darrick Hilburn

Resource file for a BookPile ADT

BookPile.cpp
*/

#include"BookPile.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

BookPile::BookPile() : headPtr(nullptr), itemCount(0)
{
	
}

BookPile::BookPile(const BookPile& cpyPile)
{
	// Copying an empty list?
	// Make an empty list.
	if (cpyPile.itemCount == 0)
		headPtr = nullptr;
	else
	{
		// Keep track of where we are in the cpyPile;
		// Iterate through and add those values to this pile.
		Book* curPtr = cpyPile.headPtr;
		while (curPtr != nullptr)
		{
			addBook(curPtr->getTitle());
			curPtr = curPtr->getNext();
		}
	}
	// Set itemCount, otherwise we have a list of size 0.
	itemCount = cpyPile.itemCount;
}

BookPile::~BookPile()
{
	// End of program; empty the heap.
	clear();
}

int BookPile::getTitleLength(string title) const
{
	return title.length();
}

bool BookPile::removeBook(string title)
{
	bool remove = false; // Flag that checks for successful remove
	Book* rmvBook = headPtr; // pointer to book we are interested in; 
							 // starts at head
	
	// HeadPtr is our remove point?
	// Remove and update headPtr
	if (headPtr->getTitle() == title)
	{
		headPtr = headPtr->getNext();
		delete rmvBook;
		--itemCount;
		remove = true;
	}
	else
	{
		// Book to remove is in the list;
		// Track the book before the one we are
		// interested in as well for preserving
		// list integrity.
		Book* prevBook = rmvBook;
		rmvBook = rmvBook->getNext();

		// Iterate through the list until either we find the
		// book with the target title or we've reached the
		// end of the list, updating observed and its previous
		// books along the way.
		while (rmvBook != nullptr && rmvBook->getTitle() != title)
		{
			prevBook = rmvBook;
			rmvBook = rmvBook->getNext();
		}

		// If we're not at the end of the list and we've found
		// the target title, get the next book after the observed,
		// link together the previous and next books, and remove
		// the observed book.
		if (rmvBook != nullptr && rmvBook->getTitle() == title)
		{
			Book* nextBook = rmvBook->getNext();
			prevBook->setNext(nextBook);
			delete rmvBook;
			--itemCount;
			nextBook = nullptr;
			remove = true;
		}
		prevBook = nullptr;		
	}
	rmvBook = nullptr;
	return remove;
}

bool BookPile::removeBook(int pos)
{
	bool remove = false;
	Book* rmvBook = headPtr;


	// First check that a proper position in the pile was passed.
	if (pos > 0 && pos < itemCount)
	{
		// Removing from the top of the pile?
		// Do so.
		if (pos == 1)
		{
			headPtr = headPtr->getNext();
			delete rmvBook;
		}
		else
		{
			// Book to remove is in the list;
			// Track the book before the one we are
			// interested in as well for preserving
			// list integrity.
			Book* prevBook = headPtr;
			rmvBook = headPtr->getNext();

			// Iterate through the pile up to the target
			// position, updating the observed book and its
			// previous along the way.
			for (int i = 1; i < pos; i++)
			{
				prevBook = rmvBook;
				rmvBook = rmvBook->getNext();
			}

			// Link together the books before and after
			// the book to remove before removing the target book.
			Book* nextBook = rmvBook->getNext();
			prevBook->setNext(nextBook);
			delete rmvBook;
			prevBook = nullptr;
			nextBook = nullptr;
		}
		--itemCount;
		remove = true;		
	}
	rmvBook = nullptr;
	return remove;
}

bool BookPile::addBook(string title)
{	
	bool insert = false;

	// First check that the title of the book to add isn't an
	// empty string and is not already in the list
	if (title != "" && findBook(title) == -1)
	{
		Book* newBook = new Book(title);

		// Book to add is at the front of the list?
		// Add to the front of the list.
		if(headPtr == nullptr ||
			getTitleLength(title) > getTitleLength(headPtr->getTitle()))
		{
			newBook->setNext(headPtr);
			headPtr = newBook;
		}
		else
		{
			// Book must be inserted in the middle of the list.
			// Track the book that will come before the book to
			// add to preserve list integrity.
			Book* prevBook = headPtr;
			Book* curBook = headPtr->getNext();

			// Iterate through the list while the character count of
			// the title of the book to add to the list is less than the
			// character count of the title(s) already in the list
			while (curBook != nullptr &&
				(getTitleLength(curBook->getTitle()) > getTitleLength(title)))
			{
				prevBook = curBook;
				curBook = curBook->getNext();
			}

			// Insert the new book into the list, linking the book
			// before the new book to the new book and the new book
			// to the book after it.
			prevBook->setNext(newBook);
			newBook->setNext(curBook);
			curBook = nullptr;
			prevBook = nullptr;
		}
		++itemCount;
		newBook = nullptr;
		insert = true;
	}	
	return insert;	
}

int BookPile::findBook(string title) const
{
	Book* curBook = headPtr;
	int bookPos = -1;	// Return value for book location
	int searchPos = 1;	// run-time book location

	// While we're searching through the list,
	// iterate the search position
	while (curBook != nullptr && curBook->getTitle() != title)
	{
		curBook = curBook->getNext();
		++searchPos;
	}

	// If we found a book with the target title,
	// set the return value to the search position.
	if (curBook != nullptr && title == curBook->getTitle())
		bookPos = searchPos;

	return bookPos;
}

void BookPile::displayPile() const
{

	Book* curBook = headPtr;
	// Iterate through the pile and display
	// book titles and their character count
	while (curBook != nullptr)
	{
		cout << curBook->getTitle() << " (" 
			 << getTitleLength(curBook->getTitle()) << ")" << endl;
		curBook = curBook->getNext();
	}
}

string BookPile::getBook(int pos) const
{
	string rtnTitle = "";
	// Check that a proper pile position was passed
	if (pos > 0 && pos < itemCount)
	{
		Book* curBook = headPtr;
		// Iterate through the pile to the passed position
		// and record the title of the book at the stop position
		for (int searchPos = 1; searchPos < pos; searchPos++)
			curBook = curBook->getNext();
		rtnTitle = curBook->getTitle();
	}
	return rtnTitle;
}

bool BookPile::renameBook(string oldName, string newName)
{
	bool renamed = false;
	// Check that the new book name is both not empty string
	// and not already in the pile;
	// also check that the old book is in the pile.
	if (newName != "" && findBook(newName) == -1 && findBook(oldName) != -1)
	{
		removeBook(oldName);
		addBook(newName);
		renamed = true;
	}
	return renamed;
}

int BookPile::bookCount() const
{
	return itemCount;
}

void BookPile::clear()
{
	Book* rmvBook = headPtr;

	// While there is still a book in the pile,
	// remove the first book in the pile
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		delete rmvBook;
		rmvBook = headPtr;
		--itemCount;
	}
}