#include <iostream>
#include <chrono>
#include <thread>
#include "BookPile.h"

int main()
{
	std::chrono::milliseconds waitTime_TINY(2000);
	std::chrono::milliseconds waitTime_SMALL(4000);
	BookPile myPile;

	std::cout << "This program displays functionality of a Linked Chain." << std::endl <<
		"Nodes are represented as books." << std::endl <<
		"The chain is a pile of books." << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);
	std::cout << "(Scroll speed is for readability)" << 
	std::endl << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_SMALL);
	

	std::string books[] = { "Dune", "Dragonflight", "Neuromancer", "Contact",
		"Brave New World", "Cinder", "Rust", "Random1ze",  "Sea of Rust",
		"All Systems Red" };

	std::cout << "bookCount() returns: "
		<< myPile.bookCount() << " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "addBook(\"" << books[i] << "\") returns: "
			<< myPile.addBook(books[i])
			<< " [should be 1]" << std::endl;
		std::this_thread::sleep_for(waitTime_TINY);
	}

	std::cout << std::endl << "bookCount() returns: "
		<< myPile.bookCount() << " [should be 10]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "BOOK PILE CONTAINS: " << std::endl;
	myPile.displayPile();
	std::this_thread::sleep_for(waitTime_SMALL);

	std::cout << std::endl << "Making a copy with the copy constructor..." << std::endl;
	BookPile myOtherPile(myPile);
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << std::endl << "addBook(\"\") returns: "
		<< myPile.addBook("")
		<< " [should be 0]" << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << std::endl << "findBook(\"Contact\") returns: "
		<< myPile.findBook("Contact") << " [should be 7]" << std::endl
		<< std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "findBook(\"Neverwhere\") returns: "
		<< myPile.findBook("Neverwhere") << " [should be -1]" << std::endl
		<< std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "getBook(-1) returns: " << myPile.getBook(-1)
		<< " [should be empty string]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "getBook(25) returns: " << myPile.getBook(25)
		<< " [should be empty string]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "getBook(6) returns: " << myPile.getBook(6)
		<< " [should be Random1ze]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "removeBook(-1) returns: " << myPile.removeBook(-1)
		<< " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "removeBook(25) returns: " << myPile.removeBook(25)
		<< " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "removeBook(1) returns: " << myPile.removeBook(1)
		<< " [should be 1]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "removeBook(\"Last Days\") returns: "
		<< myPile.removeBook("Last Days")
		<< " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "removeBook(\"Cinder\") returns: "
		<< myPile.removeBook("Cinder")
		<< " [should be 1]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "renameBook(\"Fred\", \"Jimmy\") returns: "
		<< myPile.renameBook("Fred", "Jimmy")
		<< " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "renameBook(\"Rust\", \"Crust\") returns: "
		<< myPile.renameBook("Rust", "Crust")
		<< " [should be 1]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "bookCount() returns: "
		<< myPile.bookCount() << " [should be 8]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "BOOK PILE CONTAINS: " << std::endl;
	myPile.displayPile();
	std::this_thread::sleep_for(waitTime_SMALL);

	std::cout << std::endl << "Running clear()..." << std::endl << std::endl;
	myPile.clear();
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "bookCount() returns: "
		<< myPile.bookCount() << " [should be 0]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "Book pile contains: " << std::endl;
	myPile.displayPile();
	std::this_thread::sleep_for(waitTime_SMALL);

	std::cout << std::endl << "bookCount() on the copy returns: "
		<< myOtherPile.bookCount() << " [should be 10]" << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime_TINY);

	std::cout << "COPIED BOOK PILE CONTAINS: " << std::endl;
	myOtherPile.displayPile();
	std::this_thread::sleep_for(waitTime_SMALL);

	std::cout << std::endl << std::endl << "Press any key to exit";
	std::cin.ignore();
	return 0;
}