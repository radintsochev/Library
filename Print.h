#pragma once

class Print {
protected:
	char* title = nullptr;
	char* description = nullptr;
	size_t id = 0;
	size_t year = 0;
public:
	Print();
	Print(const Print& other);
	Print& operator=(const Print& other);
	virtual ~Print();

	Print(Print&& other) noexcept;
	Print& operator=(Print&& other) noexcept;

	char* getTitle() const;
	char* getDescription() const;
	size_t getId() const;
	size_t getYear() const;

	void display() const;

	void setTitle(const char* title);
	void setDescription(const char* description);
	void setId(const size_t id);
	void setYear(const size_t year);

	friend bool operator==(const Print& lhs, const Print& rhs);
	friend bool operator!=(const Print& lhs, const Print& rhs);

private:
	void copyFrom(const Print& other);
	virtual void free();
};