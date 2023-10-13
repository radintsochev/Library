#include "Print.h"
#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

Print::Print() {
	setTitle("Title");
	setDescription("Description");

}

Print::Print(const Print& other) {
	copyFrom(other);
}

Print& Print::operator=(const Print& other) {
	 if (this != &other)
	 {
		free();
		copyFrom(other);
	 }
	return *this;
}

Print::~Print() {
	free();
}

void copyString(char* &lhs, const char* rhs) {
	lhs = new char[strlen(rhs) + 1];
	strcpy(lhs, rhs);
}

void movePointer(char* lhs, char* rhs) {
	lhs = rhs;
	rhs = nullptr;
}

void Print::copyFrom(const Print& other) {
	copyString(title, other.title);
	copyString(description, other.description);
	id = other.id;
	year = other.year;
}

void Print::free() {
	delete[] title;
	delete[] description;
	id = 0;
	year = 0;
}

Print::Print(Print&& other) noexcept {
	movePointer(title, other.title);
	movePointer(description, other.description);
	id = other.id;
	year = other.year;
}

Print& Print::operator=(Print&& other) noexcept {
	if (this != &other)
	{
		free();
		movePointer(title, other.title);
		movePointer(description, other.description);
		id = other.id;
		year = other.year;
	}
	return *this;
}

char* Print::getTitle() const {
	return title;
}

char* Print::getDescription() const {
	return description;
}

size_t Print::getId() const {
	return id;
}

size_t Print::getYear() const {
	return year;
}

void Print::setTitle(const char* title) {
	copyString(this->title, title);
}

void Print::setDescription(const char* description) {
	copyString(this->description, description);
}

void Print::setId(const size_t id) {

	this->id = id;
}

void Print::setYear(const size_t year) {
	this->year = year;
}

bool operator==(const Print& lhs, const Print& rhs)
{
	return (strcmp(lhs.title, rhs.title) == 0) && (strcmp(lhs.description, rhs.description) == 0) && lhs.id == rhs.id && lhs.year == rhs.year;
}

bool operator!=(const Print& lhs, const Print& rhs) {
	return !(lhs == rhs);
}

void Print::display() const {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "ID: " << id << std::endl;
}
