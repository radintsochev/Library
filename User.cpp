#include "User.h"
#include "Print.h"
#include "Book.h"
#include "ComicBook.h"
#include "Periodical.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

#pragma warning(disable : 4996)

User::User(const size_t numberOfRead) {
	setNumberOfRead(numberOfRead);
}

User::User(const User& other) {
	copyFrom(other);
}

User& User::operator=(const User& other) {
	if (this == nullptr)
	{
		freeNull();
		copyFrom(other);
	}
	else if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

User::~User() {
	free();
}

void copyStringU(char*& lhs, const char* rhs) {
	lhs = new char[strlen(rhs) + 1];
	strcpy(lhs, rhs);
}

void movePointerU(char* lhs, char* rhs) {
	lhs = rhs;
	rhs = nullptr;
}

void User::copyFrom(const User& other) {
	copyStringU(name, other.name);
	read = new Print[other.numberOfRead];
	numberOfRead = other.numberOfRead;
	maxNumberOfRead = other.maxNumberOfRead;
	for (size_t i = 0; i < numberOfRead; i++)
	{
		read[i] = other.read[i];
	}
	numberOfBorrowed = other.numberOfBorrowed;
	for (size_t i = 0; i < 5; i++)
	{
		borrowed[i] = other.borrowed[i];
	}
}

void User::freeNull() {
	name = nullptr;
	read = nullptr;
	numberOfRead = 0;
	maxNumberOfRead = 0;
	numberOfBorrowed = 0;
}

void User::free() {
	delete[] name;
	delete[] read;
	numberOfRead = 0;
	maxNumberOfRead = 0;
	numberOfBorrowed = 0;
}

void User::resize() {
	Print* temp = new Print[maxNumberOfRead * 2];
	maxNumberOfRead *= 2;
	for (size_t i = 0; i < numberOfRead; i++)
	{
		temp[i] = read[i];
	}
	read = temp;
	temp = nullptr;
}

User::User(User&& other) noexcept {
	movePointerU(name, other.name);
	read = other.read;
	other.read = nullptr;
	for (size_t i = 0; i < 5; i++)
	{
		borrowed[i] = other.borrowed[i];
	}
	numberOfRead = other.numberOfRead;
	maxNumberOfRead = other.maxNumberOfRead;
	numberOfBorrowed = other.numberOfBorrowed;

}

User& User::operator=(User&& other) noexcept {
	if (this != &other)
	{
		free();
		movePointerU(name, other.name);
		read = other.read;
		other.read = nullptr;
		for (size_t i = 0; i < 5; i++)
		{
			borrowed[i] = other.borrowed[i];
		}
		numberOfRead = other.numberOfRead;
		maxNumberOfRead = other.maxNumberOfRead;
		numberOfBorrowed = other.numberOfBorrowed;
	}
	return *this;
}

size_t User::getNumberOfRead() const {
	return numberOfRead;
}

size_t User::getMaxNumberOfRead() const {
	return maxNumberOfRead;
}

size_t User::getNumberOfBorrowed() const {
	return numberOfBorrowed;
}

char* User::getName() const {
	return name;
}

void User::setName(const char* name) {
	copyStringU(this->name, name);
}

void User::setNumberOfRead(const size_t numberOfRead) {
	this->numberOfRead = numberOfRead;
}

void User::setMaxNumberOfRead(const size_t maxNumberOfRead) {
	this->maxNumberOfRead = maxNumberOfRead;
}

void User::setNumberOfBorrowed(const size_t numberOfBorrowed) {
	this->numberOfBorrowed = numberOfBorrowed;
}

const char* getStateString(StateOfBook state) {
	const char* stateStrings[] = {
	"Read",
	"Borrowed",
	"None"
	};
	int index = (int)state;
	if (index >= 0 && index < 3) {
		return stateStrings[index];
	}
	return "Unknown";
}

bool operator==(const User& lhs, const User& rhs) {
	return strcmp(lhs.getName(), rhs.getName()) == 0;
}

bool operator!=(const User& lhs, const User& rhs) {
	return !(lhs == rhs);
}

bool operator>(const User& lhs, const User& rhs) {
	return lhs.getNumberOfRead() > rhs.getNumberOfRead();
}

bool operator>=(const User& lhs, const User& rhs) {
	return (lhs.getNumberOfRead() == rhs.getNumberOfRead()) || (lhs > rhs);
}

bool operator<(const User& lhs, const User& rhs) {
	return (lhs.getNumberOfRead() != rhs.getNumberOfRead()) && !(lhs > rhs);
}

bool operator<=(const User& lhs, const User& rhs) {
	return (lhs.getNumberOfRead() == rhs.getNumberOfRead()) || (lhs < rhs);
}

StateOfBook User::operator[](const size_t id) const {
	for (size_t i = 0; i < numberOfRead; i++)
	{
		if (read[i].getId() == id)
		{
			return READ;
		}
	}
	for (size_t i = 0; i < numberOfBorrowed; i++)
	{
		if (borrowed[i].getId() == id)
		{
			return BORROWED;
		}
	}
	return NONE;
}

User& operator+(User& user, const Print& print) {
	if (user.numberOfBorrowed == 5)
	{
		throw std::runtime_error("You have reached your borrowing limit. Return a print before you can borrow a new one.");
	}
	++user.numberOfBorrowed;
	user.borrowed[user.numberOfBorrowed - 1] = print;
	return user;
}

User& operator+(User& user, const Book& print) {
	if (user.numberOfBorrowed == 5)
	{
		throw "You have reached your borrowing limit. Return a print before you can borrow a new one.";
	}
	++user.numberOfBorrowed;
	user.borrowed[user.numberOfBorrowed - 1] = print;
	return user;
}

User& operator+(User& user, const Periodical& print) {
	if (user.numberOfBorrowed == 5)
	{
		throw "You have reached your borrowing limit. Return a print before you can borrow a new one.";
	}
	++user.numberOfBorrowed;
	user.borrowed[user.numberOfBorrowed - 1] = print;
	return user;
}

User& operator+(User& user, const ComicBook& print) {
	if (user.numberOfBorrowed == 5)
	{
		throw "You have reached your borrowing limit. Return a print before you can borrow a new one.";
	}
	++user.numberOfBorrowed;
	user.borrowed[user.numberOfBorrowed - 1] = print;
	return user;
}



void User::operator+=(const Print& print) {
	*this + print;
}

void User::operator+=(const Book& print) {
	*this + print;
}

void User::operator+=(const Periodical& print) {
	*this + print;
}

void User::operator+=(const ComicBook& print) {
	*this + print;
}

User& operator-(User& user, const Print& print) {
	bool found = false;
	for (size_t i = 0; i < user.numberOfBorrowed; i++)
	{
		if (user.borrowed[i] == print)
		{
			found = true;
			for (size_t j = i; j < user.numberOfBorrowed - 1; j++)
			{
				user.borrowed[j] = user.borrowed[j + 1];
			}
				--user.numberOfBorrowed;
		}
	}
	if (!found)
	{
		throw "You do not have this print in your borrowed list.";
	}
	if (user.numberOfRead == user.maxNumberOfRead)
	{
		user.resize();
	}
	++user.numberOfRead;
	user.read[user.numberOfRead - 1] = print;
	return user;
}

void User::operator-=(const Print& print) {
	*this - print;
}

User& operator-(User& user, const Book& print) {
	bool found = false;
	for (size_t i = 0; i < user.numberOfBorrowed; i++)
	{
		if (user.borrowed[i] == print)
		{
			found = true;
			for (size_t j = i; j < user.numberOfBorrowed - 1; j++)
			{
				user.borrowed[j] = user.borrowed[j + 1];
			}
				--user.numberOfBorrowed;
		}
	}
	if (!found)
	{
		throw "You do not have this print in your borrowed list.";
	}
	if (user.numberOfRead == user.maxNumberOfRead)
	{
		user.resize();
	}
	if (user.numberOfRead == 0)
	{
		user.read = new Print[1];
	}
	++user.numberOfRead;
	user.read[user.numberOfRead - 1] = print;
	return user;
}

void User::operator-=(const Book& print) {
	*this - print;
}

User& operator-(User& user, const Periodical& print) {
	bool found = false;
	for (size_t i = 0; i < user.numberOfBorrowed; i++)
	{
		if (user.borrowed[i] == print)
		{
			found = true;
			for (size_t j = i; j < user.numberOfBorrowed - 1; j++)
			{
				user.borrowed[j] = user.borrowed[j + 1];
			}
				--user.numberOfBorrowed;
		}
	}
	if (!found)
	{
		throw "You do not have this print in your borrowed list.";
	}
	if (user.numberOfRead == user.maxNumberOfRead)
	{
		user.resize();
	}
	++user.numberOfRead;
	user.read[user.numberOfRead - 1] = print;
	return user;
}

void User::operator-=(const Periodical& print) {
	*this - print;
}

User& operator-(User& user, const ComicBook& print) {
	bool found = false;
	for (size_t i = 0; i < user.numberOfBorrowed; i++)
	{
		if (user.borrowed[i] == print)
		{
			found = true;
			for (size_t j = i; j < user.numberOfBorrowed - 1; j++)
			{
				user.borrowed[j] = user.borrowed[j + 1];
			}
				--user.numberOfBorrowed;
		}
	}
	if (!found)
	{
		throw "You do not have this print in your borrowed list.";
	}
	if (user.numberOfRead == user.maxNumberOfRead)
	{
		user.resize();
	}
	++user.numberOfRead;
	user.read[user.numberOfRead - 1] = print;
	return user;
}

void User::operator-=(const ComicBook& print) {
	*this - print;
}

void User::display() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Read: " << std::endl;
	for (size_t i = 0; i < numberOfRead; i++)
	{
		std::cout << read[i].getTitle() << std::endl;
	}
	std::cout << "Borrowed: " << std::endl;
	for (size_t i = 0; i < numberOfBorrowed; i++)
	{
		std::cout << borrowed[i].getTitle() << std::endl;
	}
}