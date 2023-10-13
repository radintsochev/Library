#pragma once
#include "Book.h"

enum Period {
	WEEKLY,
	MONTHLY,
	YEARLY
};

class Periodical : virtual public Print {
protected:
	Period period = (Period)0;
	size_t volume = 0;
public:
	Periodical() = default;
	~Periodical() = default;

	Period getPeriod() const;
	size_t getVolume() const;

	void setPeriod(const Period period);
	void setVolume(const size_t volume);

	void display() const;
	friend bool operator==(const Periodical& lhs, const Periodical& rhs);
	friend bool operator!=(const Periodical& lhs, const Periodical& rhs);
};