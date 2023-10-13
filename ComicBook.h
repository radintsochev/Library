#pragma once
#include "Book.h"
#include "Periodical.h"
#include "Print.h"

class ComicBook : virtual public Print, public Periodical,  public Book  {
public:
	void display() const;
	friend bool operator==(const ComicBook& lhs, const ComicBook& rhs);
	friend bool operator!=(const ComicBook& lhs, const ComicBook& rhs);

};
