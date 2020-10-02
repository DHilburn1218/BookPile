/**
@author Darrick Hilburn

Interface header file for a BookPile ADT

BookPile.h
*/

#ifndef BOOKPILE_H
#define BOOKPILE_H

#include"Book.h"
#include<string>
using std::string;

class BookPile
{
private:

	Book* headPtr;	// Pointer to first book in pile
	int itemCount;	// Number of books in pile

	/**
	@author Darrick Hilburn

	getTitleLength returns the character count of a passed title.

	@param title: string title of a book.
	@return: Returns the number of characters in a title; 
			 includes white space.
	*/
	int getTitleLength(string title) const;

public:

	/**
	@author Darrick Hilburn
	Default constructor; sets nextTitle to nullptr
	*/
	BookPile();
	/**
	@author Darrick Hilburn
	Copy Constructor; deep copies a BookPile into another BookPile
	*/
	BookPile(const BookPile& cpyPile);
	/**
	@author Darrick Hilburn
	Destructor; calls clear() to remove the BookPile from the memory heap.
	*/
	~BookPile();

	/**
	@author Darrick Hilburn

	bookCount returns the number of books currently in the BookPile.

	@return: Returns itemCount value
	*/
	int bookCount() const;
	/**
	@author Darrick Hilburn

	findBook searches through the BookPile and attempts to locate
	the book with the passed title content.

	@param title: Title a node may contain.
	@return: Returns the position in BookPile the book with
			 title is at; -1 otherwise.
	*/
	int findBook(string title) const;
	/**
	@author Darrick Hilburn

	getBook returns the title of the book at the passed position.

	@param pos: position starting from 1 of a book in the pile.
	@return: Returns the title of the book at the position.
			 Returns empty string if an improper position was passed.
	*/
	string getBook(int pos) const;

	/**
	@author Darrick Hilburn

	addBook attempts to add a book to the pile.
	A book can't be added to the pile if the title
	is already in the pile or the title is empty string.

	@param title: Title of book to add to the pile.
	@return: Returns true if the book was added to the pile;
			 false otherwise.
	*/
	bool addBook(string title);
	/**
	@author Darrick Hilburn

	removeBook attempts to remove a book from the pile based
	on the passed title parameter.
	removeBook fails if it can't find the title in the pile.

	@param title: Title of the book to remove from the pile.
	@return: Returns true if the book was successfully removed from
			 the pile; false otherwise.
	*/
	bool removeBook(string title);
	/**
	@author Darrick Hilburn

	removeBook attempts to remove a book from the pile based
	on the passed position in the pile.
	removeBook fails if an improper position is passed.

	@param pos: position in the book pile, starting at 1.
	@return: Returns true if the book was successfully removed from
			 the pile; false otherwise.
	*/
	bool removeBook(int pos);	
	/**
	@author Darrick Hilburn

	renameBook searches for a book in the pile and "renames" it.
	rename actually removes the old titled book and adds a book with
	the new name to the pile.

	@param oldName: name of book to rename in the pile
	@param newName: new name of book in the pile to rename.
	@return: Returns true if the book with oldName can be renamed to
			 newName; returns false otherwise.
	*/
	bool renameBook(string oldName, string newName);

	/**
	@author Darrick Hilburn

	displayPile goes through the book pile and displays the names of
	all the books in the pile and their character count.
	*/
	void displayPile() const;
	/**
	@author Darrick Hilburn

	clear removes the entire book pile from the memory heap.
	*/
	void clear();	
};
#endif