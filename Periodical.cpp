#include "Periodical.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

const char* getPeriodString(Period period) {
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

Period Periodical::getPeriod() const {
	return period;
}

size_t Periodical::getVolume() const {
	return volume;
}

void Periodical::setPeriod(const Period period) {
	this->period = period;
}

void Periodical::setVolume(const size_t volume) {
	this->volume = volume;
}

void Periodical::display() const {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Period: " << getPeriodString(period) << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Volume: " << volume << std::endl;
	std::cout << "ID: " << id << std::endl;
	std::cout << "Year: " << year << std::endl;
}

bool operator==(const Periodical& lhs, const Periodical& rhs) {
	return (strcmp(lhs.title, rhs.title) == 0) && (strcmp(lhs.description, rhs.description) == 0) && lhs.id == rhs.id && lhs.year == rhs.year && lhs.period == rhs.period && lhs.volume == rhs.volume;
}

bool operator!=(const Periodical& lhs, const Periodical& rhs) {
	return !(lhs == rhs);
}