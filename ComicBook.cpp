#include "Genre.h"
#include "ComicBook.h"
#include <iostream>

const char* getPeriodStringCB(Period period) {
	const char* periodStrings[] = {
	"Weekly",
	"Monthly",
	"Yearly"
	};
	int index = (int)period;
	if (index >= 0 && index < 3) {
		return periodStrings[index];
	}
	return "Unknown";
}

void ComicBook::display() const {
	std::cout << "Title: " << Print::title << std::endl;
	std::cout << "Period: " << getPeriodStringCB(Periodical::period) << std::endl;
	std::cout << "Author: " << Book::authorName << std::endl;
	std::cout << "Publisher: " << Book::publisher << std::endl;
	Book::genre.display();
	std::cout << "Description: " << Print::description << std::endl;
	std::cout << "Volume: " << Periodical::volume << std::endl;
	std::cout << "ID: " << Print::id << std::endl;
	std::cout << "Year: " << Print::year << std::endl;
}

bool operator==(const ComicBook& lhs, const ComicBook& rhs) {
	return (strcmp(lhs.Print::title, rhs.Print::title) == 0) && (strcmp(lhs.Print::description, rhs.Print::description) == 0) && lhs.Print::id == rhs.Print::id && lhs.Print::year == rhs.Print::year && (strcmp(lhs.authorName, rhs.authorName) == 0) && (strcmp(lhs.publisher, rhs.publisher) == 0) && lhs.genre == rhs.genre && lhs.period == rhs.period && lhs.volume == rhs.volume;
}

bool operator!=(const ComicBook& lhs, const ComicBook& rhs) {
	return !(lhs == rhs);
}