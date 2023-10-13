#pragma once
#include "Print.h"
#include "Book.h"
#include "Periodical.h"
#include "ComicBook.h"

enum StateOfBook
{
	READ,
	BORROWED,
	NONE
};

class User {
private:
	char* name = nullptr;
	Print* read = nullptr;
	size_t numberOfRead = 0;
	size_t maxNumberOfRead = 1;
	Print borrowed[5];
	size_t numberOfBorrowed = 0;
public:
	friend class Library;
	User() = default;
	User(size_t numberOfRead);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	User(User&& other) noexcept;
	User& operator=(User&& other) noexcept;

	size_t getNumberOfRead() const;
	size_t getMaxNumberOfRead() const;
	size_t getNumberOfBorrowed() const;
	char* getName() const;
	void setName(const char* name);
	void setNumberOfRead(const size_t numberOfRead);
	void setMaxNumberOfRead(const size_t maxNumberOfRead);
	void setNumberOfBorrowed(const size_t numberOfBorrowed);
	void display() const;

	friend bool operator==(const User& lhs, const User& rhs);
	friend bool operator!=(const User& lhs, const User& rhs);
	friend bool operator>=(const User& lhs, const User& rhs);
	friend bool operator>(const User& lhs, const User& rhs);
	friend bool operator<=(const User & lhs, const User & rhs);
	friend bool operator<(const User& lhs, const User& rhs);
	StateOfBook operator[](const size_t id) const;
	friend User& operator+(User& user, const Print& print);
	void operator+=(const Print& print);
	friend User& operator-(User& user, const Print& print);
	void operator-=(const Print& print);

	friend User& operator+(User& user, const Book& print);
	void operator+=(const Book& print);
	friend User& operator-(User& user, const Book& print);
	void operator-=(const Book& print);

	friend User& operator+(User& user, const Periodical& print);
	void operator+=(const Periodical& print);
	friend User& operator-(User& user, const Periodical& print);
	void operator-=(const Periodical& print);

	friend User& operator+(User& user, const ComicBook& print);
	void operator+=(const ComicBook& print);
	friend User& operator-(User& user, const ComicBook& print);
	void operator-=(const ComicBook& print);

private:
	void copyFrom(const User& other);
	void free();
	void freeNull();
	void resize();
};