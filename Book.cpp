#include "Book.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

Book::Book() {
	setAuthorName("Name");
	setPublisher("Publisher");
}

Book::Book(const Book& other) : Print(other){
	copyFrom(other);
}

Book& Book::operator=(const Book& other) {
	if (this != &other) 
	{
		Print::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Book::~Book() {
	free();
}

void copyStringBook(char* &lhs, const char*  rhs) {
	lhs = new char[strlen(rhs) + 1];
	strcpy(lhs, rhs);
}

void movePointerBook(char* lhs, char* rhs) {
	lhs = rhs;
	rhs = nullptr;
}

void Book::copyFrom(const Book& other) {
	copyStringBook(authorName, other.authorName);
	copyStringBook(publisher, other.publisher);
	genre = other.genre;
}

void Book::free() {
	delete[] authorName;
	delete[] publisher;
	genre = 0;
}

Book::Book(Book&& other) noexcept : Print(std::move(other)) {
	movePointerBook(authorName, other.authorName);
	movePointerBook(publisher, other.publisher);
	genre = other.genre;
}

Book& Book::operator=(Book&& other) noexcept {
	if (this != &other)
	{
		Print::operator=(std::move(other));
		free();
		movePointerBook(authorName, other.authorName);
		movePointerBook(publisher, other.publisher);
		genre = other.genre;
	}
	return *this;
}

char* Book::getAuthorName() const {
	return authorName;
}

char* Book::getPublisher() const {
	return publisher;
}

Genre Book::getGenre() const {
	return genre;
}

void Book::setAuthorName(const char* authorName) {
	if (authorName == nullptr)
	{
		throw "You need to set an author name.";
	}
	copyStringBook(this->authorName, authorName);
}

void Book::setPublisher(const char* publisher) {
	copyStringBook(this->publisher, publisher);
}

void Book::setGenre(const Genre& genre) {
	this->genre = genre;
}

void Book::setCharacteristic(Characteristic characteristic) {
	this->genre.setCharacteristic(characteristic);
}

void Book::setType(Type type) {
	this->genre.setType(type);
}

void Book::setTargetAudience(TargetAudience audience) {
	this->genre.setTargetAudience(audience);
}

void Book::display() const {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << authorName  << std::endl;
	std::cout << "Publisher: " << publisher  << std::endl;
	genre.display();
	std::cout << "Description: " << description << std::endl;
	std::cout << "ID: " << id << std::endl;
	std::cout << "Year: " << year << std::endl;
}

bool operator==(const Book& lhs, const Book& rhs) {
	return (strcmp(lhs.title, rhs.title) == 0) && (strcmp(lhs.description, rhs.description) == 0) && lhs.id == rhs.id && lhs.year == rhs.year && (strcmp(lhs.authorName, rhs.authorName) == 0) && (strcmp(lhs.publisher, rhs.publisher) == 0) && lhs.genre == rhs.genre;
}

bool operator!=(const Book& lhs, const Book& rhs) {
	return !(lhs == rhs);
}