#pragma once
#include "Print.h"
#include "Book.h"
#include "ComicBook.h"
#include "Periodical.h"
#include "User.h"

class Library {
private:
	User* users = nullptr;
	size_t numberOfUsers = 0;
	size_t maxNumberOfUsers = 1;
	Print* prints = nullptr;
	size_t numberOfPrints = 0;
	size_t maxNumberOfPrints = 1;
public: 
	Library() = default;
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	Library(Library&& other) noexcept;
	Library& operator=(Library&& other) noexcept;

	size_t getNumberOfUsers() const;
	size_t getMaxNumberOfUsers() const;
	size_t getNumberOfPrints() const;
	size_t getMaxNumberOfPrints() const;
	void setNumberOfUsers(const size_t numberOfUsers);
	void setMaxNumberOfUsers(const size_t maxNumberOfUsers);
	void setNumberOfPrints(const size_t numberOfPrints);
	void setMaxNumberOfPrints(const size_t maxNumberOfPrints);

	void addPrint(const Book& print);
	void addPrint(const Periodical& print);
	void addPrint(const ComicBook& print);
	void removePrint(const size_t id);
	void displayPrints();
	void displayBorrowed(const size_t id);
	void addUser(const User& user);
	void removeUser(const char* name);
	void displayUsers();

private:
	void copyFrom(const Library& other);
	void free();
	void resizeUsers();
	void resizePrints();
	void sortPrints();
	void sortUsers();
};