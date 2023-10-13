#include "Print.h"
#include "Book.h"
#include "ComicBook.h"
#include "Periodical.h"
#include "User.h"
#include "Library.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

Library::Library(const Library& other) {
	copyFrom(other);
}

Library& Library::operator=(const Library& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Library::~Library() {
	free();
}

void Library::copyFrom(const Library& other) {
	numberOfUsers = other.numberOfUsers;
	maxNumberOfUsers = other.maxNumberOfUsers;
	numberOfPrints = other.numberOfPrints;
	maxNumberOfPrints = other.maxNumberOfPrints;
	User* tempUser = new User[maxNumberOfUsers];
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		tempUser[i] = other.users[i];
	}
	Print* tempPrint = new Print[maxNumberOfPrints];
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		tempPrint[i] = other.prints[i];
	}
}

void Library::free() {
	numberOfUsers = 0;
	maxNumberOfUsers = 1;
	numberOfPrints = 0;
	maxNumberOfPrints = 1;
	delete[] users;
	delete[] prints;
}

void Library::resizeUsers() {
	User* tempUser = new User[2 * maxNumberOfUsers];
	maxNumberOfUsers *= 2;
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		tempUser[i] = users[i];
	}
	users = tempUser;
	tempUser = nullptr;
}

void Library::resizePrints() {
	Print* tempPrint = new Print[2 * maxNumberOfPrints];
	maxNumberOfPrints *= 2;
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		tempPrint[i] = prints[i];
	}
	prints = tempPrint;
	tempPrint = nullptr;
}

Library::Library(Library&& other) noexcept{
	numberOfUsers = other.numberOfUsers;
	maxNumberOfUsers = other.maxNumberOfUsers;
	numberOfPrints = other.numberOfPrints;
	maxNumberOfPrints = other.maxNumberOfPrints;
	users = other.users;
	other.users = nullptr;
	prints = other.prints;
	other.prints = nullptr;
}

Library& Library::operator=(Library&& other) noexcept{
	if (this != &other)
	{
		free();
		numberOfUsers = other.numberOfUsers;
		maxNumberOfUsers = other.maxNumberOfUsers;
		numberOfPrints = other.numberOfPrints;
		maxNumberOfPrints = other.maxNumberOfPrints;
		users = other.users;
		other.users = nullptr;
		prints = other.prints;
		other.prints = nullptr;
	}
	return *this;
}

size_t Library::getNumberOfUsers() const {
	return numberOfUsers;
}

size_t Library::getMaxNumberOfUsers() const {
	return maxNumberOfUsers;
}

size_t Library::getNumberOfPrints() const {
	return numberOfPrints;
}

size_t Library::getMaxNumberOfPrints() const {
	return maxNumberOfPrints;
}

void Library::setNumberOfUsers(const size_t numberOfUsers) {
	this->numberOfUsers = numberOfUsers;
}

void Library::setMaxNumberOfUsers(const size_t maxNumberOfUsers) {
	this->maxNumberOfUsers = maxNumberOfUsers;
}

void Library::setNumberOfPrints(const size_t numberOfPrints) {
	this->numberOfPrints = numberOfPrints;
}

void Library::setMaxNumberOfPrints(const size_t maxNumberOfPrints) {
	this->maxNumberOfPrints = maxNumberOfPrints;
}

void Library::addPrint(const Book& prints) {
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		if (this->prints[i].getId() == prints.getId())
		{
			throw "There is an existing print in this library with that ID, all IDs must be unique.";
		}
	}
	if (numberOfPrints == maxNumberOfPrints)
	{
		resizePrints();
	}
	if (numberOfPrints == 0)
	{
		this->prints = new Print[1];
	}
	++numberOfPrints;
	this->prints[numberOfPrints - 1] = prints;
}

void Library::addPrint(const Periodical& prints) {
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		if (this->prints[i].getId() == prints.getId())
		{
			throw "There is an existing print in this library with that ID, all IDs must be unique.";
		}
	}
	if (numberOfPrints == maxNumberOfPrints)
	{
		resizePrints();
	}
	
	++numberOfPrints;
	this->prints[numberOfPrints - 1] = prints;
}

void Library::addPrint(const ComicBook& prints) {
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		if (this->prints[i].getId() == prints.getId())
		{
			throw "There is an existing print in this library with that ID, all IDs must be unique.";
		}
	}
	if (numberOfPrints == maxNumberOfPrints)
	{
		resizePrints();
	}
	
	++numberOfPrints;
	this->prints[numberOfPrints - 1] = prints;
}

void Library::addUser(const User& users) {
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		if (strcmp(this->users[i].getName(), users.getName()) == 0)
		{
			throw "There is an existing user in this library with that name, all names must be unique.";
		}
	}
	if (numberOfUsers == maxNumberOfUsers)
	{
		resizeUsers();
	}
	if (numberOfUsers == 0)
	{
		this->users = new User[1];
	}
	this->users[numberOfUsers] = users;
	++numberOfUsers;
}

void Library::removePrint(const size_t id) {
	bool found = false;
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		if (prints[i].getId() == id)
		{
			for (size_t j = i; j < numberOfPrints - 1; j++)
			{
				prints[j] = prints[j + 1];
			}
			found = true;
			--numberOfPrints;
		}
	}
	if (!found)
	{
		throw "The print you are trying to remove does not exist in this library.";
	}
}

void Library::removeUser(const char* name) {
	bool found = false;
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		if (strcmp(users[i].getName(), name) == 0)
		{
			for (size_t j = i; j < numberOfUsers - 1; j++)
			{
				users[j] = users[j + 1];
			}
			found = true;
			--numberOfUsers;
		}
	}
	if (!found)
	{
		throw "The user you are trying to remove does not exist in this library.";
	}
}

void Library::sortPrints() {
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		for (size_t j = i + 1; j < numberOfPrints - 1; j++)
		{
			if (prints[i].getYear() > prints[j].getYear())
			{
				Print temp = prints[i];
				prints[i] = prints[j];
				prints[i] = temp;
			}
		}
	}
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		for (size_t j = i + 1; j < numberOfPrints - 1; j++)
		{
			if (strcmp(prints[i].getTitle(), prints[j].getTitle()) >= 0)
			{
				Print temp = prints[i];
				prints[i] = prints[j];
				prints[i] = temp;
			}
		}
	}
}

void Library::sortUsers() {
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		for (size_t j = i + 1; j < numberOfUsers - 1; j++)
		{
			if (users[i].getNumberOfRead() > users[j].getNumberOfRead())
			{
				User temp = users[i];
				users[i] = users[j];
				users[i] = temp;
			}
		}
	}
}

void Library::displayPrints() {
	sortPrints();
	for (size_t i = 0; i < numberOfPrints; i++)
	{
		prints[i].display();
	}
}

void Library::displayUsers() {
	sortUsers();
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		users[i].display();
	}
}

void Library::displayBorrowed(const size_t id) {
	sortUsers();
	for (size_t i = 0; i < numberOfUsers; i++)
	{
		for (size_t j = 0; j < users[i].numberOfBorrowed; j++)
		{
			if (this->users[i].borrowed[j].getId() == id) {
				std::cout << users[i].name << std::endl;
			}
		}
	}
}