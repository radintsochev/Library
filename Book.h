#pragma once
#include "Genre.h"
#include "Print.h"

class Book : virtual public Print{
protected:
	char* authorName = nullptr;
	char* publisher = nullptr;
	Genre genre = 0;
public:
	Book();
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	Book(Book&& other) noexcept;
	Book& operator=(Book&& other) noexcept;

	char* getAuthorName() const;
	char* getPublisher() const;
	Genre getGenre() const;

	void setAuthorName(const char* authorName);
	void setPublisher(const char* publisher);
	void setGenre(const Genre& genre);
	void setCharacteristic(Characteristic characteristic);
	void setType(Type type);
	void setTargetAudience(TargetAudience audience);
	void display() const;

	friend bool operator==(const Book& lhs, const Book& rhs);
	friend bool operator!=(const Book& lhs, const Book& rhs);

private:
	void copyFrom(const Book& other);
	void free();
};